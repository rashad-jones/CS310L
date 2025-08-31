#include <iostream>
#include "shapemaker.h"

//OG constructor 
ShapeMaker::ShapeMaker(){
    width = 21;
    height = 21;
    symbol = '*';
}

//contructore to acces private
ShapeMaker::ShapeMaker(int w, int h, char s){
    width = w;
    height = h;
    symbol = s;
}

//get 
int ShapeMaker::getWidth(){
    return width;
}

int ShapeMaker::getHeight(){
    return height;
}

char ShapeMaker::getSymbol(){
    return symbol;
}

//set
void ShapeMaker::setWidth(int w){
    width = w;
}

void ShapeMaker::setHeight(int h){
    height = h;
}

void ShapeMaker::setSymbol(chat s){
    symbol = s
}

//draw functions



