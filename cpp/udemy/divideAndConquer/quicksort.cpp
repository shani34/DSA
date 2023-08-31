#include<iostream>

using namespace std;
//choose pivot->last element
//partition-> take two pointer (i,j)and swap accordingly.move j if pivot is smaller otherwise swap element at i,j index;
//recursively sort 
int partition(vector<int>&v,int s, int e){
    int pivot=v[e];
    int i=s-1;
    for(int j=s;j<=e;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }

    swap(v[i+1],v[e]);

    return i+1;
}
void quickSort(vector<int>&v, int s, int e){
//base case
if(s>=e){
    return ;
}
//get partition index
int p=partition(v,s,e);
//rec calls
quickSort(v,s,p-1);
quickSort(v,p+1,e);
}
int main(){
    vector<int>arr;
    arr.push_back(3);
     arr.push_back(1);
      arr.push_back(8);
       arr.push_back(0);
       int e=arr.size()-1;
  quickSort(arr,0,e);
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}