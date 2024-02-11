#include<iostream>
#include "blocks.h"


    t_block::t_block(){
        center = Point(250, 100);
        for(int i =0; i<3; i++) part[i] = Block(center.x + 50*i - 50, center.y, 50, 50, "violet");
        part[3] = Block(center.x, center.y - 50, 50, 50, "violet");
    }

    void t_block::transform(char input){        
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
                        for(int i =0; i<3; i++) part[i] = Block(center.x + 50*i - 50, center.y, 50, 50, "violet");
                        part[3] = Block(center.x, center.y - 50, 50, 50, "violet");
                        break;
                    case 1:
                        for(int i =0; i<3; i++) part[i] = Block(center.x, center.y + 50*i - 50, 50, 50, "violet");
                        part[3] = Block(center.x + 50, center.y, 50, 50, "violet");
                        break;
                    case 2:
                        for(int i =0; i<3; i++) part[i] = Block(center.x + 50*i - 50, center.y, 50, 50, "violet");
                        part[3] = Block(center.x, center.y + 50, 50, 50, "violet");
                        break;
                    case 3:
                        for(int i =0; i<3; i++) part[i] = Block(center.x, center.y + 50*i - 50, 50, 50, "violet");
                        part[3] = Block(center.x - 50, center.y, 50, 50, "violet");
                        break;
                    default:
                        break;
                }

            default:
                break;
        }
        
    }

    vector<Point> t_block::nextMovePoints(char input){  
        int x =0, y =  0;
        vector<Point> vec;      
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
                        for(int i =0; i<3; i++) vec.push_back(Point(center.x + 50*i - 50, center.y));
                        vec.push_back(Point(center.x, center.y - 50));
                        break;
                    case 1:
                        for(int i =0; i<3; i++) vec.push_back(Point(center.x, center.y + 50*i - 50));
                        vec.push_back(Point(center.x + 50, center.y));
                        break;
                    case 2:
                        for(int i =0; i<3; i++) vec.push_back(Point(center.x + 50*i - 50, center.y));
                        vec.push_back(Point(center.x, center.y + 50));
                        break;
                    case 3:
                        for(int i =0; i<3; i++) vec.push_back(Point(center.x, center.y + 50*i - 50));
                        vec.push_back(Point(center.x - 50, center.y));
                        break;
                    default:
                        break;
                }

                if(input == 'q') orientation.change_orient(-1);
                if(input == 'e') orientation.change_orient(1);

                return vec;

            default:
                break;
        }
        for(int i =0; i<4; i++) vec.push_back(Point(part[i].x+x, part[i].y+y));
        return vec;
    }