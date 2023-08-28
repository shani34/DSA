#include <iostream>
#include <stack>
using namespace std;


int main(){
cout<<"hello world!";
 stack<int> st;

 st.push(1);
 st.push(2);
 
 while(!st.empty()){
    cout<<st.top()<<"\n";
 }

return 0;
}