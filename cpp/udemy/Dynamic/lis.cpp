#include<iostream>


using namespace std;

int LIS(vector<int>nums,vector<int>&dp){

    for(int i=0;i<nums.size();i++){
        dp[i]=1;
        for(int j=i;j>=0;j--){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    int ans=0;
    for(int i=0;i<dp.size();i++){
         ans=max(ans, dp[i]);
    }

    return ans;
}

int main(){
    vector<int>nums;
    nums.push_back(50);
     nums.push_back(4);
     nums.push_back(10); 
     nums.push_back(8); 
      nums.push_back(30);
     nums.push_back(100);  
    vector<int>dp(nums.size()+1,0);
    cout<<LIS(nums,dp)<<endl;
}