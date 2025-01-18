#include<bits/stdc++.h>
using namespace std;

/*
    https://leetcode.com/problems/next-greater-element-i/description/
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> nge;

        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<nums2[i])st.pop();
            if(st.empty())
            {
                nge[nums2[i]]=-1;
            }
            else
            {
                nge[nums2[i]]=st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            ans[i] = nge[nums1[i]];
        }

        return ans;
    }

int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1,nums2);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }   
}