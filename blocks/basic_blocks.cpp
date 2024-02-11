#include<simplecpp>
#include<vector>
#include "blocks.h"


Point::Point(int a, int b) : x(a), y(b) {}
Point::Point (){}



Block::Block(){}
Block::Block(int a, int b, int c, int d, const char color[15] = "white") : x(a), y(b) {
    
    elementBorder = Rectangle(a,b,c,d);
    element = Rectangle(a,b,c-2,d-2);
    element.setFill(true);
    elementBorder.setColor(COLOR("black"));
    element.setColor(COLOR(color));
}

int Block::getX(){
    return x;
}
int Block::getY(){
    return y;
}
Point Block::getCenter(){
    return Point(x,y);
}


void Block::move(int a, int b){
    element.move(a,b);
    elementBorder.move(a,b);
    x += a;
    y += b;
}


Orientation::Orientation(){ 
    curr_orient = 0;
}

void Orientation::change_orient(int input){
    // +1 input is clockwise rotate
    // -1 is anticlockwise rotate

    switch(input){
        case 1:
            if(curr_orient!=3) curr_orient++;
            else curr_orient = 0;
            break;
        case -1:
            if(curr_orient!=0) curr_orient--;
            else curr_orient = 3;
            break;
    }
}
    