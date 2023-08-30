#include<iostream>

using namespace std;

int Birthdayparadox(double per){
   long double p=1;
    int person=1;
    if (per==1.00){
        return 366;
    }
    while(true){
        p=(p)*((double)(365-person)/365);
         person++;
        if((1-p)>=per){
            break;
        }
       
    }

    return person;
}
int main(){
    double per;
    cin>>per;
   cout<< Birthdayparadox(per)<<endl;
}