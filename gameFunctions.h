#include<simplecpp>
#include<vector>
#include "./blocks/blocks.h"

bool element_in(vector<vector<Point>> & , const Point & );

template<typename obj_type>
bool valid_move(vector<vector<Point>> & matrix, obj_type & object, char input){
    //cout<<"here1"<<endl;
    vector<Point> pointVec = object.nextMovePoints(input);
    

    for(int i=0; i<4; i++){
        //cout<<pointVec[i].x<<','<<pointVec[i].y<<'\t';
        //cout<<pointVec.size()<<endl;
        if(!element_in(matrix, pointVec[i])) {
            //cout<<"not possible"<<endl;
            //cout<<object.part[i].elementBorder.getX()<<endl;
            return false;
            //cout<<"invalid"<<endl;
        }
    }
    
    //cout<<"possible"<<endl;
    return true;
}


void clearLine(vector<vector<Point>> & , vector<vector<Block>> & , int & );

bool gameOver(vector<vector<Point>> );

template<typename obj_type>
void gamePlay(vector<vector<Point>> & fillArray, vector<vector<Block>> & blocks, obj_type & sq){
    while(true){
            XEvent event;
            nextEvent(event);
            if(keyPressEvent(event)){
                char c = charFromEvent(event);
                if((c != 's' && c != 'T' ) && valid_move(fillArray, sq, c)) {
                    //cout<<"valid"<<endl;
                    sq.transform(c);
                }

                //cout<<"moved\n";

                wait(0.1);

                if(!valid_move(fillArray, sq, 's')) {
                    for(int i = 0; i<4; i++){
                        cout<<"validated move\n";
                        fillArray[sq.part[i].getY()/50 - 1][sq.part[i].getX()/50 - 1] = Point(0,0);
                        blocks[sq.part[i].getY()/50-1].push_back(sq.part[i]);
                        cout<<"over"<<endl;              
                    }
                    break;
                }

                sq.transform('s');
                if(!valid_move(fillArray, sq, 's')) {
                    for(int i = 0; i<4; i++){
                        
                        fillArray[sq.part[i].getY()/50 - 1][sq.part[i].getX()/50 - 1] = Point(0,0);
                        blocks[sq.part[i].getY()/50-1].push_back(sq.part[i]);          
                    }
                    break;
                }
                
                while(checkEvent(event)){
                    
                    char other = charFromEvent(event);
                    //cout<<c<<endl;
                }
                    
            }
        }
}

