#include "othello.h"
#include <iostream>

using namespace std;

Othello::Othello(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) stage[i][j]=0;
    }
    stage[3][3]=1;
    stage[4][4]=1;
    stage[3][4]=2;
    stage[4][3]=2;
    turn = 1;
}

int Othello::get_turn(){ return turn; }

void Othello::change_turn(){
    if(turn==1) turn=2;
    else turn=1;
}

bool Othello::mark_check(int row, int col, int turn){
    int chk=0;
    int op=0;
    int mid=1;
    
    if(stage[row][col]==0){
        int i=row+2;
        while(i<8){
            if(stage[i][col]==turn){op=1; break;}
            i++;
        }
        if(op==1){
            for(int j=row+1; j<i; j++){
                if(stage[j][col]==0) mid=0;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }

        i=row-2;
        while(i>=0){
            if(stage[i][col]==turn){op=1; break;}
            i--;
        }
        if(op==1){
            for(int j=row-1; j>i; j--){
                if(stage[j][col]==0) mid=0;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }
    
        i=col+2;
        while(i<8){
            if(stage[row][i]==turn){op=1; break;}
            i++;
        }
        if(op==1){
            for(int j=col+1; j<i; j++) {
                if(stage[row][j]==0) mid=0;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }

        i=col-2;
        while(i>=0){
            if(stage[row][i]==turn){op=1; break;}
            i--;
        }
        if(op==1){
            for(int j=col-1; j>i; j--){
                if(stage[row][j]==0) mid=0;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }

        i=row+2;
        int i2=col+2;
        while(i<8 && i2<8){
            if(stage[i][i2]==turn){op=1; break;}
            i++;
            i2++;
        }
        if(op==1){
            int j=row+1;
            int j2=col+1;
            while(j<i){
                if(stage[j][j2]==0) mid=0;
                j++;
                j2++;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }

        i=row-2;
        i2=col-2;
        while(i>=0 && i2>=0){
            if(stage[i][i2]==turn){op=1; break;}
            i--;
            i2--;
        }
        if(op==1){
            int j=row-1;
            int j2=col-1;
            while(j>i){
                if(stage[j][j2]==0) mid=0;
                j--;
                j2--;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }

        i=row+2;
        i2=col-2;
        while(i<8 && i2>=0){
            if(stage[i][i2]==turn){op=1; break;}
            i++;
            i2--;
        }
        if(op==1){
            int j=row+1;
            int j2=col-1;
            while(j<i){
                if(stage[j][j2]==0) mid=0;
                j++;
                j2--;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }

        i=row-2;
        i2=col+2;
        while(i>=0 && i2<8){
            if(stage[i][i2]==turn){op=1; break;}
            i--;
            i2++;
        }
        if(op==1){
            int j=row-1;
            int j2=col+1;
            while(j>i){
                if(stage[j][j2]==0) mid=0;
                j--;
                j2++;
            }
            if(mid==1) chk=1;
            mid=1;
            op=0;
        }
    }
    return chk;
}

void Othello::put_mark(int row, int col, int turn){
    int op=0;
    int mid=1;
    
    if(mark_check(row,col,turn)==1){
        stage[row][col]=turn;
        int i=row+1;
        while(i<8){
            if(stage[i][col]==turn){op=1; break;}
            i++;
        }
        if(op==1){
            for(int j=row+1; j<i; j++){
                if(stage[j][col]==0) mid=0;
            }
            if(mid==1){
                for(int j=row+1; j<i; j++){
                    stage[j][col]=turn;
                }
            }
            mid=1;
            op=0;
        }

        i=row-1;
        while(i>=0){
            if(stage[i][col]==turn){op=1; break;}
            i--;
        }
        if(op==1){
            for(int j=row-1; j>i; j--){
                if(stage[j][col]==0) mid=0;
            }
            if(mid==1){
                for(int j=row-1; j>i; j--){
                    stage[j][col]=turn;
                }
            }
            mid=1;
            op=0;
        }
    
        i=col+1;
        while(i<8){
            if(stage[row][i]==turn){op=1; break;}
            i++;
        }
        if(op==1){
            for(int j=col+1; j<i; j++) {
                if(stage[row][j]==0) mid=0;
            }
            if(mid==1){
                for(int j=col+1; j<i; j++){
                    stage[row][j]=turn;
                }
            }
            mid=1;
            op=0;
        }

        i=col-1;
        while(i>=0){
            if(stage[row][i]==turn){op=1; break;}
            i--;
        }
        if(op==1){
            for(int j=col-1; j>i; j--){
                if(stage[row][j]==0) mid=0;
            }
            if(mid==1){
                for(int j=col-1; j>i; j--){
                    stage[row][j]=turn;
                }
            }
            mid=1;
            op=0;
        }

        i=row+1;
        int i2=col+1;
        while(i<8 && i2<8){
            if(stage[i][i2]==turn){op=1; break;}
            i++;
            i2++;
        }
        if(op==1){
            int j=row+1;
            int j2=col+1;
            while(j<i){
                if(stage[j][j2]==0) mid=0;
                j++;
                j2++;
            }
            j=row+1;
            j2=col+1;
            if(mid==1){
                while(j<i){
                    stage[j][j2]=turn; j++; j2++;
                }
            }
            mid=1;
            op=0;
        }

        i=row-1;
        i2=col-1;
        while(i>=0 && i2>=0){
            if(stage[i][i2]==turn){op=1; break;}
            i--;
            i2--;
        }
        if(op==1){
            int j=row-1;
            int j2=col-1;
            while(j>i){
                if(stage[j][j2]==0) mid=0;
                j--;
                j2--;
            }
            j=row-1;
            j2=col-1;
            if(mid==1){
                while(j>i){
                    stage[j][j2]=turn; j--; j2--;
                }
            }
            mid=1;
            op=0;
        }

        i=row+1;
        i2=col-1;
        while(i<8 && i2>=0){
            if(stage[i][i2]==turn){op=1; break;}
            i++;
            i2--;
        }
        if(op==1){
            int j=row+1;
            int j2=col-1;
            while(j<i){
                if(stage[j][j2]==0) mid=0;
                j++;
                j2--;
            }
            j=row+1;
            j2=col-1;
            if(mid==1){
                while(j<i){
                    stage[j][j2]=turn; j++; j2--;
                }
            }
            mid=1;
            op=0;
        }

        i=row-1;
        i2=col+1;
        while(i>=0 && i2<8){
            if(stage[i][i2]==turn){op=1; break;}
            i--;
            i2++;
        }
        if(op==1){
            int j=row-1;
            int j2=col+1;
            while(j>i){
                if(stage[j][j2]==0) mid=0;
                j--;
                j2++;
            }
            j=row-1;
            j2=col+1;
            if(mid==1){
                while(j>i){
                    stage[j][j2]=turn; j--; j2++;
                }
            }
            mid=1;
            op=0;
        }
    }
}

bool Othello::game_check(int turn){
    int chk=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(stage[i][j]==0 && mark_check(i,j,turn)==1) chk=1;
        }
    }
    return chk;
}

void Othello::print_stage(){
    int col=65;
    cout << "   1   2   3   4   5   6   7   8" << endl;
    cout << "  --- --- --- --- --- --- --- ---" << endl;
    for(int i=0; i<8; i++){
        cout << char(col+i) << "|";
        for(int j=0; j<8; j++){
            if(stage[i][j]==0) cout << "   |";
            else if(stage[i][j]==1) cout << " O |";
            else cout << " X |";
        }
        cout << endl;
        cout << "  --- --- --- --- --- --- --- ---" << endl;
    }
}

int Othello::get_score1(){
    int score=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(stage[i][j]==1) score++;
        }
    }
    return score;
}

int Othello::get_score2(){
    int score=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(stage[i][j]==2) score++;
        }
    }
    return score;
}
