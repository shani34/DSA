#include<iostream>

using namespace std;

int merge(vector<int>&arr,int s, int e){
  int i=s;
  int m=(s+e)/2;
  int j=m+1;

  vector<int>tmp;
  int cnt=0;
  while(i<=m && j<=e){
    if(arr[i]<arr[j]){
        tmp.push_back(arr[i]);
        i++;
    }else{
        cnt+=(m-i+1);
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

return cnt;
}
int mergeSort(vector<int>&arr, int s, int e){
   //base case
   if(s>=e){
        return 0;
    }

    //rec case
    int mid=(s+e)/2;
    int c1=mergeSort(arr,s,mid);
    int c2=mergeSort(arr,mid+1,e);
    int c3= merge(arr,s,e);
    return c1+c2+c3;

}

int main(){
    vector<int>arr;
    arr.push_back(3);
     arr.push_back(1);
      arr.push_back(8);
       arr.push_back(0);
       int e=arr.size()-1;
  cout<<mergeSort(arr,0,e);
//   for(int i=0;i<arr.size();i++){
//     cout<<arr[i]<<" ";
//   }
  cout<<endl;
}