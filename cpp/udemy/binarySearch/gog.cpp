#include<iostream>

using namespace std;

//its about basically finding the search space
bool canMakePartitions(int K, int N, vector<int>coins,int sep){
    int friends=0;
    int sum=0;

    for(int i=0;i<N;i++){
        sum+=coins[i];
        if(sum>=sep){
            sum=0;
            friends++;
            if(friends>=K){
                return true;
            }
        }
    }

    return false;
}
int main(){
    int K=5;
    vector<int>coins;
    coins.push_back(11);
    coins.push_back(20);
    coins.push_back(23);
    coins.push_back(30); 
    coins.push_back(4);
    //may not be sorted 
    sort(coins.begin(),coins.end());
    int N=coins.size();
    int s=0;
    int e=0;
    for(int i=0;i<N;i++){
        e+=coins[i];
    }

    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        bool canPlace=canMakePartitions(K,N,coins,mid);
        if(canPlace){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }

    cout<<ans<<endl;
}