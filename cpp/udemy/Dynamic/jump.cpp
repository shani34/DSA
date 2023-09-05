#include<iostream>

using namespace std;

int minJump(vector<int>jump, int index, vector<int>dp){
    if(index==jump.size()-1){
        return 0;
    }

    if(index>=jump.size()-1){
        return INT_MAX;
    }

    if(dp[index]!=0){
        return dp[index];
    }
    int count=INT_MAX;

    for(int i=1;i<=jump[index];i++){
         int next_cell=i+index;
         int subProblem=minJump(jump,next_cell, dp);
         if(subProblem!=INT_MAX){
            count=min(count,subProblem+1);
         }
    }

    return dp[index]=count;
}
int main(){
    vector<int>jump;
    jump.push_back(3);
    jump.push_back(4);
    jump.push_back(2);
    jump.push_back(1);
    jump.push_back(2);
     jump.push_back(3);
      jump.push_back(10);
       jump.push_back(1);
     jump.push_back(1);
     jump.push_back(1);
      jump.push_back(2);
      jump.push_back(5);     
      vector<int>dp(jump.size(),0);
    cout<<minJump(jump,0,dp)<<endl;
}