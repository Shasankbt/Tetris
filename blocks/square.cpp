#include<iostream>
#include "blocks.h"

    Square::Square(){
        center = Point(275, 75);
        part[0] = Block(center.x - 25, center.y - 25, 50, 50, "red");
        part[1] = Block(center.x + 25, center.y - 25, 50, 50, "red");
        part[2] = Block(center.x - 25, center.y + 25, 50, 50, "red");
        part[3] = Block(center.x + 25, center.y + 25, 50, 50, "red");
        for(int i = 0; i<4; i++){
            //part[i].setFill(true);
            //part[i].setColor(COLOR("red"));
        }
    }
    void Square::transform(char input){
        switch(input){
            case 'w':
            case 'R':
                break;
            case 's':
            case 'T':
                center = Point(center.x , center.y + 50);
                for(int i =0; i<4; i++) part[i].move(0,50);
                break;
            case 'a':
            case 'Q':
                center = Point(center.x - 50, center.y );
                for(int i =0; i<4; i++) part[i].move(-50,0);
                break;
            case 'd':
            case 'S':
                center = Point(center.x + 50, center.y);
                for(int i =0; i<4; i++) part[i].move(50,0);
                break;
            default:
                break;
        }
    }
    vector<Point> Square::nextMovePoints(char input){
        vector<Point> vec;
        int x = center.x, y = center.y;
        switch(input){
            case 'w':
            case 'R':
                break;
            case 's':
            case 'T':
                y += 50;
                break;
            case 'a':
            case 'Q':
                x-= 50;
                break;
            case 'd':
            case 'S':
                x+= 50;
                break;
            default:
                break;
        }
        vec.push_back(Point(x - 25, y - 25));
        vec.push_back(Point(x + 25, y - 25));
        vec.push_back(Point(x - 25, y + 25));
        vec.push_back(Point(x + 25, y + 25));
        return vec;
    }