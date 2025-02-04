#include<iostream>
using namespace std;

void printgn(int n){
    if(n==0)return;
    cout<<"Hello Good Morning"<<endl;
    printgn(n-1);

}

int main(){
    int n;
    cout<<"Enter your value ";
    cin>>n;
    printgn(n);
}