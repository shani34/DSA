#include<iostream>
using namespace std;

void findPhone(string digits, int ind, string temp, vector<string>&ans){
    //base condition
    if(digits.size()==0){
        return;
    }
    
    if(temp.size()==digits.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=ind;i<digits.size();i++){
        if(digits[i]=='2'){
            temp+='a';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='b';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='c';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
         if(digits[i]=='3'){
            temp+='d';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='e';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='f';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
         if(digits[i]=='4'){
            temp+='g';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='h';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='i';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
         if(digits[i]=='5'){
            temp+='j';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='k';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='l';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
        
         if(digits[i]=='6'){
            temp+='m';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='n';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='o';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
         if(digits[i]=='7'){
            temp+='p';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='q';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='r';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
         if(digits[i]=='8'){
            temp+='t';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='u';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='v';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
         if(digits[i]=='9'){
            temp+='w';
          findPhone(digits,i+1,temp,ans);
          temp.pop_back();
          
          temp+='y';
           findPhone(digits,i+1,temp,ans);
         temp.pop_back();
          
           temp+='z';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
             temp+='x';
           findPhone(digits,i+1,temp,ans);
          temp.pop_back();
        }
    }
}
int main() {
    while(1){
        vector<string>ans;
    string digits;
     cin>>digits;
     findPhone(digits,0,"",ans);
     for( int i=0;i<ans.size();i++){

        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans.size()*ans[0].size()<<endl;
    }
}
