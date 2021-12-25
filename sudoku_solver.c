//A program to solve Sudoku puzzles.
//Oct-2020

#include <stdio.h>
#include <stdbool.h>

void input(int sudoku[9][9]){
  printf("Enter numbers to be filled as '0'..give space between each number and press enter after each line\n");
  printf("Enter your puzzle below \n");
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++) scanf("%d",&sudoku[i][j]);
    getchar();
  }
  printf("\n\nThe Solved Puzzle : \n");
}

void output(int sudoku[9][9]){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++) printf(" %d ",sudoku[i][j]);
    printf("\n");
  }
}

bool safe(int sudoku[9][9],int row,int column,int value){
  bool row_check=true,col_check=true,submatrix_check=true;
  int i,j;
  for(j=0;j<9;j++)
   if(sudoku[row][j]==value) row_check=false;
  for(i=0;i<9;i++)
   if(sudoku[i][column]==value) col_check=false;
  for(i=0;i<3;i++)
   for(j=0;j<3;j++)
    if(sudoku[i+(row-(row%3))][j+(column-(column%3))]==value)
      submatrix_check=false;
  if(row_check==true&&col_check==true&&submatrix_check==true)
  return true;else return false;
}

bool solve(int sudoku[9][9],int row,int column){
  if(row==8&&column==9)return true;
  if(column==9){row++;column=0;}
  if(sudoku[row][column]>0){++column;return solve(sudoku,row,column);}
  for(int value=1;value<=9;value++){
	  if(safe(sudoku,row,column,value)){
			sudoku[row][column]=value;++column;
			if(solve(sudoku,row,column))return true;else{
        if(column==0){--row;column=8;}
        else --column;
      }
		}
		sudoku[row][column]=0;
	}
	return false;
}

int main(void){
 int sudoku[9][9];
 input(sudoku);
 if(!solve(sudoku,0,0)){
   printf("\n\nCan't be Solved!!\n\n");
   return 0;
 }
 output(sudoku);
 return 0;
}
