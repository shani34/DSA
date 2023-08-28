#include <iostream>
#include<stack>
using namespace std;



int main(){
     cout<<"queue implementation using stack";
     stack<int>st;
     stack<int>st2;
     st.push(1);
     st.push(2);
     st.push(3);

     while(!st.empty()){
        cout<<st.top()<<"\n";
        st2.push(st.top());
        st.pop();
     }
 
 cout<<"queue"<<"\n";
    while(!st2.empty()){
        cout<<st2.top()<<"\n";
        st2.pop();
     }
     
    return 0;
}