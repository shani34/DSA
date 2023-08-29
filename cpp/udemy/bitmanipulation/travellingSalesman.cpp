#include<iostream>
#include<vector>
using namespace std;


int TravellingSalesman(vector<vector <int> >dist, int city,int setofCities, int n, vector<vector<int> >&dp){
// base condition
 if (setofCities==(1<<n)-1){
    return dist[city][0];
 }

if(dp[setofCities][city]!=-1){
   return dp[setofCities][city];
}
int ans=INT_MAX;
 //explore all possibility
 for(int choice=0;choice<n;choice++){
    //need to check city is visisted or not

    if((setofCities&(1<<choice))==0){
        int subProb=dist[city][choice]+ TravellingSalesman(dist,choice,setofCities|(1<<choice),n,dp);
        ans=min(ans,subProb);
    }
 }

 dp[setofCities][city]=ans;

 return ans;
}

int main(){
     vector<vector<int> > dist ;

    dist.push_back(std::vector<int>());
    dist[0].push_back(0);
    dist[0].push_back(20);
    dist[0].push_back(42);
    dist[0].push_back(25);

    dist.push_back(std::vector<int>());
    dist[1].push_back(20);
    dist[1].push_back(0);
    dist[1].push_back(30);
    dist[1].push_back(34);

    dist.push_back(std::vector<int>());
    dist[2].push_back(42);
    dist[2].push_back(30);
    dist[2].push_back(0);
    dist[2].push_back(10);

    dist.push_back(std::vector<int>());
    dist[3].push_back(25);
    dist[3].push_back(34);
    dist[3].push_back(10);
    dist[3].push_back(0);
int n=4;
vector<vector<int> >dp(1<<n,vector<int>(n,-1));
 cout<<TravellingSalesman(dist,0,1,4,dp)<<endl;
}