#include<iostream>
#include<vector>

using namespace std;

int box(vector<vector<int> >&v, vector<int>&dp){
    //sort the vector v according to length

    for(int i=0;i<v.size();i++){
        dp[i]=v[i][2];
        int h=v[i][1];
        int l=v[i][2];
        int w=v[i][0];
        for(int j=i-1;j>=0;j--){
            if(w>v[j][0] && h>v[j][1] && l>v[j][2]){
                dp[i]+=v[j][2];
                w=v[j][0];h=v[j][1];l=v[j][2];
            }
        }
    }

   int ans=0;
    for(int i=0;i<dp.size()-1;i++){
        cout<<dp[i]<<endl;
            ans=max(ans,dp[i]);
    }

return ans;
}
int main(){
    vector<vector<int> >v;
   
    v.push_back(vector<int> {2,2,1});
    v.push_back(vector<int> {2,1,2});
    
     v.push_back(vector<int> {3,2,3});
     v.push_back(vector<int> {2,3,4}); 
      v.push_back(vector<int> {4,4,5});
       v.push_back(vector<int> {2,2,8}); 
        vector<int>dp(v.size()+1,0);
    cout << box(v,dp)<<endl;
}