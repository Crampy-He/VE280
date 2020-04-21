//
// Created by crampy on 2019/7/18.
//
#include "square.h"
Square::Square(Vaxis v, Haxis h):v(v), h(h){

}
Vaxis Square::getV() const {
    return v;
}
void Square::setV(Vaxis v) {
    this->v=v;
}
Haxis Square::getH() const {
    return h;
}
void Square::setH(Haxis h) {
    this->h=h;
}
const Piece& Square::getPiece() const {
     if(isEmpty()){
         throw *this->p;
     }
    return *this->p;
}
void Square::setPiece(const Piece *p) {
     this->p=p;
}
bool Square::isEmpty() const {
    return  this->p== nullptr;
}
bool Square::isOnFirstDiagonal() const {
    if((v==A&&h==H1)||(v==B&&h==H2)||(v==C&&h==H3)||(v==D&&h==H4)){
        return true;
    }else{
        return false;
    }
}
bool Square::isOnSecondDiagonal() const {
    if((v==A&&h==H4)||(v==B&&h==H3)||(v==C&&h==H2)||(v==D&&h==H1)){
        return true;
    }else{
        return false;
    }
}

std::string Square::toString() const {
    std::string square_code;
    char Vaxis_rep[4]={'A','B','C','D'};
    char Haxis_rep[4]={'1','2','3','4'};
    square_code+=Vaxis_rep[getV()];
    square_code+=Haxis_rep[getH()];
    return square_code;
}
