#include<iostream>

using namespace std;
//its about basically finding the search space
bool canPlaceBirds(int B, int N, vector<int>nests,int sep){
    int birds=1;
    int location=nests[0];

    for(int i=1;i<N;i++){
        int current_location=nests[i];
        if(current_location-location>=sep){
            location=current_location;
            birds++;
            if(birds==B){
                return true;
            }
        }
    }

    return false;
}
int main(){
    int B=3;
    vector<int>nests;
    nests.push_back(1);
    nests.push_back(2);
    nests.push_back(4);
    nests.push_back(8); 
    nests.push_back(9);
    //may not be sorted 
    sort(nests.begin(),nests.end());
    int N=nests.size();
    int s=0;
    int e=nests[N-1]-nests[0];
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        bool canPlace=canPlaceBirds(B,N,nests,mid);
        if(canPlace){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }

    cout<<ans<<endl;
}