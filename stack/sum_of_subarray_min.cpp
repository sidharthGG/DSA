#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;

/*
    Problem: https://leetcode.com/problems/sum-of-subarray-minimums/

    Explaination: Each element has its range where it is the minimum by calculating
                  nearest smallest in either direction. In this subarray every subarray
                  including this current element will have min ans as current element.
                  the no of subarray can be calculated for each element in array.
                  NOTE: every subarray is included and none is repeated, prove this to
                        yourself. Also take care of when two equal elements in array 
                        not separated by even min element.
*/
int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        vector<int> left(arr.size()),right(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() and arr[st.top()]>arr[i])st.pop();
            if(st.empty())left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])st.pop();
            if(st.empty())right[i]=arr.size();
            else right[i]=st.top();
            st.push(i);
        }

        int64_t sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            int64_t narr = 1;
            narr = (narr%mod * (i-left[i])%mod)%mod;
            narr = ((int64_t)(narr%mod) * (right[i]-i)%mod)%mod;
            narr = ((int64_t)(narr%mod) * (arr[i]%mod))%mod;

            sum = (int64_t)((sum%mod) + (narr%mod))%mod;
           
        }

        return sum;
    }

int main()
{
    vector<int> arr = {71,55,82,55};
    vector<int> a2 = {1,2,3};
    cout<<sumSubarrayMins(a2);
}