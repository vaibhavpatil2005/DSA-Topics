/*
    ## Compare Arrays , Linked Lists and stacks 

               # Time Complexity                space complexity
               arr    ll      stack               arr      ll       stack


    1. get     O(1)   O(n)      O(n)               O(1)     O(1)      O(n)
    2. insert  O(n)   O(n)      O(n)               O(n)     O(1)      O(n)
    3. delete  O(n)   O(n)      O(n)               O(n)     O(1)      O(n)
    

// Reverse a stack


    -(1) using two other stacks

        |         |         
        |         |
        |         |------------|
        |  st     |            |
        |---------|            |
    #                            
        |         |            |
        |         |            |
        |    gt   | <----------|           
        |         |            
        |---------| <----------|          

        |         |            |
        |         |            |
        |         | <----------|            
        |   rt    |
        |---------|


    (2) - first store the elements in vector and in reverse order push intro stack 

        |         |
        |         |
        |         |         vector<int>vec = {50,40,30,20,10}
        |         |
        |---------|
*/

#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>st){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
    
    stack<int>gt;
    stack<int>rt;

    // empty st into gt
    while(st.size()>0){
        gt.push(st.top());
        st.pop();
    }

    // empty gt into rt
    while(gt.size()>0){
        rt.push(gt.top());
        gt.pop();
    }

    // empty rt into st
    while(rt.size()>0){
        st.push(rt.top());
        rt.pop();
    }
}


