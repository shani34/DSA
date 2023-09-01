#include <iostream>
#include <vector>  // You were missing this header

using namespace std;

int nkLadder(int n, int k, vector<int>& dp) {  // Pass dp by reference
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int ans = 0;
    for (int j = 1; j <= k; j++) {  // Start from j = 1, not j = 0
        ans += nkLadder(n - j, k, dp);
    }

    return dp[n] = ans;
}

int nkLadderBottomUp(int n, int k) { 
vector<int>dp(n+1,0);
   dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    }

    return dp[n];
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> dp(n+1, 0);
    cout << nkLadder(n, k, dp) << endl;
     cout << nkLadderBottomUp(n, k) << endl;
    return 0;
}
