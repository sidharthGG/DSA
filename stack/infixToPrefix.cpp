#include<bits/stdc++.h>
using namespace std;

bool is_operator(char ch)
{
    return (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^');
}

int priority(char ch)
{
    if(ch == '^')return 3;
    if(ch == '*' or ch == '/')return 2;
    if(ch == '+' or ch == '/')return 1;
    return 0;
}

string infixToPrefix(string s)
{
    stack<char> st;
    string ans = "";

    for(int i=s.length()-1;i>=0;i--)
    {
        if(is_operator(s[i]))
        {
            while(!st.empty() and priority(st.top()) > priority(s[i]))
            {
                char top = st.top();
                st.pop();
                ans += top;
            }

            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            st.push(s[i]);
        }
        else if(s[i] == '(')
        {
            while(!st.empty() and st.top()!=')')
            {
                ans += st.top();
                st.pop();
            }

            //remove the ) "closing braces from if parsing from end!"
            if(st.top() == ')')st.pop();
        }
        else
        {
            ans += s[i];
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s;cin>>s;
    cout<<infixToPrefix(s)<<endl;
}