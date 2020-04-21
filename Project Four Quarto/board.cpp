//
// Created by crampy on 2019/7/18.
//
#include "board.h"
#include <iostream>
Board::Board() {
    Vaxis  vaxis_value[4]={A, B, C, D};
    Haxis  haxis_value[4]{H1, H2, H3, H4};
    int i=0,j=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            grid[i][j].setV(vaxis_value[i]);
            grid[i][j].setH(haxis_value[j]);
            grid[i][j].setPiece(nullptr);
        }
    }
}
Square& Board::getSquare(Vaxis v, Haxis h) {
    int i=0,j=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
           if(grid[i][j].getH()==h&&grid[i][j].getV()==v){
               return grid[i][j];
        }
    }
}
    return grid[0][0];
}
Square& Board::getEmptySquare(Vaxis v, Haxis h) {
    int i=0,j=0,square_num_i=0,square_num_j=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(grid[i][j].getH()==h&&grid[i][j].getV()==v){
                square_num_i=i;
                square_num_j=j;
                break;
            }
        }
    }
    if(!(grid[square_num_i][square_num_j].isEmpty())){
        throw grid[square_num_i][square_num_j];
    }
    return grid[square_num_i][square_num_j];
}
Square& Board::getEmptySquare(const std::string &s) {
    char Vaxis_rep[4]={'A','B','C','D'};
    char Haxis_rep[4]={'1','2','3','4'};
    char s_char[2];
    s_char[0]=s[0];
    s_char[1]=s[1];
    int i=0,j=0,square_num_i=0,square_num_j=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(Vaxis_rep[grid[i][j].getV()]==s_char[0]&&Haxis_rep[grid[i][j].getH()]==s_char[1]){
                square_num_i=i;
                square_num_j=j;
                break;
            }
        }
    }
    if(!(grid[square_num_i][square_num_j].isEmpty())){
        throw grid[square_num_i][square_num_j];
    }
    return grid[square_num_i][square_num_j];
}

bool compare_four_pieces(const Piece &piece1, const Piece &piece2, const Piece &piece3, const Piece &piece4) {
    if(piece1.compareColor(piece2)&&piece2.compareColor(piece3)&&piece3.compareColor(piece4)){
        return true;
    }
    if(piece1.compareShape(piece2)&&piece2.compareShape(piece3)&&piece3.compareShape(piece4)){
        return true;
    }
    if(piece1.compareHeight(piece2)&&piece2.compareHeight(piece3)&&piece3.compareHeight(piece4)){
        return true;
    }
    if(piece1.compareTop(piece2)&&piece2.compareTop(piece3)&&piece3.compareTop(piece4)){
        return true;
    }
    return  false;
}
void Board::place(Piece &p, Square &sq) {
    sq.setPiece(&p);
    p.setUsed(true);
}

bool Board::isWinning(const Piece &p, const Square &sq) {
   int sq_vaxis=0,sq_haxis=0,i,j;
    bool compare[4]={false,false,false,false},result=false;
    Square square_same_Vaix[3],square_same_Haix[3], square_same_Dia_1[3],square_same_Dia_2[3];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(grid[i][j].getV()==sq.getV()&&grid[i][j].getH()==sq.getH()){
                sq_vaxis=i;
                sq_haxis=j;
                break;
            }
        }
    }
    j=0;
    for(i=0;i<3;i++){
        square_same_Vaix[i].setPiece(nullptr);
        square_same_Haix[i].setPiece(nullptr);
        square_same_Dia_1[i].setPiece(nullptr);
        square_same_Dia_2[i].setPiece(nullptr);
    }
    for(i=0;i<4;i++) {
        if (i != sq_vaxis) {
            if (!(grid[i][sq_haxis].isEmpty())) {
                square_same_Haix[j].setPiece(&grid[i][sq_haxis].getPiece());
                j++;
            }
        }
    }

        j = 0;
        for (i = 0; i < 4; i++) {
            if (i != sq_haxis) {
                if (!(grid[sq_vaxis][i].isEmpty())) {
                    square_same_Vaix[j].setPiece(&grid[sq_vaxis][i].getPiece());
                    j++;
                }
            }
        }

        if (!square_same_Vaix[2].isEmpty()) {
            compare[0] = compare_four_pieces(p, square_same_Vaix[0].getPiece(), square_same_Vaix[1].getPiece(),
                                             square_same_Vaix[2].getPiece());
        }
        if (!square_same_Haix[2].isEmpty()) {
            compare[1] = compare_four_pieces(p, square_same_Haix[0].getPiece(), square_same_Haix[1].getPiece(),
                                             square_same_Haix[2].getPiece());;
        }
        result = compare[0] || compare[1];
        if (sq.isOnFirstDiagonal()) {
            j = 0;
            for (i = 0; i < 4; i++) {
                if (i != sq_haxis) {
                    if (!grid[i][i].isEmpty()) {
                        square_same_Dia_1[j].setPiece(&grid[i][i].getPiece());
                        j++;
                    }
                }
            }
            if (j == 3) {
                compare[2] = compare_four_pieces(p, square_same_Dia_1[0].getPiece(), square_same_Dia_1[1].getPiece(),
                                                 square_same_Dia_1[2].getPiece());
            }
            result = compare[0] || compare[1] || compare[2];
        }

    if(sq.isOnSecondDiagonal()){
        j=0;
        for(i=0;i<4;i++) {
            if (i!= sq_haxis) {
                if(!grid[3-i][i].isEmpty()){
                square_same_Dia_2[j].setPiece(&grid[3-i][i].getPiece());
                j++;
            }
            }
        }if(j==3) {
            compare[3] = compare_four_pieces(p, square_same_Dia_2[0].getPiece(), square_same_Dia_2[1].getPiece(),
                                             square_same_Dia_2[2].getPiece());
        }
            result=compare[0]||compare[1]||compare[3];
    }

    return  result;
}
std::string Board::toString() const {
    std::string board_string;
    int i, j;
    board_string = "    1    2    3    4\n";
    for (i = 0; i < 4; i++) {
        board_string += "  +----+----+----+----+\n";
        if (i == 0) {
            board_string += "a ";
        }
        if (i == 1) {
            board_string += "b ";
        }
        if (i == 2) {
            board_string += "c ";
        }
        if (i == 3) {
            board_string += "d ";
        }
        for (j = 0; j < 4; j++) {
            if (grid[i][j].isEmpty()) {
                board_string += "|    ";
            } else {
                board_string += "| " + grid[i][j].getPiece().toString().substr(0, 2) + " ";
            }
        }
        board_string += "|\n";
        board_string += "  ";
        for (j = 0; j < 4; j++) {
            if (grid[i][j].isEmpty()) {
                board_string += "|    ";
            } else {
                board_string += "| " + grid[i][j].getPiece().toString().substr(2, 2) + " ";
            }
        }
        board_string += "|\n";
    }
    board_string += "  +----+----+----+----+\n";
    return board_string;
}