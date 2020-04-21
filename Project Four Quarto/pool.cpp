//
// Created by crampy on 2019/7/16.
//
#include <iostream>
#include "pool.h"
Pool::Pool() {
    pieces[0]=Piece(SHORT,BEIGE,CIRCLE,HOLLOW);
    pieces[1]=Piece(SHORT,BEIGE,CIRCLE,SOLID);
    pieces[2]=Piece(SHORT,BEIGE,SQUARE,HOLLOW);
    pieces[3]=Piece(SHORT,BEIGE,SQUARE,SOLID);
    pieces[4]=Piece(SHORT,SEPIA,CIRCLE,HOLLOW);
    pieces[5]=Piece(SHORT,SEPIA,CIRCLE,SOLID);
    pieces[6]=Piece(SHORT,SEPIA,SQUARE,HOLLOW);
    pieces[7]=Piece(SHORT,SEPIA,SQUARE,SOLID);
    pieces[8]=Piece(TALL,BEIGE,CIRCLE,HOLLOW);
    pieces[9]=Piece(TALL,BEIGE,CIRCLE,SOLID);
    pieces[10]=Piece(TALL,BEIGE,SQUARE,HOLLOW);
    pieces[11]=Piece(TALL,BEIGE,SQUARE,SOLID);
    pieces[12]=Piece(TALL,SEPIA,CIRCLE,HOLLOW);
    pieces[13]=Piece(TALL,SEPIA,CIRCLE,SOLID);
    pieces[14]=Piece(TALL,SEPIA,SQUARE,HOLLOW);
    pieces[15]=Piece(TALL,SEPIA,SQUARE,SOLID);

}
Piece& Pool::getUnusedPiece(int index) {
     if (pieces[index].isUsed()){
         throw UsedPieceException(this->pieces[index]);
     }
        return pieces[index];
    }

Piece & Pool::getUnusedPiece(Height h, Color c, Shape s, Top t){
    int i,piece_number=0;
    Piece p_temp(h,c,s,t);
    for(i=0;i<16;i++){
        if(pieces[i].compareHeight(p_temp)&&pieces[i].compareTop(p_temp)&&pieces[i].compareShape(p_temp)&&pieces[i].compareColor(p_temp)){
            piece_number=i;
            break;
        }
    }
    if (pieces[piece_number].isUsed()){
        throw UsedPieceException(this->pieces[piece_number]);
    }
    return pieces[piece_number];
}
  /*  if (pieces[piece_number].isUsed()){
        throw pieces[piece_number];
    }
    return pieces[piece_number];
*/


std::string Pool::toString() const{
    std::string pool_string;
    pool_string="Available:\n";
    int i=0,first_element_inline=0;
    for(i=0;i<=15;i++){
        if(!(pieces[i].isUsed())){
            if(i==0||first_element_inline==0){
                pool_string+=pieces[i].toString().substr(0,2);
                first_element_inline++;
            }else if(i<=15&&first_element_inline!=0){
                pool_string+=" "+pieces[i].toString().substr(0,2);
            }
        }
    }
    pool_string+="\n";
      first_element_inline=0;
    for(i=0;i<=15;i++){
        if(!(pieces[i].isUsed())){
            if(i==0||first_element_inline==0){
                pool_string+=pieces[i].toString().substr(2,2);
                first_element_inline++;
            }else if(i<=15&&first_element_inline!=0){
                pool_string+=" "+pieces[i].toString().substr(2,2);
            }
        }
    }
    pool_string+="\n";
      if(first_element_inline==0){
          return "\n";
      }
    return pool_string;
}
Piece& Pool::getUnusedPiece(const std::string &in) {
    int i=0,piece_number=0;
    for(i=0;i<=15;i++){
        if(pieces[i].toString()==in){
            piece_number=i;
            break;
        }
    }
    if (pieces[piece_number].isUsed()){
        throw UsedPieceException(this->pieces[piece_number]);
    }
    return pieces[piece_number];
/*    if (pieces[piece_number].isUsed()){
        throw pieces[piece_number];
    }
    return pieces[piece_number];
*/
 }
