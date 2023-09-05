#include<iostream>

using namespace std;

vector<int>dp(10000,0);
int PerfectSquare(int n){
   if(n==0){
    return 0;
   }

   if(n<0){
    return INT_MAX;
   }

   if(dp[n]!=0){
    return dp[n];
   }

    int ans=INT_MAX;
   for( int i=1;i*i<=n;i++){
    int subProblem=PerfectSquare(n-i*i);
    if(ans>subProblem+1){
        ans=subProblem+1;
    }
   }

   return dp[n]=ans;
}


int PerfectSquareBottomUp(int n){
    vector<int>dp(n+1,INT_MAX);

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
   for( int i=3;i<=n;i++){
     for(int j=1;j*j<=i;j++){
        if(i-j*j>=0){
        dp[i]=min(dp[i],1+dp[i-j*j]);
        }
     }
   }


   return dp[n];
}
int main(){
    int n;
    vector<int>dp(n,0);
    cin>>n;
    cout<<PerfectSquareBottomUp(n)<<endl;
}