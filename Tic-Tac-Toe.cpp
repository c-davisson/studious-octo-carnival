#include <iostream>
#include <cstdlib>

using namespace std;

//Play a game of Tic-Tac-Toe in the Terminal against a computer generating random inputs.

//Draws the Board up-to-date when called.
void TTTdraw(char a[])
{
    cout << "   |   |   " << endl << " " << a[0] << " | " << a[1] << " | " << a[2] << " " << endl << "___|___|___" << endl << "   |   |   " << endl << " " << a[3] << " | " << a[4] << " | " << a[5] << " " << endl << "___|___|___" << endl << "   |   |   " << endl << " " << a[6] << " | " << a[7] << " | " << a[8] << " " << endl;
}

//Function to check if a player has won.
bool winCheck(char a[], char b)
{
    if (a[0]==b){
        if(a[1]==b && a[2]==b){
            return (true);
        }
        if (a[4]==b && a[8]==b){
            return (true);
        }
        if (a[3]==b && a[6]==b){
            return (true);
        }
    }
    if (a[1]==b && a[4]==b && a[7]==b){
        return (true);
    }
    if (a[2]==b && a[4]==b && a[6]==b){
        return (true);
    }
    if (a[2]==b && a[5]==b && a[8]==b){
        return (true);
    }
    if (a[3]==b && a[4]==b && a[5]==b){
        return (true);
    }
    if (a[6]==b && a[7]==b && a[8]==b){
        return (true);
    }

    return(false);
}

//Gets the user's move and checks if it's a valid move.
int getInput() {
    int input;
    while (true){
    cout << "What is your move?" << endl;
    cin >> input;
    if (input>=1 && input<=9){
        return (input);
        } else {
            cout << "Invlaid Move." << endl;
        }
    }
}

//Generate the computer's move. Each "Thinking... " in the terminal represents a failed random check.
int autoMove(char a[]){
    srand(time(NULL));
    while (true) {
        int aiTry = std::rand() % 9;
        if (a[aiTry]=='X' or a[aiTry]=='O'){
            cout << "Thinking... " << endl;
        }
        else {
            cout << "This One!" << endl;
            return (aiTry);
        }
    }
}

//main
int main()
{
    char TTT []= {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int turns=0;
    bool won=0;

    while (turns<9 && !won){
        TTTdraw(TTT);
        TTT[getInput()-1]='X';
        turns++;
        if (turns>=5 && turns%2!=0){
            if(winCheck(TTT, 'X')){
                won=1;
            }
        }
        if (turns<9 && won!=true){
            TTT[autoMove(TTT)]='O';
            turns++;
        }
        if (turns>=6 && turns%2==0){
            if(winCheck(TTT, 'O')){
                won=1;
            }
        }
    }

    TTTdraw(TTT);

    if (turns==9 && !won) {
        cout << "Max Moves Reached!" << endl;
    }
    
    if (won==true && turns%2!=0){
        cout << "You Win! Congratulations!";
    }
    else if (won!=true || turns%2==0){
        cout << "You'll get 'em next time, champ!";
    }
}
