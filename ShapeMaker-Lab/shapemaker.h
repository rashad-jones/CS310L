#ifndef SHAPEMAKER_H
#define SHAPEMAKER_H

class ShapeMaker{

    private: 
        int width;
        int height;
        char symbol;

    
    public:
    
    //constructor
    ShapeMaker();
    ShapeMaker(int w, int h, char s);

    //get
    int getWidth();
    int getHeight();
    char getSymbol();

    //set
    void setWidth(int w);
    void setHeight(int h);
    void setSymbol(int char);

    //draw
    void drawHorizontal();
    void drawVertical();
    void drawSquareOpen();
    void drawSquareFilled();
    void drawSmiley();


}