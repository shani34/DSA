#include<iostream>

using namespace std;

void permute(int ind, vector<int>nums, vector<int>temp,vector<vector<int> >&ans,vector<int>&vis){
 if(temp.size()==nums.size()){
    ans.push_back(temp);
    return;
 }


for(int i=0;i<nums.size();i++){
        if(!vis[i]){
            vis[i]=1;
            temp.push_back(nums[i]);
            permute(i+1,nums,temp,ans,vis);
            temp.pop_back();
            vis[i]=0;
        }
    }
}

int main(){
    vector<int>nums;
    vector<int>temp;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<int>vis(3,0);
    vector<vector<int> >ans;
   permute(0,nums,temp,ans,vis);
    for( int i=0;i<ans.size();i++){

        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}