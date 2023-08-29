#include<iostream>

using namespace std;

//use left shift 1<<i 

int getithBit(int n, int i){
   int mask=(1<<i);
   return (n&mask)>0? 1:0;
}

int setithBit(int n, int i){
    int mask=(1<<i);
    n=n|mask;
    return n;
}

int clearithBit(int n,int i){
    int mask=~(1<<i);
    n=(n&mask);
    return n;
}

int updateithBit(int n, int i, int v){
    int mask=~(1<<i);
    n=(n&mask);
    int mask2=(v<<i);
    n=(n|mask2);
    return n;
}

int cleatLastIBits(int n, int i){
    int mask=(-1<<i);
    return n&mask;
}

int clearBitsinRange(int n,int i, int j){
    int a=(~0)<<(j+1);
    int b=(1<<i)-1;
    int mask=a|b;
    return (n&mask);
}
int  main(){
    int n=31;
    // int i;
    // cin>>i;
    // cout<<getithBit(n,i)<<"\n";
    // cout<<setithBit(n,i)<<"\n";
    // cout<<clearithBit(n,i);
    //  cout<<updateithBit(n,i,0);
    // cout<<cleatLastIBits(n,i);
     cout<<clearBitsinRange(n,0,2);
}