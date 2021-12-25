// A computer Tic-tac-toe player
// Oct-2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const char bot='O',human='X'; int moves=0;

void displayGame(char tic[3][3]){
    printf("      0    1    2   \n");
    printf("     ___ ___ ___\n");
    printf("0   | %c | %c | %c |\n",tic[0][0],tic[0][1],tic[0][2]);
    printf("    |---+---+---|\n");
    printf("1   | %c | %c | %c |\n",tic[1][0],tic[1][1],tic[1][2]);
    printf("    |---+---+---|\n");
    printf("2   | %c | %c | %c |\n",tic[2][0],tic[2][1],tic[2][2]);
    printf("    |___|___|___|\n\n");
    return;
}

void userInput(char tic[3][3]){
  int x,y;
  a_case:{
   displayGame(tic);
   printf("Give Input coordinates (x,y) : ");
   scanf("%d,%d",&x,&y);
   getchar();//purge new-line
   if((x>2)||(y>2)||(x<0)||(y<0)){
    printf("Illegal Input: Program Terminated");
    exit(1);
  }
  }
  if(tic[x][y]!=' '){
    printf("Already Occupied!!Try Again..\n");
    goto a_case;
  }
  else{
   tic[x][y]=human;++moves;
   displayGame(tic);
  }
  return;
}

bool winConditions(char tic[3][3],char play){
 if (
  (tic[0][0] == play && tic[0][1] == play && tic[0][2] == play) ||
  (tic[1][0] == play && tic[1][1] == play && tic[1][2] == play) ||
  (tic[2][0] == play && tic[2][1] == play && tic[2][2] == play) ||
  (tic[0][0] == play && tic[1][0] == play && tic[2][0] == play) ||
  (tic[0][1] == play && tic[1][1] == play && tic[2][1] == play) ||
  (tic[0][2] == play && tic[1][2] == play && tic[2][2] == play) ||
  (tic[0][0] == play && tic[1][1] == play && tic[2][2] == play) ||
  (tic[0][2] == play && tic[1][1] == play && tic[2][0] == play)
    ) return true;
 else return false;
}

bool BlockWin(char tic[3][3]){
    if((tic[0][0]==tic[0][1])&&tic[0][2]==' '&&tic[0][0]==bot){
      tic[0][2]=bot;++moves;return true;
    }else
    if((tic[0][1]==tic[0][2])&&tic[0][0]==' '&&tic[0][1]==bot){
      tic[0][0]=bot;++moves;return true;
    }else
    if((tic[0][0]==tic[0][2])&&tic[0][1]==' '&&tic[0][0]==bot){
      tic[0][1]=bot;++moves;return true;
    }else
    if((tic[1][0]==tic[1][1])&&tic[1][2]==' '&&tic[1][0]==bot){
      tic[1][2]=bot;++moves;return true;
    }else
    if((tic[1][1]==tic[1][2])&&tic[1][0]==' '&&tic[1][1]==bot){
      tic[1][0]=bot;++moves;return true;
    }else
    if((tic[1][0]==tic[1][2])&&tic[1][1]==' '&&tic[1][0]==bot){
      tic[1][1]=bot;++moves;return true;
    }else
    if((tic[2][0]==tic[2][1])&&tic[2][2]==' '&&tic[2][0]==bot){
      tic[2][2]=bot;++moves;return true;
    }else
    if((tic[2][1]==tic[2][2])&&tic[2][0]==' '&&tic[2][1]==bot){
      tic[2][0]=bot;++moves;return true;
    }else
    if((tic[2][0]==tic[2][2])&&tic[2][1]==' '&&tic[2][0]==bot){
      tic[2][1]=bot;++moves;return true;
    }else
    if((tic[0][0]==tic[1][0])&&tic[2][0]==' '&&tic[0][0]==bot){
      tic[2][0]=bot;++moves;return true;
    }else
    if((tic[0][0]==tic[2][0])&&tic[1][0]==' '&&tic[0][0]==bot){
      tic[1][0]=bot;++moves;return true;
    }else
    if((tic[1][0]==tic[2][0])&&tic[0][0]==' '&&tic[1][0]==bot){
      tic[0][0]=bot;++moves;return true;
    }else
    if((tic[0][1]==tic[1][1])&&tic[2][1]==' '&&tic[0][1]==bot){
      tic[2][1]=bot;++moves;return true;
    }else
    if((tic[0][1]==tic[2][1])&&tic[1][1]==' '&&tic[0][1]==bot){
      tic[1][1]=bot;++moves;return true;
    }else
    if((tic[1][1]==tic[2][1])&&tic[0][1]==' '&&tic[1][1]==bot){
      tic[0][1]=bot;++moves;return true;
    }else
    if((tic[0][2]==tic[1][2])&&tic[2][2]==' '&&tic[0][2]==bot){
      tic[2][2]=bot;++moves;return true;
    }else
    if((tic[0][2]==tic[2][2])&&tic[1][2]==' '&&tic[0][2]==bot){
      tic[1][2]=bot;++moves;return true;
    }else
    if((tic[1][2]==tic[2][2])&&tic[0][2]==' '&&tic[1][2]==bot){
      tic[0][2]=bot;++moves;return true;
    }else
  if((tic[0][0]==tic[1][1])&&tic[2][2]==' '&&tic[0][0]==bot){
    tic[2][2]=bot;++moves;return true;
  }else
  if((tic[0][0]==tic[2][2])&&tic[1][1]==' '&&tic[0][0]==bot){
    tic[1][1]=bot;++moves;return true;
  }else
  if((tic[1][1]==tic[2][2])&&tic[0][0]==' '&&tic[1][1]==bot){
    tic[0][0]=bot;++moves;return true;
  }else
  if((tic[0][2]==tic[1][1])&&tic[2][0]==' '&&tic[1][1]==bot){
    tic[2][0]=bot;++moves;return true;
  }else
  if((tic[2][0]==tic[0][2])&&tic[1][1]==' '&&tic[2][0]==bot){
    tic[1][1]=bot;++moves;return true;
  }else
  if((tic[2][0]==tic[1][1])&&tic[0][2]==' '&&tic[2][0]==bot){
    tic[0][2]=bot;++moves;return true;
  }else
  if((tic[0][0]==tic[0][1])&&tic[0][2]==' '&&tic[0][0]==human){
    tic[0][2]=bot;++moves;return true;
  }else
  if((tic[0][1]==tic[0][2])&&tic[0][0]==' '&&tic[0][1]==human){
    tic[0][0]=bot;++moves;return true;
  }else
  if((tic[0][0]==tic[0][2])&&tic[0][1]==' '&&tic[0][0]==human){
    tic[0][1]=bot;++moves;return true;
  }else
  if((tic[1][0]==tic[1][1])&&tic[1][2]==' '&&tic[1][0]==human){
    tic[1][2]=bot;++moves;return true;
  }else
  if((tic[1][1]==tic[1][2])&&tic[1][0]==' '&&tic[1][1]==human){
    tic[1][0]=bot;++moves;return true;
  }else
  if((tic[1][0]==tic[1][2])&&tic[1][1]==' '&&tic[1][0]==human){
    tic[1][1]=bot;++moves;return true;
  }else
  if((tic[2][0]==tic[2][1])&&tic[2][2]==' '&&tic[2][0]==human){
    tic[2][2]=bot;++moves;return true;
  }else
  if((tic[2][1]==tic[2][2])&&tic[2][0]==' '&&tic[2][1]==human){
    tic[2][0]=bot;++moves;return true;
  }else
  if((tic[2][0]==tic[2][2])&&tic[2][1]==' '&&tic[2][0]==human){
    tic[2][1]=bot;++moves;return true;
  }else
  if((tic[0][0]==tic[1][0])&&tic[2][0]==' '&&tic[0][0]==human){
    tic[2][0]=bot;++moves;return true;
  }else
  if((tic[0][0]==tic[2][0])&&tic[1][0]==' '&&tic[0][0]==human){
    tic[1][0]=bot;++moves;return true;
  }else
  if((tic[1][0]==tic[2][0])&&tic[0][0]==' '&&tic[1][0]==human){
    tic[0][0]=bot;++moves;return true;
  }else
  if((tic[0][1]==tic[1][1])&&tic[2][1]==' '&&tic[0][1]==human){
    tic[2][1]=bot;++moves;return true;
  }else
  if((tic[0][1]==tic[2][1])&&tic[1][1]==' '&&tic[0][1]==human){
    tic[1][1]=bot;++moves;return true;
  }else
  if((tic[1][1]==tic[2][1])&&tic[0][1]==' '&&tic[1][1]==human){
    tic[0][1]=bot;++moves;return true;
  }else
  if((tic[0][2]==tic[1][2])&&tic[2][2]==' '&&tic[0][2]==human){
    tic[2][2]=bot;++moves;return true;
  }else
  if((tic[0][2]==tic[2][2])&&tic[1][2]==' '&&tic[0][2]==human){
    tic[1][2]=bot;++moves;return true;
  }else
  if((tic[1][2]==tic[2][2])&&tic[0][2]==' '&&tic[1][2]==human){
    tic[0][2]=bot;++moves;return true;
  }else
if((tic[0][0]==tic[1][1])&&tic[2][2]==' '&&tic[0][0]==human){
  tic[2][2]=bot;++moves;return true;
}else
if((tic[0][0]==tic[2][2])&&tic[1][1]==' '&&tic[0][0]==human){
  tic[1][1]=bot;++moves;return true;
}else
if((tic[1][1]==tic[2][2])&&tic[0][0]==' '&&tic[1][1]==human){
  tic[0][0]=bot;++moves;return true;
}else
if((tic[0][2]==tic[1][1])&&tic[2][0]==' '&&tic[1][1]==human){
  tic[2][0]=bot;++moves;return true;
}else
if((tic[2][0]==tic[0][2])&&tic[1][1]==' '&&tic[2][0]==human){
  tic[1][1]=bot;++moves;return true;
}else
if((tic[2][0]==tic[1][1])&&tic[0][2]==' '&&tic[2][0]==human){
  tic[0][2]=bot;++moves;return true;
}else
  return false;
}

void BotFirstMoveFour(char tic[3][3]){
  int q=moves;
   if(moves==q&&tic[0][0]==bot&&tic[0][2]==bot&&tic[1][1]==' '&&((tic[2][2]==' '&&tic[1][2]==' ')||(tic[2][0]==' '&&tic[1][0]==' '))){
     tic[1][1]=bot;++moves;
   }else
   if(moves==q&&tic[0][0]==bot&&tic[2][0]==bot&&tic[1][1]==' '&&((tic[0][2]==' '&&tic[2][2]==' ')||(tic[2][2]==' '&&tic[2][1]==' '))){
     tic[1][1]=bot;++moves;
   }else
   if(moves==q&&tic[0][0]==bot&&tic[2][2]==bot&&tic[1][0]==' '&&tic[2][1]==' '&&tic[2][0]==' '){
     tic[2][0]=bot;++moves;
   }else
   if(moves==q&&tic[0][0]==bot&&tic[2][2]==bot&&tic[0][2]==' '&&tic[0][1]==' '&&tic[1][2]==' '){
     tic[0][2]=bot;++moves;
   }else
   if(moves==q&&tic[2][2]==bot&&tic[2][0]==bot&&tic[1][1]==' '&&((tic[0][2]==' '&&tic[1][2]==' ')||(tic[0][0]==' '&&tic[1][0]==' '))){
     tic[1][1]=bot;++moves;
   }else
   if(moves==q&&tic[2][2]==bot&&tic[0][2]==bot&&tic[1][1]==' '&&((tic[0][0]==' '&&tic[0][1]==' ')||(tic[2][1]==' '&&tic[2][0]==' '))){
     tic[1][1]=bot;++moves;
   }else
   if(moves==q&&tic[2][0]==bot&&tic[0][2]==bot&&tic[2][2]==' '&&tic[2][1]==' '&&tic[1][2]==' '){
     tic[2][2]=bot;++moves;
   }else
   if(moves==q&&tic[2][0]==bot&&tic[0][2]==bot&&tic[0][0]==' '&&tic[0][1]==' '&&tic[1][0]==' '){
     tic[0][0]=bot;++moves;
   }else{
     for(int d=0;d<3;d++){
       for(int o=0;o<3;o++){
         if(tic[d][o]==' '){
           tic[d][o]=bot;++moves;return;}}}
   }

}

void BotMoveFirst(char tic[3][3]){
  if(moves==0){
   srand(time(NULL));
   int q= rand()%4+1;
   if(q==1) tic[0][0]=bot;
   else if(q==2) tic[0][2]=bot;
   else if(q==3) tic[2][0]=bot;
   else if(q==4) tic[2][2]=bot;
   ++moves;return;
  }
  if(moves==2){
    if(tic[1][1]==human){
      srand(time(NULL));
      int q=rand()%2+1;
      if(q==1&&moves==2&&tic[0][0]==bot) {tic[2][2]=bot;++moves;}
      if(q==1&&moves==2&&tic[0][2]==bot) {tic[2][0]=bot;++moves;}
      if(q==1&&moves==2&&tic[2][0]==bot) {tic[0][2]=bot;++moves;}
      if(q==1&&moves==2&&tic[2][2]==bot) {tic[0][0]=bot;++moves;}
      if(q==2&&moves==2&&(tic[0][0]==bot||tic[2][0]==bot)) {tic[1][2]=bot;++moves;}
      if(q==2&&moves==2&&(tic[0][2]==bot||tic[2][2]==bot)) {tic[1][0]=bot;++moves;}
    }
    else {
      if(tic[0][0]==bot){
        if(moves==2&&tic[0][1]==' '&&tic[0][2]==' '){tic[0][2]=bot;++moves;}
        if(moves==2&&tic[1][0]==' '&&tic[2][0]==' '){tic[2][0]=bot;++moves;}
        if(moves==2&&tic[2][2]==' '){tic[2][2]=bot;++moves;}
      }else
      if(tic[0][2]==bot){
        if(moves==2&&tic[0][1]==' '&&tic[0][0]==' '){tic[0][0]=bot;++moves;}
        if(moves==2&&tic[2][0]==' '){tic[2][0]=bot;++moves;}
        if(moves==2&&tic[1][2]==' '&&tic[2][2]==' '){tic[2][2]=bot;++moves;}
      }else
      if(tic[2][0]==bot){
        if(moves==2&&tic[0][2]==' '){tic[0][2]=bot;++moves;}
        if(moves==2&&tic[0][0]==' '&&tic[1][0]==' '){tic[0][0]=bot;++moves;}
        if(moves==2&&tic[2][2]==' '&&tic[2][1]==' '){tic[2][2]=bot;++moves;}
      }else
      if(tic[2][2]==bot){
        if(moves==2&&tic[2][1]==' '&&tic[2][0]==' '){tic[2][0]=bot;++moves;}
        if(moves==2&&tic[1][2]==' '&&tic[0][2]==' '){tic[0][2]=bot;++moves;}
        if(moves==2&&tic[0][0]==' '){tic[0][0]=bot;++moves;}
      }
      return;
  }

 }
  if(moves==4){
   int x=BlockWin(tic);
   if(x==false) BotFirstMoveFour(tic);
   return;
 }
  if(moves==6) {int zx=BlockWin(tic);
       if(zx==false){
         for(int a=0;a<3;a++){
           for(int y=0;y<3;y++){
             if(tic[a][y]==' '){
               tic[a][y]=bot;++moves;return;
       }
  }
 }
}
}
}

bool casecheck=false;
void BotMoveSecond(char tic[3][3]){
  if(moves==1){
    if(tic[1][1]!=human){
    tic[1][1]=bot;++moves;
     }
    else{
     srand(time(NULL));
     int z= rand()%4+1;
     if(z==1) tic[0][0]=bot;
     else if(z==2) tic[0][2]=bot;
     else if(z==3) tic[2][0]=bot;
     else if(z==4) tic[2][2]=bot;
     ++moves;return;
      }
  }
  if(moves==3){
   int q=BlockWin(tic);
   if(q==false&&tic[1][1]==bot){
     if((tic[0][1]==human&&tic[2][1]==human)||(tic[1][0]==human&&tic[1][2]==human)){
       srand(time(NULL));
       int e= rand()%4+1;
       if(e==1) tic[0][0]=bot;
       else if(e==2) tic[0][2]=bot;
       else if(e==3) tic[2][0]=bot;
       else if(e==4) tic[2][2]=bot;
       casecheck=true;++moves;return;
     }
   }else
   if(q==false){
    if(tic[1][1]==bot){
     if(tic[0][1]==' '){
      tic[0][1]=bot;++moves;return;
       }
      if(tic[2][1]==' '){
       tic[2][1]=bot;++moves;return;
        }
      if(tic[1][0]==' '){
       tic[1][0]=bot;++moves;return;
        }
      if(tic[1][2]==' '){
       tic[1][2]=bot;++moves;return;
        }
       }
     }
 }
  if(moves==3){
   if(tic[1][1]==human){
     srand(time(NULL));
     int g=rand()%2+1;
     if((tic[0][0]==human&&tic[2][2]==bot)||(tic[2][2]==human&&tic[0][0]==bot)){
       if(g==1){tic[2][0]=bot;++moves;return;}
       if(g==2){tic[0][2]=bot;++moves;return;}
     }
     if((tic[2][0]==human&&tic[0][2]==bot)||(tic[0][2]==human&&tic[2][0]==bot)){
       if(g==1){tic[2][2]=bot;++moves;return;}
       if(g==2){tic[0][0]=bot;++moves;return;}
     }
   }
 }
  if(moves==3){
   if(tic[1][1]==bot){
     if(tic[0][0]==human&&tic[2][2]==' '&&tic[0][2]==' '&&tic[2][0]==' '){tic[2][2]=bot;++moves;return;}
     if(tic[2][2]==human&&tic[0][0]==' '&&tic[0][2]==' '&&tic[2][0]==' '){tic[0][0]=bot;++moves;return;}
     if(tic[2][0]==human&&tic[0][2]==' '&&tic[0][0]==' '&&tic[2][2]==' '){tic[0][2]=bot;++moves;return;}
     if(tic[0][2]==human&&tic[2][0]==' '&&tic[0][0]==' '&&tic[2][2]==' '){tic[2][0]=bot;++moves;return;}
   }
 }
  if(moves==3&&tic[1][1]==bot){
    srand(time(NULL));
    int gi=rand()%2+1;
    if(tic[0][0]==human&&tic[2][2]==human){
      if(gi==1){tic[0][1]=bot;++moves;return;}
      if(gi==2){tic[2][1]=bot;++moves;return;}
    }
    if(tic[2][0]==human&&tic[0][2]==human){
      if(gi==1){tic[1][0]=bot;++moves;return;}
      if(gi==2){tic[1][2]=bot;++moves;return;}
    }
  }
  if(moves==5){
    if(casecheck==true){
    for(int j=0;j<3;j++){
     if(tic[0][j]==human&&tic[1][j]==human&&tic[2][j]==' '){
      tic[2][j]=bot;++moves;return;
     }
     if(tic[1][j]==human&&tic[2][j]==human&&tic[0][j]==' '){
      tic[0][j]=bot;++moves;return;
     }
     if(tic[j][0]==human&&tic[j][1]==human&&tic[j][2]==' '){
       tic[j][2]=bot;++moves;return;
     }
     if(tic[j][2]==human&&tic[j][1]==human&&tic[j][0]==' '){
       tic[j][0]=bot;++moves;return;
     }
    }
   }
    else
    if(BlockWin(tic)==false){
      for(int d=0;d<3;d++){
        for(int o=0;o<3;o++){
          if(tic[d][o]==' '){
            tic[d][o]=bot;++moves;return;}}}
      }
  }
  if(moves==7){
    int bw=BlockWin(tic);
    if(bw==false){
      for(int d=0;d<3;d++){
        for(int o=0;o<3;o++){
          if(tic[d][o]==' '){
            tic[d][o]=bot;++moves;return;
          }
        }
      }
    }
  }
}

int main(void){
 char tic[3][3],q;int h,b;
 for(int w=0;w<3;w++){for(int e=0;e<3;e++)tic[w][e]=' ';}
  // "do u want to start first" loop ; q= y/n;
 while(1){
  printf("Player - X    Bot - O\n");
  printf("Do you want to start first? (y/n) :");
  scanf("%c",&q);
  getchar();//purge new-line
  if((q=='y')||(q=='n'))break;
  if((q!='y')||(q!='n'))printf("Illegal Input \n");
}

 if(q=='y'){
  while(1){
   userInput(tic);
   h=winConditions(tic,human);
   b=winConditions(tic,bot);
   if(h==true) {printf("\nYou Won\n");break;}
   if(b==true) {printf("\nBot Won\n");break;}
   if(moves==8) {printf("\nIt's a Draw\n");break;}
   BotMoveSecond(tic);
   h=winConditions(tic,human);
   b=winConditions(tic,bot);
   if(h==true) {printf("\nYou Won\n");break;}
   if(b==true) {printf("\nBot Won\n");break;}
   if(moves==8) {printf("\nIt's a Draw\n");break;}
  }
}
 if(q=='n'){
   while(1){
   BotMoveFirst(tic);
   h=winConditions(tic,human);
   b=winConditions(tic,bot);
   if(h==true) {printf("\nYou Won\n");break;}
   if(b==true) {printf("\nBot Won\n");break;}
   if(moves==8) {printf("\nIt's a Draw\n");break;}
   userInput(tic);
   h=winConditions(tic,human);
   b=winConditions(tic,bot);
   if(h==true) {printf("\nYou Won\n");break;}
   if(b==true) {printf("\nBot Won\n");break;}
   if(moves==8) {printf("\nIt's a Draw\n");break;}
  }
 }
  return 0;
}
