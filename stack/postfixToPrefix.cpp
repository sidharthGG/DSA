#include<bits/stdc++.h>
using namespace std;

bool is_operator(char ch)
{
    return (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^');
}

string postToPre(string pre_exp)
{
    int len = pre_exp.length();
    stack<string> st;

    for(int i=0;i<len;i++)
    {
        if(is_operator(pre_exp[i]))
        {   
            //no need to check if empty, if the exp is valid
            string second = st.top();st.pop();
            string first = st.top();st.pop();

            string res = pre_exp[i] + first  + second;

            st.push(res);
        }   
        else
        {
            st.push(string(1,pre_exp[i]));
        }
    }

    return st.top();
}

int main()
{
    string s;cin>>s;
    cout<<postToPre(s)<<endl;

}