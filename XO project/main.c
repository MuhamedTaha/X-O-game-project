#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
 int digits[9] = {0,0,0,0,0,0,0,0,0};
 char xo;
 int numb=0;
COORD coord = {0, 0};  // sets coordinates to (0,0) as global variables
void gotoxy(int x,int y)// a function controls the coordenates of the outputs
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void draw_board()
{   gotoxy(33,0);
    printf("WELCOME!");
    gotoxy(20,3);
    printf("1st player'X'       2nd player'O'");
    int j;

    for(j=8; j<16; j++)
    {
        gotoxy(24,j);
        printf("|       |       |       |");
    }
    gotoxy(25,10);
    printf("-----------------------");
    gotoxy(25,13);
    printf("-----------------------");
    gotoxy(24,16);
    printf("-------------------------");
     gotoxy(24,7);
    printf("-------------------------");

}
int xoro (int m)
{
    if(xo == 'X'){ m=1;}
    else if (xo == 'O') {m=2;}
    return (m);
}
int check(int ply)
{
    int i=0;
    switch(ply){
case 7 :
    if(digits[6]==0){
    digits[6]=xoro(i);
    gotoxy(28,9);
    printf("%c", xo);
    numb++;
      }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
case 4 :
 if(digits[3]==0){
    digits[3]=xoro(i);
    gotoxy(28,12);
    printf("%c", xo);
    numb++;
        }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
 case 1 :
    if(digits[0]==0){
    digits[0]=xoro(i);
    gotoxy(28,15);
    printf("%c", xo);
    numb++;
        }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
 case 2 :
    if(digits[1]==0){
    digits[1]=xoro(i);
    gotoxy(36,15);
    printf("%c", xo);
    numb++;
        }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
 case 5 :
    if(digits[4]==0){
    digits[4]=xoro(i);
    gotoxy(36,12);
    printf("%c", xo);
    numb++;
       }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
 case 8 :
    if(digits[7]==0){
    digits[7]=xoro(i);
    gotoxy(36,9);
    printf("%c", xo);
    numb++;
        }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
 case 9 :
    if(digits[8]==0){
    digits[8]=xoro(i);
    gotoxy(44,9);
    printf("%c", xo);
    numb++;
      }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
 case 6 :
    if(digits[5]==0){
    digits[5]=xoro(i);
    gotoxy(44,12);
    printf("%c", xo);
    numb++;
    }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;
 case 3 :
    if(digits[2]==0){
    digits[2]=xoro(i);
    gotoxy(44,15);
    printf("%c", xo);
    numb++;
       }else{ if(xo== 'O'){ play2();}
           else if(xo== 'X'){ play1(); }}
    break;

 default :
    play1();}

 gotoxy(36,18);
}


void win()
{ int i;
if(digits[0]*digits[4]*digits[8]==1 || digits[6]*digits[4]*digits[2]==1 || digits[0]*digits[4]*digits[8]==8 || digits[6]*digits[4]*digits[2]==8 )
{
    winner();
}
for(i=0;i<9;i+=3)
{
 if( digits[i]*digits[i+1]*digits[i+2] == 1 ||  digits[i]*digits[i+1]*digits[i+2] == 8)
    {winner();}
}
for(i=6;i<9;i++)
{
  if( digits[i]*digits[i-3]*digits[i-6] == 1 || digits[i]*digits[i-3]*digits[i-6] == 8)
    {winner();}
}
}


void winner()
{   gotoxy(30,21);
    if ( xo=='X')
    {
        printf("1ST PLAYER WINS!!\n");
    }
    else if (xo == 'O')
    {
    printf("2ST PLAYER WINS!!\n");
    }
    exit(0);
}
void play1 (){
int ply1;
    gotoxy(36,18);
    scanf("%i",&ply1);
    xo = 'X';
    check(ply1);
    win();
    drw();
    play2();}

void play2(){
        int ply2;
        gotoxy(36,18);
      scanf("%i",&ply2);
    xo='O';
    check(ply2);
    win();
     drw();
        play1();

}
void drw()
{
    if(numb == 9){
        gotoxy(32,21);
    printf("GAME DRAW!!\n");
            exit(0); }
}

int main()
{
    draw_board();
    play1();
    return 0;
}
