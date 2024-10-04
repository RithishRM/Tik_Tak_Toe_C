#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];   //This is global variable for the board 
const char PLAYER='X';  //The const keyword is used here as we don't want the values to change
const char COMP='O';

void resetboard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}

void printboard(){
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

}

int freespaces(){
    int fs=9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                fs--;
            }
        }
    }
    return fs;
}

void playermove(){
    int x;
    int y; 
    do{
    printf("Enter Row (1-3)-");
    scanf("%d",&x);
    x--;
    printf("Enter Column (1-3)-");
    scanf("%d",&y);
    y--;
    if(board[x][y]!=' '){
        printf("Invalid Move!!!");
    }else{
        board[x][y]=PLAYER;
        break;
    }
        
    } while (board[x][y] != ' ');
}

char checkwinner(){
    for(int i=0;i<3;i++){   //Checks Rows
        if(board[i][0]==board[i][1]&& board[i][0]==board[i][2]){
            return board[i][0];
        }
    }
    for(int i=0;i<3;i++){   //Checks Column
        if(board[0][i]==board[1][i]&& board[0][i]==board[2][i]){
            return board[0][i];
        }
    }
    //Check Diagnols
    if(board[0][0]==board[1][1]&& board[0][0]==board[2][2]){
            return board[0][0];
        }
    if(board[0][2]==board[1][1]&& board[0][2]==board[2][0]){
            return board[0][2];
        }
    return ' ';
}

void printwinner(char winner);

void Compmove(){
    srand(time(0)); //Creates a seed based on current time
    int x;int y;
    if(freespaces()>0){
        do
        {   //We give it a modulus of 3 as the it always returns a number within 0-2
            x=rand()%3;
            y=rand()%3;
        } while (board[x][y]!=' ');
        board[x][y]=COMP;
    }else{
        printwinner(' ');   //The Empty space means there is no winner and its a draw
    }
}

void printwinner(char winner){
    if(winner==PLAYER){
        printf("YOU WIN!!");
    }else if(winner==COMP){
        printf("YOU LOSE!!");
    }else{
        printf("ITS A DRAW!!");
    }
}

int main(){
    char winner =' ';
    resetboard();
    while(winner==' ' && freespaces()!=0){   //Here if winner is equal to ' ' then that means there is no winner 
        printboard();
        //Player Move
        playermove();
        winner=checkwinner();
        if(winner!=' '||freespaces()==0){
            break;  //This means we have a winner and we are breaking out of the while loop
        }
        //Computer Move
        Compmove();
        winner=checkwinner();
        if(winner!=' '||freespaces()==0){
            break;  //This means we have a winner and we are breaking out of the while loop
        }
    }
    printboard();
    printwinner(winner);

    return 0;
    
}