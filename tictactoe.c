#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char arr[5][5];
void startboard(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            arr[i][j]='-';
        }
    }
}
void print(){
    printf("\nCurrent state of board:\n");
    int i,j;
    printf(" 1 2 3 4 5\n");
    for(i=0;i<5;i++){
        printf("%d",i+1);
        for(j=0;j<5;j++){
            printf("%c",arr[i][j]);
            if(j<4){
                printf("|");
            }
        }
        printf("\n");
        if(i<4){
            printf(" ---------");
            printf("\n");
        }
    }
}
int valid(int x,int y){
    if(x<0||x>=5||y<0||y>=5){
        return 0;
    }
    if(arr[x][y]!='-'){
        return 0;
    }
    return 1;
}
int end(){
    int i,j;
    for (i=0;i<5;i++) {
        if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]&&arr[i][2]==arr[i][3]&&arr[i][3]!='-'){
            return 1;
        }
        if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i]&&arr[2][i]==arr[3][i]&&arr[3][i]!='-'){
            return 1;
        }
    }
    if((arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[2][2]==arr[3][3]&&arr[3][3]!='-')||(arr[0][4]==arr[1][3]&&arr[1][3]==arr[2][2]&&arr[2][2]==arr[3][1]&&arr[3][1]!='-')){
        return 1;
    }
    return 0;
}
int toss(){
    srand(time(NULL));
    int toss1=rand()%2+1;
    return toss1;
}
int main(){
    printf("WELCOME TO 5x5 TIC-TAC-TOE!\nby Kingsuk Panda\n\n\nThis is your tic-tac-toe board:\n\n");
    startboard();
    print();
    printf("\n\nWhen asked for a position to play your move, enter the row and column for the position.\nWhen you score 4 consecutive Xs or Os, you win! Get ready for the game!!");
    printf("\n\n\nMODE: PLAYER VS PLAYER\n\nThe LUCK GODS have decided that ");
    int x,y;
    char currentplayer;
    int toss2=toss();
        if(toss2==1){
            currentplayer='X';
            printf("player X goes first!\n\nPlayer X, enter the position where you want to place your X:\nRow: ");
            scanf("%d",&x);
            printf("\nColumn:");
            scanf("%d",&y);
            x--;
            y--;
            arr[x][y]=currentplayer;
            currentplayer='O';
            while(!end()){
                print();
                printf("\nPlayer %c, enter the position where you want to place your %c:\nRow: ",currentplayer,currentplayer);
                scanf("%d",&x);
                printf("\nColumn: ");
                scanf("%d",&y);
                x--;
                y--;
                if(valid(x,y)){
                    arr[x][y]=currentplayer;
                    if(currentplayer=='O'){
                        currentplayer='X';
                    }
                    else{
                        currentplayer='O';
                    }
                }
                else{
                        printf("\nINVALID POSITION OR MOVE!");
                }   
            }
            print();
            if(end==0){
                printf("\nIt's a draw!!");
                return 0;
            }
            printf("\nPlayer %c wins!!",currentplayer);
        }
        else{
            currentplayer='O';
            printf("player O goes first!\n\nPlayer O, enter the position where you want to place your X:\nRow: ");
            scanf("%d",&x);
            printf("\nColumn:");
            scanf("%d",&y);
            x--;
            y--;
            arr[x][y]=currentplayer;
            currentplayer='X';
            while(!end()){
                print();
                printf("\nPlayer %c, enter the position where you want to place your %c:\nRow: ",currentplayer,currentplayer);
                scanf("%d",&x);
                printf("\nColumn: ");
                scanf("%d",&y);
                x--;
                y--;
                if(valid(x,y)){
                    arr[x][y]=currentplayer;
                    if(currentplayer=='O'){
                        currentplayer='X';
                    }
                    else{
                        currentplayer='O';
                    }
                }
                else{
                        printf("\nINVALID POSITION OR MOVE!");
                }   
            }
            print();
            if(end==0){
                printf("\nIt's a draw!!");
                return 0;
            }
            printf("\nPlayer %c wins!!",currentplayer);
        }
        return 0;
}
