#include "othello.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int convert(string a){
    if(a=="A") return 0;
    else if(a=="B") return 1;
    else if(a=="C") return 2;
    else if(a=="D") return 3;
    else if(a=="E") return 4;
    else if(a=="F") return 5;
    else if(a=="G") return 6;
    else if(a=="H") return 7;
}

int main(){
    Othello game;
    cout << "Welcome to Othello Game!!" << endl;
    cout << "Player1 marks with 'O' symbol." << endl;
    cout << "Player2 marks with 'X' symbol." << endl;
    cout << "Type the place where you want to put your mark on!!" << endl;
    cout << "ex) A5 / F2 / D8 ..." << endl;

    while(1){
        int row, col;
        string input;
        game.print_stage();
        if(game.get_turn()==1){
            if(game.game_check(1)==1){
                cout << "Now it's Player1's turn. Type the place : " << endl;
                cin >> input;
                row=convert(input.substr(0,1));
                col = stoi(input.substr(1,1))-1;
                if(game.mark_check(row, col, 1)==1){
                    game.put_mark(row, col, 1);
                    game.change_turn();
                }
                else cout << "You cannot mark there!! Select another place." << endl;
            }
            else{
                if(game.game_check(2)==1){
                    cout << "Player1 doesn't have the place to mark on..." << endl;
                    game.change_turn();
                }
                else break;
            }
            if(game.game_check(1)==0 && game.game_check(2)==0) break;
        }
        else if(game.get_turn()==2){
            if(game.game_check(2)==1){
                cout << "Now it's Player2's turn. Type the place : " << endl;
                cin >> input;
                row=convert(input.substr(0,1));
                col = stoi(input.substr(1,1))-1;
                if(game.mark_check(row, col, 2)==1){
                    game.put_mark(row, col, 2);
                    game.change_turn();
                }
                else cout << "You cannot mark there!! Select another place." << endl;
            }
            else{
                if(game.game_check(1)==1){
                    cout << "Player2 doesn't have the place to mark on..." << endl;
                    game.change_turn();
                }
                else break;
            }
            if(game.game_check(1)==0 && game.game_check(2)==0) break;
        }
        else{
            cout << "Error occured. Game is finished..." << endl;
            exit(1);
        }
    }
    game.print_stage();
    cout << "The game is over!!!" << endl;
    cout << "Player1 got " << game.get_score1() << " points." << endl;
    cout << "Player2 got " << game.get_score2() << " points." << endl;
    if(game.get_score1()>game.get_score2()) cout << "Player1 won the game!!!";
    else if(game.get_score1()<game.get_score2()) cout << "Player2 won the game!!!";
    else cout << "It's a draw.";
}
