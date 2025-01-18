#include<bits/stdc++.h>
using namespace std;

/*
    https://www.interviewbit.com/problems/nearest-smaller-element/
*/

vector<int> prevSmaller(vector<int> &A) {
    
    stack<int> st;
    vector<int> pse(A.size());
    for(int i=0;i<A.size();i++)
    {
        while(!st.empty() and st.top()>=A[i])st.pop();
        if(st.empty())
        {
            pse[i]=-1;
        }
        else
        {
            pse[i]=st.top();
        }
        
        st.push(A[i]);
    }
    
    return pse;
}

int main()
{
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> pse = prevSmaller(A);
    for(auto ele:pse)
    {
        cout<<ele<<" ";
    }
    cout<<"\n";
}