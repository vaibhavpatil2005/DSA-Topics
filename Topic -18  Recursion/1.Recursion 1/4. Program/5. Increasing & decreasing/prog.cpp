/*
    ## Print increasing decreasing sequence 

        int n = 4
        output = 1 2 3 4 3 2 1
*/

#include<iostream>
using namespace std;

void print(int x,int n){
    if(x>=n){
        cout<<x<<" ";
        return;
    }
       cout<<x<<" ";
       print(x+1,n);

       cout<<x<<" ";

}

int main(){
    int n;
    cout<<"Enter Your value";
    cin>>n;
    print(1,n);
}