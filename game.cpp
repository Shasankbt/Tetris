#include<simplecpp>
#include<vector>
//#include "basic_elements.h"
#include "blocks/blocks.h"
#include "gameFunctions.h"
int main(){

    //-----------------------Background-----------------------
    initCanvas("tetris", 550, 1350);
    Rectangle border[2];
    border[0] = Rectangle(275 , 775 , 510, 1010);
    border[0].setFill(true);
    border[0].setColor(COLOR("green"));
    border[1] = Rectangle(275, 775, 500, 1000);
    border[1].setFill(true);
    border[1].setColor(COLOR("white"));
    Line v_line[11];
    Line h_line[26];
    for(int i = 0; i<11; i++){
        v_line[i] = Line(25+50*i,25, 25+50*i, 1275);
        v_line[i].setFill(true);
        v_line[i].setColor(COLOR(200,200,200));
    }
    for(int i =0; i<26; i++){
        h_line[i] = Line(25, 25+50*i, 525, 25+50*i);
        h_line[i].setFill(true);
        h_line[i].setColor(COLOR(200,200,200));
    }
    
    //----------------------Properties-------------------------
    vector<vector<Point>> fillArray (25, vector<Point> (10));
    for(int i =0; i<25; i++) for(int j=0; j<10; j++) fillArray[i][j] = Point(50+50*j, 50+50*i);

    vector<vector<Block>> blocks (25);

    int score = 0;
    Text score_card(275, 1320, ("score : " + to_string(score)));

    srand(time(NULL));
    while(true){
        int a = (rand()%7)+1;
        if(a == 1){
            Square sq;
            gamePlay<Square>(fillArray, blocks, sq);
            //break;
        }
        if(a == 2){
            lin sq;
            gamePlay<lin>(fillArray, blocks, sq);
        }
        if(a == 3){
            l_left sq;
            gamePlay<l_left>(fillArray, blocks, sq);
        }
        if(a == 4){
            l_right sq;
            gamePlay<l_right>(fillArray, blocks, sq);
        }
        if(a == 5){
            z_left sq;
            gamePlay<z_left>(fillArray, blocks, sq);
        }
        if(a == 6){
            z_right sq;
            gamePlay<z_right>(fillArray, blocks, sq);
        }
        if(a == 7){
            t_block sq;
            gamePlay<t_block>(fillArray, blocks, sq);
        }
        
        clearLine(fillArray, blocks, score); 
        
        score_card = Text(275, 1320, ("score : " + to_string(score)));

        if(gameOver(fillArray)) {
            border[0].setColor(COLOR("red"));
            break;
        }
    }
    getClick();
}
