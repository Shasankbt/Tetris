// #include <iostream>

#include "blocks.h"
    lin::lin(){
        pivot = Point(275, 125);
        for(int i = 0; i<4; i++) part[i] = Block(300, 50+50*i,  50, 50, "orange");        
    }

    void lin::transform(char input){
        switch(input){
            case 'w':
            case 'R':
                break;
            case 's':
            case 'T':
                pivot.y += 50;
                for(int i =0; i<4; i++) part[i].move(0,50);
                break;
            case 'a':
            case 'Q':
                pivot.x -=50;
                for(int i =0; i<4; i++) part[i].move(-50,0);
                break;
            case 'd':
            case 'S':
                pivot.x += 50;
                for(int i =0; i<4; i++) part[i].move(50,0);
                break;
            case 'q':
            case 'e':
                if(input == 'e') orientation.change_orient(1);
                if(input == 'q') orientation.change_orient(-1);
                switch(orientation.curr_orient){
                    case 0:
                        for(int i =0; i<4; i++) part[i] = Block(pivot.x + 25, pivot.y-75 + 50*i, 50, 50, "orange");
                        break;
                    case 1:
                        for(int i =0; i<4; i++) part[i] = Block(pivot.x - 75 + 50*i, pivot.y + 25, 50, 50, "orange");
                        break;
                    case 2:
                        for(int i =0; i<4; i++) part[i] = Block(pivot.x - 25, pivot.y-75 + 50*i, 50, 50, "orange");
                        break;
                    case 3:
                        for(int i =0; i<4; i++) part[i] = Block(pivot.x - 75 + 50*i, pivot.y - 25, 50, 50, "orange");
                        break;
                }
                break;
            default:
                break;
        }

    
    }
    
    vector<Point> lin::nextMovePoints(char input){
        vector<Point> vec;
        int x = pivot.x, y = pivot.y;
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
        if(input == 'e') orientation.change_orient(1);
                if(input == 'q') orientation.change_orient(-1);
                switch(orientation.curr_orient){
                    case 0:
                        for(int i =0; i<4; i++) vec.push_back(Point(x + 25, y-75 + 50*i));
                        break;
                    case 1:
                        for(int i =0; i<4; i++) vec.push_back(Point(x - 75 + 50*i, y + 25));
                        break;
                    case 2:
                        for(int i =0; i<4; i++) vec.push_back(Point(x - 25, y-75 + 50*i));
                        break;
                    case 3:
                        for(int i =0; i<4; i++) vec.push_back(Point(x - 75 + 50*i, y - 25));
                        break;
                }
                if(input == 'e') orientation.change_orient(-1);
                if(input == 'q') orientation.change_orient(+1);
        return vec;
    }