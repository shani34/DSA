#include<iostream>
#include<vector>
using namespace std;
//basically using xor will cancelout the same bits 
//given 2N+1 (meaning 1 number is unique )

//given 2N+2 (meaning 2 number is unique)

// given 3N+1 (1 unique number)(basically find the sum at bit level and then modulo that with x=3,5,7) 
void updateSum(vector<int>&s,int x){
    for(int i=0;i<32;i++){
        int ith_bit=x&(1<<i);
        if(ith_bit){
            s[i]++;
        }
    }
}
void unique3(vector<int>v){
    vector<int>sumArr(32,0);

    for(int x:v){
        updateSum(sumArr,x);

    }

    for(int i=0;i<32;i++){
        sumArr[i]=sumArr[i]%3;
    }
   
   int num=0;

   for(int i=0;i<32;i++){
    num+=(sumArr[i]*(1<<i));
   }

   cout<<num;
}
void unique2(vector<int>v){
    int cx=0;

//XOR of all numbers
    for(int i=0;i<v.size();i++){
        cx=cx^v[i];
    }

    //position of first set bit
    int pos=0;
    int temp=cx;
    while((temp&1)==0){
        pos++;
        temp=temp>>1;
    }

//filter out array

int setA=0;
int setB=0;
int mask=(1<<pos);

for( int i=0;i<v.size();i++){
   if((v[i]&mask)>0){
    setA=setA^v[i];
   }else{
    setB=setB^v[i];
   }
}

cout<<setA<<" "<<setB;
}
int unique(vector<int>v){

 int cx=0;
 for(int i=0;i<v.size();i++){
    cx=cx^v[i];
 }

 return cx;
}
int main(){
   vector<int>v;
   v.push_back(1);
   v.push_back(1);
   v.push_back(2);
   v.push_back(2);
   v.push_back(5);
   v.push_back(1);
   v.push_back(2);

  //int ans=unique(v);
//   unique2(v);
unique3(v);
  //cout<<ans;

}