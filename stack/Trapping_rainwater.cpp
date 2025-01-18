#include<bits/stdc++.h>
using namespace std;

/*
    Problem: https://leetcode.com/problems/trapping-rain-water/
*/


/*
   1. two pointer approach:
    the key thing about this approach is we dont need to focus on both highs at the same time!
*/
int trap(vector<int>& height) {
    
    int left_max = 0;
    int right_max = 0;

    int right = height.size()-1;
    int left = 0;
    int water = 0;

    while(left <= right)
    {
        if(height[left] <= height[right])
        {
            //left wall will be holding water if any
            //check if this is max when looking left, else it will store some water
            if(height[left] >= left_max)left_max = height[left];
            else water += left_max-height[left];

            left++;
        }
        else
        {
            if(height[right] >= right_max)right_max = height[right];
            else water += right_max-height[right];

            right--;
        }
    }

    return water;
}


/*
    2. left greatest , right greatest approach (Space complexity: O(N) )
*/


/*
    on each bar, the bar longest to right and left matter , min of those will be current bars water level
*/
    vector<int> find_gel(vector<int>& height)
    {
        int greatest_yet = 0;
        vector<int> gel(height.size());
       for(int i=0;i<height.size();i++)
       {
            gel[i] = greatest_yet;
            greatest_yet = max(greatest_yet,height[i]);
       }

       return gel;
    }

    vector<int> find_ger(vector<int>& height)
    {
        int greatest_yet = 0;
        vector<int> ger(height.size());
        for(int i=height.size()-1;i>=0;i--)
        {
            ger[i] = greatest_yet;
            greatest_yet = max(greatest_yet,height[i]);
        }

        return ger;
    }



    int trap_2(vector<int>& height) {
        
        vector<int> ger = find_ger(height);
        vector<int> gel = find_gel(height);
        int water = 0;

        for(int i=0;i<height.size();i++)
        {
            int wall =  min(ger[i],gel[i]);
            if(wall>height[i])water+=wall-height[i];
        }
        //cout<<gel[5]<<" "<<ger[5]<<endl;
        return water;
    }



int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<" "<<trap_2(height)<<"\n";
}