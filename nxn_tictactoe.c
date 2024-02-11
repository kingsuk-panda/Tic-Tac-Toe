#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char arr[1000][1000];
void startboard(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr[i][j]='-';
        }
    }
}
void print(int n){
    printf("\nCurrent state of board:\n");
    int i,j,k;
    for(k=0;k<n;k++){
        printf(" %d",k+1);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d",i+1);
        for(j=0;j<n;j++){
            printf("%c",arr[i][j]);
            if(j<n-1){
                printf("|");
            }
        }
        printf("\n");
        if(i<n-1){
            printf(" ");
            for(k=0;k<(2*n)-1;k++){
                printf("-");
            }
            printf("\n");
        }
    }
}
int valid(int x,int y,int n){
    if(x<0||x>=n||y<0||y>=n){
        return 0;
    }
    if(arr[x][y]!='-'){
        return 0;
    }
    return 1;
}
int end(int n){
    int i,j;
    if(n>3){
        for(i=0;i<n;i++){
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
    }
    else if(n=3){
        for(i=0;i<n;i++){
            if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]&&arr[i][2]!='-'){
                return 1;
            }
            if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i]&&arr[2][i]!='-'){
                return 1;
            }
        }
        if((arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[2][2]!='-')||(arr[0][4]==arr[1][3]&&arr[1][3]==arr[2][2]&&arr[2][2]!='-')){
            return 1;
        }
    }
    else if(n=2){
        for(i=0;i<n;i++){
            if(arr[i][0]==arr[i][1]&&arr[i][1]!='-'){
                return 1;
            }
            if(arr[0][i]==arr[1][i]&&arr[1][i]!='-'){
                return 1;
            }
        }
        if((arr[0][0]==arr[1][1]&&arr[1][1]!='-')||(arr[0][4]==arr[1][3]&&arr[1][3]!='-')){
            return 1;
        }
    }
    else if(n=1){
        printf("\nOh so you wanna play 1x1? You can't really play TIC-TAC-TOE in a 1x1 can you hahaha!\n");
    }
    return 0;
}
int toss(){
    srand(time(NULL));
    int toss1=rand()%2+1;
    return toss1;
}
int main(){
  int n;
  printf("WELCOME TO TIC-TAC-TOE!\nby Kingsuk Panda\n\nYou can choose your own board!\nPlease enter your board size(for example: 3 for 3x3; 5 for 5x5; etc.): ");
  scanf("%d",&n);
  startboard(n);
  printf("\n\nThis is your board!\n");
  print(n);
  printf("\n\nWhen asked for a position to play your move, enter the row and column for the position.\nWhen you score 4 consecutive Xs or Os, you win! Get ready for the game!!\n\nSelect your game mode(type in the option number):\n1. Player vs Player\n2. Player vs Computer\n\nMode: ");
  int mode;
  scanf("%d",&mode);
  if(mode==1){
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
          while(!end(n)){
              print(n);
              printf("\nPlayer %c, enter the position where you want to place your %c:\nRow: ",currentplayer,currentplayer);
              scanf("%d",&x);
              printf("\nColumn: ");
              scanf("%d",&y);
              x--;
              y--;
              if(valid(x,y,n)){
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
          print(n);
          if(end(n)==0){
              printf("\nIt's a draw!!");
              return 0;
          }
          if(currentplayer=='X'){
            printf("\nPlayer O wins!!");
          }
          else{
            printf("\nPlayer X wins!!");
          }
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
          while(!end(n)){
              print(n);
              printf("\nPlayer %c, enter the position where you want to place your %c:\nRow: ",currentplayer,currentplayer);
              scanf("%d",&x);
              printf("\nColumn: ");
              scanf("%d",&y);
              x--;
              y--;
              if(valid(x,y,n)){
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
          print(n);
          if(end(n)==0){
              printf("\nIt's a draw!!");
              return 0;
          }
          if(currentplayer=='X'){
            printf("\nPlayer O wins!!");
          }
          else{
            printf("\nPlayer X wins!!");
          }
        }
  }
  else{
    printf("\n\n\nMODE: PLAYER (X) VS COMPUTER (O)\n\nThe LUCK GODS have decided that ");
    int x,y;
    char currentplayer;
    int toss2=toss();
    if(toss2==1){
        currentplayer='X';
        printf("player (X) goes first!\n\nPlayer, enter the position where you want to place your X:\nRow: ");
        scanf("%d",&x);
        printf("\nColumn:");
        scanf("%d",&y);
        x--;
        y--;
        arr[x][y]='X';
        currentplayer='O';
        while(!end(n)){
          print(n);
          if(currentplayer=='X'){
            printf("\nPlayer, enter the position where you want to place your X:\nRow: ");
            scanf("%d",&x);
            printf("\nColumn: ");
            scanf("%d",&y);
          }
          else{
            x=rand()%5+1;
            y=rand()%5+1;
            printf("\nComputer's move:\nRow: %d\nColumn: %d\n",x,y);
          }
          x--;
          y--;
          if(valid(x,y,n)){
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
        print(n);
        if(end(n)==0){
            printf("\nIt's a draw!!");
            return 0;
        }
        if(currentplayer=='O'){
          printf("\nPlayer wins!!");
        }
        else{
          printf("\nComputer wins!!");
        }
    }
    else{
      currentplayer='O';
      printf("Computer (O) goes first!");
      x=rand()%5+1;
      y=rand()%5+1;
      x--;
      y--;
      printf("\nComputer's move:\nRow: %d\nColumn: %d\n",x,y);
      arr[x][y]='O';
      print(n);
      currentplayer='X';
      while(!end(n)){
        if(currentplayer=='X'){
          printf("\nPlayer, enter the position where you want to place your %c:\nRow: ",currentplayer);
          scanf("%d",&x);
          printf("\nColumn: ");
          scanf("%d",&y);
        }
        else{
          x=rand()%5+1;
          y=rand()%5+1;
          printf("\nComputer's move:\nRow: %d\nColumn: %d\n",x,y);
        }
        x--;
        y--;
        if(valid(x,y,n)){
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
        print(n);
      }
      if(end(n)==0){
          printf("\nIt's a draw!!");
          return 0;
      }
      if(currentplayer=='O'){
        printf("\nPlayer wins!!");
      }
      else{
        printf("\nComputer wins!!");
      }
    }
  }
  return 0;
}