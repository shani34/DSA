#include<iostream>

using namespace std;

int catalan(int n, vector<int>dp){
    if(n==0 ||n==1){
        return 1;
    }

    if(dp[n]!=0){
        return dp[n];
    }
     int ans=0;
    for(int i=1;i<=n;i++){
        int x=catalan(i-1,dp);
        int y=catalan(n-i,dp);
        ans+=x*y;
    }

    return dp[n]=ans;
}
int main(){
    int n;

    
    while(true){
        cin>>n;
        vector<int>dp(n+1,0);
   cout<<catalan(n,dp)<<endl;
    }

}