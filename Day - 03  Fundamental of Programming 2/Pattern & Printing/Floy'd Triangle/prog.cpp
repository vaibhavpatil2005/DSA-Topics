#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Number of Rows: ";
    cin>>n;

    int k = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
           cout<<k<<" ";
           k++;
        }
        cout<<endl;
    }

    return 0;
}