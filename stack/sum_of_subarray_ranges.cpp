#include<bits/stdc++.h>
using namespace std;

/*
    Problem: https://leetcode.com/problems/sum-of-subarray-ranges/description/
*/

/*
    Pre-requisite: do sum of subarray min first, 
                    later this can be done with min max !
*/

long long max_subarray(vector<int>& nums)
{
    
    vector<int> left(nums.size()),right(nums.size());
    stack<int> st;

    for(int i=0;i<nums.size();i++)
    {
        while(!st.empty() and nums[st.top()]<nums[i])st.pop();
        //giving left more priority to avoid duplicates in case of two max in a subarray

        if(st.empty())left[i] = -1;
        else left[i] = st.top();

        st.push(i);
    }

    while(!st.empty())st.pop();

    for(int i=nums.size()-1;i>=0;i--)
    {
        while(!st.empty() and nums[st.top()]<=nums[i])st.pop();

        if(st.empty())right[i] = nums.size();
        else right[i] = st.top();

        st.push(i);
    }

    long long max_sub = 0;
    for(int i=0;i<nums.size();i++)
    {
        max_sub += (long long)(i-left[i])*(long long)(right[i]-i)*(long long)nums[i];
    }

    return max_sub;

}

long long min_subarray(vector<int>& nums)
{
    vector<int> left(nums.size()),right(nums.size());
    stack<int> st;

    for(int i=0;i<nums.size();i++)
    {
        while(!st.empty() and nums[st.top()]>nums[i])st.pop();
        if(st.empty())left[i] = -1;
        else left[i] = st.top();

        st.push(i);
    }

    while(!st.empty())st.pop();

    for(int i=nums.size();i>=0;i--)
    {
        while(!st.empty() and nums[st.top()]>=nums[i])st.pop();
        if(st.empty())right[i] = nums.size();
        else right[i] = st.top();

        st.push(i);
    }

    long long min_sub = 0;
    for(int i=0;i<nums.size();i++)
    {
        min_sub += (long long)(i-left[i])*(long)(right[i]-i)*(long long)nums[i];
    }

    return min_sub;
}

long long subArrayRanges(vector<int>& nums)
{
    
    return max_subarray(nums) - min_subarray(nums);  
}


int main()
{
    vector<int> nums = {4,-2,-3,4,1};
    vector<int> a = {47,70};
    cout<<subArrayRanges(a)<<endl;
    
}