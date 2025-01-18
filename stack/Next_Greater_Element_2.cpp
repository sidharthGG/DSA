#include<bits/stdc++.h>
using namespace std;

/*
    https://leetcode.com/problems/next-greater-element-ii/description/
*/

vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;vector<int> nge(nums.size());
        for(int i=0;i<2;i++)
        {
            for(int j=nums.size()-1;j>=0;j--)
            {
                while(!st.empty() and st.top()<=nums[j])st.pop();
                if(st.empty())
                {
                    nge[j]=-1;
                }
                else
                {
                    nge[j]=st.top();
                }

                st.push(nums[j]);
            }
        }

        return nge;
    }

int main()
{
    vector<int> nums = {1,2,1};
    vector<int> nge = nextGreaterElements(nums);
    for(auto ele:nge)
    {
        cout<<ele<<" ";
    }
    cout<<"\n";
}