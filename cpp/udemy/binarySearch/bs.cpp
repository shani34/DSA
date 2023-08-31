#include<iostream>

using namespace std;

int binary(vector<int>v,int t){
    int l=0;
    int h=v.size();

    while(l<=h){
        int mid=(l+h)/2;
        if(v[mid]>t){
            h=mid-1;
        }else if(v[mid]<t){
            l=mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout<<binary(v,2);
}