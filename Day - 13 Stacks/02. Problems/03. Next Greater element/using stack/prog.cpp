/*


ite                         i
arr = 3  1  2  5    4   6   2   3
ans =                          -1

    ## Initial
        ans[n-1] = -1;
        st.push(arr[n-1]);

    ## Steps
        1. while{(st.top() <= arr[i]) st.pop();
        2. ans[i] = st.top();
        3. st.push(arr[i]);

    ## technique - pop--->ans---->push
*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {3,1,2,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Next greater element array using stack (t.c. O(n) s.c. O(n))
    
    stack<int>st;
    int nge[n];
    nge[n-1] = -1;
    st.push(arr[n-1]);

    for(int i=n-2;i>=0;i--){                         // reverse traverse
        //pop all the element smaller than arr[i];
        while(st.size()>0 && st.top()<=arr[i]){
            st.pop();
        }
        //mark the nas in nge array
        if(st.size()==0) nge[i]=-1;
        else nge[i]=st.top();
        // push the arr[i];
        st.push(arr[i]);
    }


    // dislay the ans
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
    cout<<endl;
}

