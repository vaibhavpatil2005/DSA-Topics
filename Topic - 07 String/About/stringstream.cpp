#include<bits/stdc++.h>
using namespace std;
int main(){
    string sub;
    sub="vaibhav lives in burhanpur";
    stringstream ss(sub);
    string temp;
    while(ss>>temp){
        cout<<temp<<endl;
    }

}