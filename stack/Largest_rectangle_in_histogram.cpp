#include<bits/stdc++.h>
using namespace std;

/*
    Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

/*
    Approach 1: Find first min on both side and calc area
*/
vector<int> find_left(vector<int>& h)
    {
        vector<int> left(h.size());
        stack<int> st;
        for(int i=0;i<h.size();i++)
        {
            while(!st.empty() and h[st.top()]>=h[i])st.pop();
            if(st.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = st.top();
            }

            st.push(i);
        }

        return left;
    }

    vector<int> find_right(vector<int>& h)
    {
        vector<int> right(h.size());
        stack<int> st;
        for(int i=h.size()-1;i>=0;i--)
        {
            while(!st.empty() and h[st.top()] >= h[i])st.pop();
            if(st.empty())
            {
                right[i] = h.size();
            }
            else
            {
                right[i] = st.top();
            }

            st.push(i);
        }

        return right;
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = find_left(heights);
        vector<int> right = find_right(heights);

        // for(int i=0;i<heights.size();i++)cout<<left[i]<<" "<<i<<" "<<right[i]<<endl;

        int ans = 0;
        for(int i=0;i<heights.size();i++)
        {
            int cur = heights[i]*(right[i]-left[i]-1);
            ans = max(ans,cur);
        }

        return ans;
    }


/*
    Approach 2: same , but one pass!
    How does it work ? : Every element gets popped out of stack,
                         while popping check its left (left small)
                         while right small would be curr ( the one popping it right now!)
*/

int largestRectangleArea2(vector<int>& heights)
{
    heights.push_back(0);
    int ans = 0;
    stack<int> st;
    for(int i=0;i<heights.size();i++)
    {
        while(!st.empty() and heights[st.top()] >= heights[i])
        {
            int area = 0;
            int cur_idx = st.top();
            st.pop();

            if(st.empty())
            {
                area+= (cur_idx+1)*heights[cur_idx];
            }
            else
            {
                area+= (cur_idx-st.top())*heights[cur_idx];
            }

            //right
            area+= (i-cur_idx-1)*heights[cur_idx];
            ans = max(ans, area);
        }

        st.push(i);
    }

    /*
        this part is not needed if 0 is pused in last of heights
        since it will pop all those elements
    */

    // while(!st.empty())
    // {
    //     int cur = st.top();st.pop();
    //     int area = 0;
    //     area+= (heights.size()-cur-1)*heights[cur];
        
    //     if(st.empty())
    //     {
    //         area+= (cur+1)*heights[cur];
    //     }
    //     else
    //     {
    //         area+= (cur-st.top())*heights[cur];
    //     }

    //     ans = max(ans, area);
    // }

    return ans;
}

int width = 0;


int main()
{
    vector<int> h = {4,5};
    cout<<largestRectangleArea(h);
}