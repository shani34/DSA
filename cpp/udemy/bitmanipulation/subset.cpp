#include<iostream>

using namespace std;

void overlayNumber(string s, int number){
  int j=0;

  while(number){
    int last_bit=number&1;
    if(last_bit){
        cout<<s[j];
    }
    j++;
    number=(number>>1);
  }

  cout<<endl;
}
void subset(string s){
   int n=s.size();

   for(int i=0;i<(1<<n);i++){
       for(int j=0;j<i;j++){
         if(i&(1<<j)){
            cout<<s[j];
         }
       }
       cout<<endl;
   }
}
int main(){
   string s="abc";
   subset(s);
}