#include<simplecpp>
#include<vector>

#ifndef BLOCKS_H
#define BLOCKS_H

struct Point {
    int x, y;
    Point(int, int);
    Point ();
};

struct Block{
    Rectangle elementBorder;
    Rectangle element;
    int x, y;
    
    Block();
    Block(int, int, int , int , const char color[15]);

    int getX();
    int getY();
    Point getCenter();
    void move(int a, int b);
};

struct Orientation{
    int curr_orient;
    Orientation();    
    void change_orient(int);
    
};

struct Square {
    Block part[4];
    Point center;

    Square();

    void transform(char);
    vector<Point> nextMovePoints(char);
};

struct lin{
    Block part[4];
    Point pivot;
    Orientation orientation;

    lin();

    void transform(char input);
    vector<Point> nextMovePoints(char input);
};

struct l_left{
    Block part[4];
    Orientation orientation;
    Point center;
    l_left();
    
    void transform(char input);
    vector<Point> nextMovePoints(char input);
};

struct l_right{
    Block part[4];
    Orientation orientation;
    Point center;
    l_right();
    
    void transform(char input);
    vector<Point> nextMovePoints(char input);
};

struct z_left{
    Block part[4];
    Orientation orientation;
    Point center;
    z_left();

    void transform(char input);

    vector<Point> nextMovePoints(char input);
};

struct z_right{
    Block part[4];
    Orientation orientation;
    Point center;
    z_right();

    void transform(char input);

    vector<Point> nextMovePoints(char input);
};

struct t_block{
    Block part[4];
    Orientation orientation;
    Point center;
    t_block();

    void transform(char input);

    vector<Point> nextMovePoints(char input);
    
};

#endif