#include<iostream>
#include "blocks.h"

    z_left::z_left(){
        center = Point(250, 100);
        for(int i =0; i<2; i++) part[i] = Block(center.x, center.y - 50 + 50*i, 50, 50, "green");
        for(int i =2; i<4; i++) part[i] = Block(center.x + 50, center.y - 100 + 50*i, 50, 50, "green");
    }

    void z_left::transform(char input){        
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
                        for(int i =0; i<2; i++) part[i] = Block(center.x, center.y - 50 + 50*i, 50, 50, "green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x + 50, center.y - 100 + 50*i, 50, 50, "green");
                        break;
                    case 1:
                        for(int i =0; i<2; i++) part[i] = Block(center.x + 50*i, center.y, 50, 50, "green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x - 150 + 50*i, center.y + 50, 50, 50, "green");
                        break;
                    case 2:
                        for(int i =0; i<2; i++) part[i] = Block(center.x, center.y + 50*i, 50, 50, "green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x - 50, center.y - 150 + 50*i, 50, 50, "green");
                        break;
                    case 3:
                        for(int i =0; i<2; i++) part[i] = Block(center.x + 50*i - 50, center.y, 50, 50, "green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x - 100 + 50*i, center.y - 50, 50, 50, "green");
                        break;
                    default:
                        break;
                }

            default:
                break;
        }
        
    }

    vector<Point> z_left::nextMovePoints(char input){  
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
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x, center.y - 50 + 50*i));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x + 50, center.y - 100 + 50*i));
                        break;
                    case 1:
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x + 50*i, center.y));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x - 150 + 50*i, center.y + 50));
                        break;
                    case 2:
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x, center.y + 50*i));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x - 50, center.y - 150 + 50*i));
                        break;
                    case 3:
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x + 50*i - 50, center.y));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x - 100 + 50*i, center.y - 50));
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


    z_right::z_right(){
        center = Point(300, 100);
        for(int i =0; i<2; i++) part[i] = Block(center.x, center.y - 50 + 50*i, 50, 50, "dark green");
        for(int i =2; i<4; i++) part[i] = Block(center.x - 50, center.y - 100 + 50*i, 50, 50, "dark green");
    }

    void z_right::transform(char input){        
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
                        for(int i =0; i<2; i++) part[i] = Block(center.x, center.y - 50 + 50*i, 50, 50, "dark green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x - 50, center.y - 100 + 50*i, 50, 50, "dark green");
                        break;
                    case 1:
                        for(int i =0; i<2; i++) part[i] = Block(center.x + 50*i, center.y, 50, 50, "dark green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x - 150 + 50*i, center.y - 50, 50, 50, "dark green");
                        break;
                    case 2:
                        for(int i =0; i<2; i++) part[i] = Block(center.x, center.y + 50*i, 50, 50, "dark green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x + 50, center.y - 150 + 50*i, 50, 50, "dark green");
                        break;
                    case 3:
                        for(int i =0; i<2; i++) part[i] = Block(center.x + 50*i - 50, center.y, 50, 50, "dark green");
                        for(int i =2; i<4; i++) part[i] = Block(center.x - 100 + 50*i, center.y + 50, 50, 50, "dark green");
                        break;
                    default:
                        break;
                }

            default:
                break;
        }
        
    }

    vector<Point> z_right::nextMovePoints(char input){  
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
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x, center.y - 50 + 50*i));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x - 50, center.y - 100 + 50*i));
                        break;
                    case 1:
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x + 50*i, center.y));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x - 150 + 50*i, center.y - 50));
                        break;
                    case 2:
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x, center.y + 50*i));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x + 50, center.y - 150 + 50*i));
                        break;
                    case 3:
                        for(int i =0; i<2; i++) vec.push_back(Point(center.x + 50*i - 50, center.y));
                        for(int i =2; i<4; i++) vec.push_back(Point(center.x - 100 + 50*i, center.y + 50));
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