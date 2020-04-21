//
// Created by crampy on 2019/7/18.
//
#include <iostream>
#include <string>
#include "player.h"
#include "quarto.h"
using namespace std;
bool string_detect(string s){
    return (s=="SBCH")||(s=="SBCO")||(s=="SBQH")||(s=="SBQO")||(s=="SECH")||(s=="SECO")||(s=="SEQH")||(s=="SEQO")
            ||(s=="TBCH")||(s=="TBCO")||(s=="TBQH")||(s=="TBQO")||(s=="TECH")||(s=="TECO")||(s=="TEQH")||(s=="TEQO");
}
bool string_detect_2(string s){
    return (s=="A1")||(s=="A2")||(s=="A3")||(s=="A4")||(s=="B1")||(s=="B2")||(s=="B3")||(s=="B4")
            ||(s=="C1")||(s=="C2")||(s=="C3")||(s=="C4")||(s=="D1")||(s=="D2")||(s=="D3")||(s=="D4");
}
class HumanPlayer: public Player{
public:
    HumanPlayer(Board *board, Pool *pool): Player(board, pool){}
    Piece & selectPiece() override ;
    Square & selectSquare(const Piece &p)override;
};
class MyopicPlayer: public Player{
public:
    MyopicPlayer(Board *board,Pool *pool, unsigned int seed=0):Player(board, pool){}
    Piece & selectPiece() override ;
    Square & selectSquare(const Piece &p)override;
};

Piece& HumanPlayer::selectPiece() {
    bool valid_input = false;
    string input;
    string str ;
    bool input_invalid, input_used;
    while (!valid_input) {
        input_invalid = false;
        input_used = false;
        cout << "Enter a piece:"<<flush ;
        cin >> input;
        try {
            if (!string_detect(input)) {
                throw InvalidInputException(input);
            }
        } catch (InvalidInputException &ia) {
            cout << ia.what() << endl;
            input_invalid = true;
        }
        if (!input_invalid) {
            try {
                str=input;
                pool->getUnusedPiece(str);
            } catch (UsedPieceException &up) {
                cout << up.what() << endl;
                input_used= true;
            }
        }if((!input_invalid)&&(!input_used)){
            valid_input= true;
        }
    }
    return  pool->getUnusedPiece(str);
}
    Square& HumanPlayer::selectSquare(const Piece &p)  {
        bool valid_input=false;
        bool input_invalid, input_nonempty;
        string input;
        string str;
        string m="not empty";
        while(!valid_input){
            input_invalid= false, input_nonempty= false;
            cout<<"Enter a position:"<<flush;
            cin>>input;
            if(!string_detect_2(input)){
                cout<<input<<" is an invalid input."<<endl;
                input_invalid= true;
            }else{
                str=input;
                try {
                    board->getEmptySquare(str);
                }catch(Square &sq){
                    input_nonempty=true;
                    SquareException non_empty_sq(sq,m);
                    cout<<non_empty_sq.what()<<endl;
                }
            }
            if((!input_invalid)&&(!input_nonempty)){
                valid_input= true;
            }
        }
        return    board->getEmptySquare(str);
    }
Piece& MyopicPlayer::selectPiece() {
    Piece all_piece[16], unused_piece[17], bad_piece[17], good_piece[17];
    int unused_piece_num = 0, empty_square_num = 0,bad_piece_num=0,good_piece_num=0, i, j,return_index;
    Square all_square[4][4], empty_square[17];
    string m=string();
    bool is_used,is_empty,piece_is_good;
    all_piece[0] = Piece(SHORT, BEIGE, CIRCLE, HOLLOW);
    all_piece[1] = Piece(SHORT, BEIGE, CIRCLE, SOLID);
    all_piece[2] = Piece(SHORT, BEIGE, SQUARE, HOLLOW);
    all_piece[3] = Piece(SHORT, BEIGE, SQUARE, SOLID);
    all_piece[4] = Piece(SHORT, SEPIA, CIRCLE, HOLLOW);
    all_piece[5] = Piece(SHORT, SEPIA, CIRCLE, SOLID);
    all_piece[6] = Piece(SHORT, SEPIA, SQUARE, HOLLOW);
    all_piece[7] = Piece(SHORT, SEPIA, SQUARE, SOLID);
    all_piece[8] = Piece(TALL, BEIGE, CIRCLE, HOLLOW);
    all_piece[9] = Piece(TALL, BEIGE, CIRCLE, SOLID);
    all_piece[10] = Piece(TALL, BEIGE, SQUARE, HOLLOW);
    all_piece[11] = Piece(TALL, BEIGE, SQUARE, SOLID);
    all_piece[12] = Piece(TALL, SEPIA, CIRCLE, HOLLOW);
    all_piece[13] = Piece(TALL, SEPIA, CIRCLE, SOLID);
    all_piece[14] = Piece(TALL, SEPIA, SQUARE, HOLLOW);
    all_piece[15] = Piece(TALL, SEPIA, SQUARE, SOLID);
    for (i = 0; i < 16; i++) {
        is_used = false;
        try {
            pool->getUnusedPiece(all_piece[i].toString());
        } catch (UsedPieceException &up2) {
            is_used = true;
        }
        if (!is_used) {
            unused_piece[unused_piece_num] =all_piece[i];
            unused_piece_num++;
        }
    }
    unused_piece_num--;
    Vaxis vaxis_value[4] = {A, B, C, D};
    Haxis haxis_value[4]{H1, H2, H3, H4};
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            all_square[i][j].setV(vaxis_value[i]);
            all_square[i][j].setH(haxis_value[j]);
            all_square[i][j].setPiece(nullptr);
        }
    }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                is_empty=true;
                try{
                board->getEmptySquare(all_square[i][j].toString());
            }catch (Square &sq){
                    SquareException non_empty_sq(sq,m);
                    is_empty= false;
                }
                if(is_empty){
                    empty_square[empty_square_num]=all_square[i][j];
                    empty_square_num++;
                }
            }
        }
    empty_square_num--;

    for (i = 0; i <=unused_piece_num; i++) {
        piece_is_good=true;
        for (j = 0; j <= empty_square_num; j++) {
                if(board->isWinning(unused_piece[i], empty_square[j])) {
                    piece_is_good = false;
                }
        }
        if(piece_is_good){
            good_piece[good_piece_num]=unused_piece[i];
            good_piece_num++;
        }if(!piece_is_good){
            bad_piece[bad_piece_num]=unused_piece[i];
            bad_piece_num++;
        }
    }
 // cout<<bad_piece_num<<endl;cout<<good_piece_num<<endl;
    if(good_piece_num==0){
        return_index=rand()%(unused_piece_num+1);
        return pool->getUnusedPiece(bad_piece[return_index].toString());
    }else{
        return_index=rand()%(good_piece_num);
        return pool->getUnusedPiece(good_piece[return_index].toString());

    }
}
Square& MyopicPlayer::selectSquare(const Piece &p) {
    Square all_square[4][4], empty_square[17];
    int  empty_square_num = 0,i,j,return_index=0;
    bool is_empty,square_detect=false;
    string m=string();
    Vaxis vaxis_value[4] = {A, B, C, D};
    Haxis haxis_value[4]{H1, H2, H3, H4};
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            all_square[i][j].setV(vaxis_value[i]);
            all_square[i][j].setH(haxis_value[j]);
            all_square[i][j].setPiece(nullptr);
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            is_empty=true;
            try{
                board->getEmptySquare(all_square[i][j].toString());
            }catch (Square sq){
                SquareException non_empty_sq(sq,m);
                is_empty= false;
            }
            if(is_empty){
                empty_square[empty_square_num]=all_square[i][j];
                empty_square_num++;
            }
        }
    }

    for(i=0;i<empty_square_num;i++){
        square_detect=false;
            if(board->isWinning(p,empty_square[i])){
                square_detect=true;
                return_index=i;
                break;
            }
    }
    if(square_detect){
        return board->getEmptySquare(empty_square[return_index].toString());
    }else{
        return_index=rand()%empty_square_num;
        return board->getEmptySquare(empty_square[return_index].toString());
    }
}
extern Player *getHumanPlayer(Board *b, Pool *p){
    static HumanPlayer  hp(b,p);
    return &hp;
}

extern Player *getMyopicPlayer(Board *b, Pool *p, unsigned int s){
    srand(s);
    static MyopicPlayer opicplayer(b,p);
    return &opicplayer;
}