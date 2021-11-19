#include "othello.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int convert(string a){
    if(a=="A" || a=="a") return 0;
    else if(a=="B" || a=="b") return 1;
    else if(a=="C" || a=="c") return 2;
    else if(a=="D" || a=="d") return 3;
    else if(a=="E" || a=="e") return 4;
    else if(a=="F" || a=="f") return 5;
    else if(a=="G" || a=="g") return 6;
    else if(a=="H" || a=="h") return 7;
    else return -1;
}

int main(){
    Othello game;
    cout << "Welcome to Othello Game!!" << endl;
    cout << "Player1 marks with '○' symbol." << endl;
    cout << "Player2 marks with '●' symbol." << endl;
    cout << "Type the place where you want to put your mark on!!" << endl;
    cout << "ex) A5 / F2 / D8 ..." << endl;

    while(1){
        int row, col;
        string input;
        game.print_stage();
        if(game.get_turn()==1){
            if(game.game_check(1)==1){
                cout << "Now it's Player1's turn. Type the place : ";
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
                cout << "Now it's Player2's turn. Type the place : ";
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
