#include <iostream>
#include <random>

using namespace std;

void TTTdraw(char a[])
{
    cout << "   |   |   " << endl << " " << a[0] << " | " << a[1] << " | " << a[2] << " " << endl << "___|___|___" << endl << "   |   |   " << endl << " " << a[3] << " | " << a[4] << " | " << a[5] << " " << endl << "___|___|___" << endl << "   |   |   " << endl << " " << a[6] << " | " << a[7] << " | " << a[8] << " " << endl;
}

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
        }}
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

int getInput()
{
int input;
while (true){
cout << "What is your move?";
cin >> input;
if (input>=1 && input<=9){
    return (input);
    } else {
        cout << "Invlaid Move.";
    }
}
}

int autoMove(char a[]){

    for(int i = 8; i>=0; i--){
        int aiTry = rand() % ( i + 1 );
        if (a[aiTry]=='X'){
            cout << "Thinking...";
        }
        else {
            cout << "This One!";
            return (aiTry);
        }

    }

}


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
if (turns<9){
TTT[autoMove(TTT)]='O';
turns++;
}
if (turns>=6 && turns%2==0){
    if(winCheck(TTT, 'O')){
        won=1;
    }
}

else {
    cout << "Max Moves Reached!";
}
}
if (won==true){
    cout << "You Win! Congratulations!";
}
else {
    cout << "You'll get 'em next time, champ!";
}
}
