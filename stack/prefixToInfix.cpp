#include<bits/stdc++.h>
using namespace std;

bool is_operator(char ch)
{
    return (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^');
}


string preToInfix(string pre_exp) {
        // Write your code here
    int len = pre_exp.length();

    stack<string> st;

    for(int i=len-1;i>=0;i--)
    {
        if(is_operator(pre_exp[i]))
        {   
            //no need to check if empty, if the exp is valid
            string first = st.top();st.pop();
            string second = st.top();st.pop();

            string res = '(' + first + pre_exp[i] + second + ')';

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
    cout<<preToInfix(s);

}