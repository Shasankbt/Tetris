#include<simplecpp>
#include<vector>
#include "./blocks/blocks.h"





bool element_in(vector<vector<Point>> & matrix, const Point & element){
    int x = element.x, y = element.y;
    for(int i =0; i<25; i++) for(int j =  0; j<10; j++) if(matrix[i][j].x == x && matrix[i][j].y == y) return true;
    return false;
}


void clearLine(vector<vector<Point>> & matrix, vector<vector<Block>> & blocks, int & score){
    for(int i =0; i<25; i++){
        bool inLine = true;
        for(int j = 0; j<10; j++) if(matrix[i][j].x != 0) inLine = false;
        if(inLine){
            for(int j = 0; j<10; j++){
                matrix[i][j] = Point(50+50*j, 50+50*i);
            }
            blocks[i].clear();
            for(int j = i-1; j>=0; j--){
                for(unsigned int k = 0; k<blocks[j].size(); k++) blocks[j][k].move(0,50);
                for(int k = 0; k<10; k++){
                    blocks[j+1] = blocks[j];
                    if(!(matrix[j+1][k].x = matrix[j][k].x)) matrix[j+1][k].y = 0;
                    else matrix[j+1][k].y = 50*(j+2); 
                } 
                wait(0.01);
            } 
            score++;
        }
    }
}



bool gameOver(vector<vector<Point>> matrix){
    for(int i =0; i<5; i++){
        for(int j =0; j<10; j++) if(matrix[i][j].x == 0 && matrix[i][j].y == 0) return true;
    }
    return false;
}



