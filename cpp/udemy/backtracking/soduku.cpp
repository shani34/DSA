#include<iostream>

using namespace std;

bool isSafe(int mat[][9], int i, int j, int num,int n){
    //check row and column
    for(int k=0;k<9;k++){
        if(mat[k][j]==num||mat[i][k]==num){
            return false;
        }
    }

    //find starting point oof subgrid  
    int sx=(i/3)*3;
    int sy=(j/3)*3;

    for(int x=sx;x<sx+3;x++){
          for(int y=sy;y<sy+3;y++){
            if(mat[x][y]==num){
                return false;
            }
          }
    }

    return true;
}
bool solve(int mat[][9],int i, int j, int n){
    //base case
    if(i==n){
        //print the solution
        for( int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
//rec case
    if(j==n){
        return solve(mat,i+1,0,n);
    }
    //if mat is prefilled
  if(mat[i][j]!=0){
    return solve(mat,i,j+1,n);
  }
    //cell to be filled
    //try out all possibility 

  for(int num=1;num<=9;num++){
        //check whether its safe or not
    if(isSafe(mat,i,j,num,n)){
        mat[i][j]=num;
        bool subProblem=solve(mat,i,j+1,n);
        if(subProblem==true){
            return true;
        }  
    }
  }
    //if no option works go back and undo
  mat[i][j]=0;
  return false;
}
int main(){
int n=9;
int mat[9][9]={
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    solve(mat,0,0,n) ;
}