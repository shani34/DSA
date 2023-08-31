#include<iostream>

using namespace std;

void merge(vector<int>&arr,int s, int e){
  int i=s;
  int m=(s+e)/2;
  int j=m+1;

  vector<int>tmp;

  while(i<=m && j<=e){
    if(arr[i]<arr[j]){
        tmp.push_back(arr[i]);
        i++;
    }else{
          tmp.push_back(arr[j]);
          j++;
    }
  }

  while(i<=m){
     tmp.push_back(arr[i]);
        i++;
  }

  while(j<=e){
     tmp.push_back(arr[j]);
        j++;
  }

int k=0;
  for(int idx=s;idx<=e;idx++){
    arr[idx]=tmp[k++];
  }

return ;
}
void mergeSort(vector<int>&arr, int s, int e){
   //base case
   if(s>=e){
        return;
    }

    //rec case
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    return merge(arr,s,e);
}

int main(){
    vector<int>arr;
    arr.push_back(3);
     arr.push_back(1);
      arr.push_back(8);
       arr.push_back(0);
       int e=arr.size()-1;
  mergeSort(arr,0,e);
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}