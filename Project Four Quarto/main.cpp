#include <iostream>
#include"pool.h"
#include "board.h"
#include "player.h"
using namespace std;
int main(int argc, char* argv[]) {
    Board quarto_board;
    Pool quarto_pool;
   unsigned int seed=0,times=0;

    if(argv[3]) {
        seed = (unsigned) atoi(argv[3]);
    }
    string temp1,temp2;
    temp1=argv[1];
    temp2=argv[2];
    Player * player1=getHumanPlayer(&quarto_board,&quarto_pool);
    Player * player2=getMyopicPlayer(&quarto_board,&quarto_pool,seed);
    Player *pl[2];
    pl[0]= nullptr;
    pl[1]= nullptr;
    bool won=false;
    if(temp1=="h"){
     pl[0]=player1;
    }else{
        pl[0]=player2;
    }
    if(temp2=="h"){
        pl[1]=player1;
    }else{
        pl[1]=player2;
    }
    cout<<quarto_board.toString()<<endl;
    cout<<quarto_pool.toString()<<endl;
           while(!won){
                cout<<"Player 1's turn to select a piece:"<<endl;
                Piece &temp_piece=pl[0]->selectPiece();
                cout<<temp_piece.toString()<<" selected.\n"<<endl;
                cout<<"Player 2's turn tos elect a square:"<<endl;
                Square &temp_square=pl[1]->selectSquare(temp_piece);
                cout<<temp_square.toString()<<" selected.\n"<<endl;
                won=quarto_board.isWinning(temp_piece,temp_square);
                if(won){
                    quarto_board.place(temp_piece,temp_square);
                    cout<<quarto_board.toString()<<endl;
                    cout<<quarto_pool.toString()<<endl;
                    cout<<"Player 2 has won!"<<endl;
                    break;
                }
                quarto_board.place(temp_piece,temp_square);
                cout<<quarto_board.toString()<<endl;
                cout<<quarto_pool.toString()<<endl;
                cout<<"Player 2's turn to select a piece:"<<endl;
                Piece &temp_piece_2=pl[1]->selectPiece();
                cout<<temp_piece_2.toString()<<" selected.\n"<<endl;
                cout<<"Player 1's turn to select a square:"<<endl;
                Square &temp_square_2=pl[0]->selectSquare(temp_piece_2);
                cout<<temp_square_2.toString()<<" selected.\n"<<endl;
                won=quarto_board.isWinning(temp_piece_2,temp_square_2);
                if(won){
                    quarto_board.place(temp_piece_2,temp_square_2);
                    cout<<quarto_board.toString()<<endl;
                    cout<<quarto_pool.toString()<<endl;
                    cout<<"Player 1 has won!"<<endl;
                    break;
                }
               quarto_board.place(temp_piece_2, temp_square_2);
               cout << quarto_board.toString() << endl;
               cout << quarto_pool.toString() << endl;
               times++;
               if(times==8){
                   cout<<"It is a draw.\n"<<endl;
                   return  0;
               }
            }
    return 0;
        }





