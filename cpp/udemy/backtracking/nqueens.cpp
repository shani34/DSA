#include<iostream>

using namespace std;

void print(int n, int board[][20]){
    for( int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout <<endl;
    }
      cout <<endl;
}

bool canPlace(int board[][20], int i, int j,int n){

//column
for(int k=0;k<i;k++){
   if(board[k][j]==1){
    return false;
   }
}

//left diagonal

int x=i;
int y=j;
while(i>=0 &&j>=0){
  if(board[i][j]==1){
    return false;
  }
  i--;j--;
}

while(i>=0 &&j<n){
  if(board[i][j]==1){
    return false;
  }
  i--,j++;
}

return true;
}
bool nqueens(int n, int board[][20], int i){
    //base case
 if(i==n){
    print(n,board);
    return true;
 }

 //rec case  try all possibility

   for(int j=0;j<n;j++){
    //check safity whether i,j or safe to place or not
      if(canPlace(board,i,j,n)){
        board[i][j]=1;
        bool success=nqueens(n,board,i+1);
        if(success){
            return true;
        }
        //backtrack 
        board[i][j]=0;
      }
   }
   return false;
}
int main(){
 int board[20][20]={0};
 int n;
 cin>>n;
 nqueens(n,board,0);
 return 0;
}