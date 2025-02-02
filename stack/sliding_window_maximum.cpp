#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> nge(nums.size()),ans;
    stack<int> st;
    for(int i=nums.size();i>=0;i--)
    {
        while(!st.empty() and nums[st.top()]<=nums[i])st.pop();
        if(st.empty())nge[i] = nums.size();
        else nge[i] = st.top();

        st.push(i);
    }

    int max_yet = 0;
    for(int i=0;i<k;i++)
    {
        max_yet = max(max_yet, nums[i]);
    }

    ans.push_back(max_yet);

    for(int i=k;i<nums.size();i++)
    {
        //exit first
        int last = i-k;
        if(nums[last]==max_yet)
        {
            if(nge[last]>i)
            {
                //find greatest in next k elements
                int first = last+1;
                while(nge[first]<=i)
                {
                    first = nge[first];
                }

                max_yet = nums[first];
            }
            else
            {
                max_yet = nums[nge[last]];
            }
        }
        else
        {
            //dont do anything
        }


        //enter new , cur is i
        if(nums[i]>max_yet)max_yet = nums[i];

        ans.push_back(max_yet);
    }
    
    return ans;        
}


/*
    use deque to cutoff everything except recent k elements
*/
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i=0;i<nums.size();i++)
        {
            while(!q.empty() and q.front()<i-k+1)q.pop_front();
            while(!q.empty() and nums[q.back()]<=nums[i])q.pop_back();
            q.push_back(i);
            if(i>=k-1)ans.push_back(nums[q.front()]);
        }
        return ans;
}


int main()
{
    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> nums = {1};
    int k =3;
    vector<int> ans = maxSlidingWindow(nums,k);
    vector<int> ans2 = maxSlidingWindow2(nums,k);
    for(auto it:ans)cout<<it<<" ";cout<<endl;
    for(auto it:ans)cout<<it<<" ";
}