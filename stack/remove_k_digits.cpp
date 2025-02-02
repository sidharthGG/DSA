#include<bits/stdc++.h>
using namespace std;
/*
    Problem: https://leetcode.com/problems/remove-k-digits/description/

    Idea: remove when digits decrease, from most to least significant!
*/
string remove_leading_zeroes(string& s)
{
    int i;
    for(i=0;i<s.length();i++)if(s[i]!='0')break;
    string new_str = s.substr(i);
    if(new_str == "")new_str="0";
    return new_str;
}


string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.length();i++)
        {
            while(!st.empty() and (st.top()-'0')>(num[i]-'0') and k>0)
            {
                st.pop();
                --k;
            }

            st.push(num[i]);
        }

        while(!st.empty() and k>0)
        {
            st.pop();--k;
        }

        string ans = "";
        while(!st.empty())
        {
            ans+= st.top();st.pop();
        }

        reverse(ans.begin(),ans.end());
        ans = remove_leading_zeroes(ans);
        return ans;
}

int main()
{

    vector<pair<string,int>> nums = {{"1432219",3}, {"10200",1}, {"10",2}};
    
    for(int i=0;i<nums.size();i++){
        cout<<removeKdigits(nums[i].first, nums[i].second)<<endl;
    }
}  