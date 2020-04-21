//
// Created by crampy on 2019/7/16.
//

# include "piece.h"
Piece::Piece(Height h, Color c, Shape s, Top t):h(h), c(c), s(s),t(t),used(false){
}
bool Piece::compareColor(const Piece &p) const {
    return this->c==p.c;
}
bool Piece::compareHeight(const Piece &p) const {
    return this->h==p.h;
}
bool Piece::compareShape(const Piece &p) const {
    return this->s==p.s;
}
bool Piece::compareTop(const Piece &p) const {
    return this->t==p.t;
}
bool Piece::isUsed() const {
    return this->used;
}
void Piece::setUsed(bool u) {
    this->used= u;
}
std::string Piece::toString() const {
    std::string  code=std::string();
    code+=HCODE[this->h];
    code+=CCODE[this->c];
    code+=SCODE[this->s];
    code+=TCODE[this->t];
    return code;
}
