#include<iostream>

using namespace std;

int partition(vector<int>&v,int s,int e){
    int pivot=v[e];
    int i=s-1;

    for(int j=s;j<=e;j++){
        if(v[j]<pivot){
            i++;
            swap(v[j],v[i]);
        }
    }

    swap(v[i+1],v[e]);
    return i+1;
}

int quickSelect(vector<int>&v,int s, int e, int k){
    int p=partition(v,s,e);
    if(p==k){
        return v[p];
    }
    else if(p>k){
        return quickSelect(v,s,p-1,k);
    }else if(p<k){
        return quickSelect(v,p+1,e,k);
    }
}
int main(){
    vector<int>arr;
    arr.push_back(3);
     arr.push_back(1);
      arr.push_back(8);
       arr.push_back(0);
       int e=arr.size()-1;
  cout<<quickSelect(arr,0,e,2)<<endl;
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}