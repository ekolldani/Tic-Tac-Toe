#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

vector<vector<char>> board(3, vector<char>(3));

void Print(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j != 2){
                if(board[i][j] == 'X' || board[i][j] == 'O'){
                    cout << ""<<board[i][j]<<" | ";
                }else{
                    cout << "  | ";
                }
            }else{
                cout << board[i][j];
            }
        }
        cout << "\n";
        if(i != 2){
            cout << "----------" << endl;
        }
    }
}

void GetCoords(string position, int& x, int& y){
    if(position[0] == 'M'){
        x = 1;
    }else if(position[0] == 'T'){
        x = 0;
    }else{
        x = 2;
    }

    if(position[1] == 'C'){
        y = 1;
    }else if(position[1] == 'L'){
        y = 0;
    }else {
        y = 2;
    }
}

string GetPos(){
    string position;
    cout << "Enter position: ";
    cin >> position;

    for(int i = 0; i < 2; i++){
        position[i] = toupper(position[i]);
    }
    
    return position;
}

void Input(char symbol){
    string position = GetPos();

    int x, y;

    GetCoords(position, x, y);

    if(board[x][y] == 'X' || board[x][y] == 'O'){
        cout << "\nInvalid position. Please enter again\n";
        Input(symbol);
    }else{
        board[x][y] = symbol;
    }
}


bool Check(char symbol){
    int identical = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(symbol == board[i][j]){
                identical++;
            }else{
                break;
            }
        }
        if(identical == 3){
            return true;
        }else{
            identical = 0;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(symbol == board[j][i]){
                identical++;
            }else{
                break;
            }
        }
        if(identical == 3){
            return true;
        }else{
            identical = 0;
        }
    }

    for(int i = 0; i < 3; i++){
        if(symbol == board[i][i]){
            identical++;
        }else{
            identical = 0;
            break;
        }
    }

    if(identical == 3) return true;

    for(int i = 2; i >= 0; i--){
        if(symbol == board[i][i]){
            identical++;
        }else{
            identical = 0;
            break;
        }
    }

    if(identical == 3){
        return true;
    }else{
        return false;
    }
}

int main(){
    char p1, p2;
    cout << "Player 1: X or O\n";
    cin >> p1;
    p1 = toupper(p1);
    if(p1 == 'X'){
        p2 = 'O';
    }else{
        p2 = 'X';
    }

    cout << "\nControls:\n";
    cout << "MC = Middle - Center\n";
    cout << "ML = Middle - Left\n";
    cout << "MR = Middle - Right\n";
    cout << "TC = Top - Center\n";
    cout << "TL = Top - Left\n";
    cout << "TR = Top - Right\n";
    cout << "BC = Bottom - Center\n";
    cout << "BL = Bottom - Left\n";
    cout << "BR = Bottom - Right\n";

    int no_inputs = 0;

    while(true){
        Input(p1);
        no_inputs++;
        cout << "\n";
        Print();
        cout << "\n";
        if(Check(p1)){
            cout << "Player 1 WINS! Congratulations!"<< endl;
            break;
        }else if(no_inputs == 9){
            cout << "TIE!";
            break;
        }
        Input(p2);
        no_inputs++;
        cout << "\n";
        Print();
        cout << "\n";
        if(Check(p2)){
            cout << "Player 2 WINS! Congratulations!" << endl;
            break;
        }else if(no_inputs == 9){
            cout << "TIE!";
            break;
        }
    }

    
}