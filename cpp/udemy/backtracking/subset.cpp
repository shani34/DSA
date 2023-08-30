#include<iostream>
#include<vector>

using namespace std;

vector<vector< int> >ans;
void Subset(int n, vector<int>v, vector<int>nums, int ind){
        ans.push_back(v);
    

    for(int i=ind;i<n;i++){
        v.push_back(nums[i]);
        Subset(n,v,nums,i+1);
        v.pop_back();
    }
  
  return ;
}

void SubsetTwo(int n, vector<int>v, vector<int>nums,int ind){
    if(ind==n){
        ans.push_back(v);
        return;
    }

    SubsetTwo(n,v,nums,ind+1);
    v.push_back(nums[ind]);
    SubsetTwo(n,v,nums,ind+1);
}
int main(){
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<int>v;
    Subset(3,v,nums,0);
    SubsetTwo(3,v,nums,0);
    for( int i=0;i<ans.size();i++){

        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}