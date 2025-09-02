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

void ShapeMaker::drawHorizontal(){
    int mid = height / 2;
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            if (row == mid)
                cout << symbol;
            else
                cout << " ";

        }
        cout << endl;
    }
}

void ShapeMaker::drawVertical(){
    int mid = width / 2;
    for(int row = 0; row < width; row++){
        for(int col = 0; col < width; col++){
            if (row == mid)
                cout << symbol;
            else
                cout << " ";
        }
        cout << endl;
    }
}


