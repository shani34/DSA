#include<iostream>

using namespace std;


void generateBrackets(int n, int open, int close,int i,vector<string>&ans,string tmp){
//base condition
if(i==2*n){
    ans.push_back(tmp);
    return;
}
//calling open brackets
    //calling close brackets

    //  generateBrackets(n,open+1,close,i+1,ans,tmp+"(");={
            //  tmp+="("
            //  generateBrackets(n,open+1,close,i+1,ans,tmp);
            // tmp.pop_back()
    // }
    
if(open<n){
    generateBrackets(n,open+1,close,i+1,ans,tmp+"(");
}    

if(close<open){
        generateBrackets(n,open,close+1,i+1,ans,tmp+")");
    }
}
int main(){
    while(true){
    int n;
    cin>>n;
    vector<string>ans;
    generateBrackets(n,0,0,0,ans,"");
    for( int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    }

}