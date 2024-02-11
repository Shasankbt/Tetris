#include<iostream>
#include "blocks.h"

    l_left::l_left(){
        center = Point(275, 125);
        for(int i =0; i<3; i++)part[i] = Block(300, 50 + 50*i, 50, 50, "blue");
        part[3] = Block(250, 150, 50, 50, "blue");
    }
    
    void l_left::transform(char input){
        int x = 0, y = 0;
        
        switch(input){
            case 'a':
            case 'Q':
                for(int i =0; i<4; i++) part[i].move(-50,0); 
                center.x -= 50;
                break;
            case 's':
            case 'T':
                for(int i =0; i<4; i++) part[i].move(0, 50); 
                center.y += 50;
                break;
            case 'd':
            case 'S':
                for(int i =0; i<4; i++) part[i].move(50, 0); 
                center.x += 50;
                break;
            case 'q':
            case 'e':
                
                if(input == 'q') orientation.change_orient(-1);
                if(input == 'e') orientation.change_orient(1);
                
                switch (orientation.curr_orient){
                    case 0:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x + 25, center.y + i*50 - 25, 50, 50, "blue");
                        part[3] = Block(center.x-25, center.y + 25, 50, 50, "blue");
                        break;
                    case 1:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x + i*50 + 25, center.y + 25 , 50, 50, "blue");
                        part[3] = Block(center.x - 25, center.y - 25, 50, 50, "blue");
                        break;
                    case 2:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x - 25, center.y + i*50 + 25, 50, 50, "blue");
                        part[3] = Block(center.x + 25, center.y - 25, 50, 50, "blue");
                        break;
                    case 3:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x + i*50 -25, center.y - 25, 50, 50, "blue");
                        part[3] = Block(center.x + 25, center.y + 25, 50, 50, "blue");
                        break;
                    default:
                        break;
                }

            default:
                break;
        }
    }

    vector<Point> l_left::nextMovePoints(char input){
        vector<Point> vec;
        int x=0, y=0;
        switch(input){
            case 'a':
            case 'Q':
                x -= 50;
                break;
            case 's':
            case 'T':
                y += 50; 
                break;
            case 'd':
            case 'S':
                x += 50;
                break;
            case 'q':
            case 'e':
                if(input == 'q') orientation.change_orient(-1);
                if(input == 'e') orientation.change_orient(1);
                switch (orientation.curr_orient){
                    
                    case 0:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x + 25, center.y + i*50 -25 ));
                        vec.push_back(Point(center.x-25, center.y + 25));
                        break;
                    case 1:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x + i*50 + 25, center.y + 25 ));
                        vec.push_back(Point(center.x - 25, center.y - 25));
                        break;
                    case 2:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x - 25, center.y + i*50 + 25));
                        vec.push_back(Point(center.x + 25, center.y - 25));
                        break;
                    case 3:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x + i*50 -25, center.y - 25));
                        vec.push_back(Point(center.x + 25, center.y + 25));
                        break;
                    
                    default:
                        break;
                }
                if(input == 'q') orientation.change_orient(1);
                if(input == 'e') orientation.change_orient(-1);
                return vec;
            default:
                break;
        }
        for(int i =0; i<4; i++) vec.push_back(Point(part[i].x+x, part[i].y+y));
        return vec;
    }

    l_right::l_right(){
        center = Point(275, 125);
        for(int i =0; i<3; i++)part[i] = Block(250, 50 + 50*i, 50, 50, "light blue");
        part[3] = Block(300, 150, 50, 50, "light blue");
    }
    
    void l_right::transform(char input){
        int x = 0, y = 0;
        
        switch(input){
            case 'a':
            case 'Q':
                for(int i =0; i<4; i++) part[i].move(-50,0); 
                center.x -= 50;
                break;
            case 's':
            case 'T':
                for(int i =0; i<4; i++) part[i].move(0, 50); 
                center.y += 50;
                break;
            case 'd':
            case 'S':
                for(int i =0; i<4; i++) part[i].move(50, 0); 
                center.x += 50;
                break;
            case 'q':
            case 'e':
                
                if(input == 'q') orientation.change_orient(-1);
                if(input == 'e') orientation.change_orient(1);
                
                switch (orientation.curr_orient){
                    case 0:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x - 25, center.y + i*50 - 25, 50, 50, "light blue");
                        part[3] = Block(center.x + 25, center.y + 25, 50, 50, "light blue");
                        break;
                    case 1:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x + i*50 + 25, center.y - 25 , 50, 50, "light blue");
                        part[3] = Block(center.x - 25, center.y + 25, 50, 50, "light blue");
                        break;
                    case 2:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x + 25, center.y + i*50 + 25, 50, 50, "light blue");
                        part[3] = Block(center.x - 25, center.y - 25, 50, 50, "light blue");
                        break;
                    case 3:
                        for(int i = -1; i<2; i++) part[i+1] = Block(center.x + i*50 -25, center.y + 25, 50, 50, "light blue");
                        part[3] = Block(center.x + 25, center.y - 25, 50, 50, "light blue");
                        break;
                    default:
                        break;
                }

            default:
                break;
        }
    }

    vector<Point> l_right::nextMovePoints(char input){
        vector<Point> vec;
        int x=0, y=0;
        switch(input){
            case 'a':
            case 'Q':
                x -= 50;
                break;
            case 's':
            case 'T':
                y += 50; 
                break;
            case 'd':
            case 'S':
                x += 50;
                break;
            case 'q':
            case 'e':
                if(input == 'q') orientation.change_orient(-1);
                if(input == 'e') orientation.change_orient(1);
                switch (orientation.curr_orient){
                    
                    case 0:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x - 25, center.y + i*50 -25 ));
                        vec.push_back(Point(center.x + 25, center.y + 25));
                        break;
                    case 1:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x + i*50 + 25, center.y - 25 ));
                        vec.push_back(Point(center.x - 25, center.y + 25));
                        break;
                    case 2:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x + 25, center.y + i*50 + 25));
                        vec.push_back(Point(center.x - 25, center.y - 25));
                        break;
                    case 3:
                        for(int i = -1; i<2; i++) vec.push_back(Point(center.x + i*50 -25, center.y + 25));
                        vec.push_back(Point(center.x + 25, center.y - 25));
                        break;
                    default:
                        break;
                }
                if(input == 'q') orientation.change_orient(1);
                if(input == 'e') orientation.change_orient(-1);
                return vec;
            default:
                break;
        }
        for(int i =0; i<4; i++) vec.push_back(Point(part[i].x+x, part[i].y+y));
        return vec;
    }
