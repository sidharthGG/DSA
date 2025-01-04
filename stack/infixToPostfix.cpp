#include<bits/stdc++.h>
using namespace std;

/*
    a+b*c^d-e*f

    understand how this fits in!
*/

bool is_operator(char ch)
{
    return (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^');
}

string infixToPostfix(string& s) {
        // Your code here
    string ans = "";
    stack<char> st;

    map <char,int> priority;
    priority['^']=3;
    priority['*']=2;priority['/']=2;
    priority['+']=1;priority['-']=1;
    priority['(']=0;

    for(int i=0;i<s.length();i++)
    {
        if(is_operator(s[i]))
        {
            while(!st.empty() and priority[st.top()]>=priority[s[i]])
            {
                //calculate this
                char top = st.top();st.pop();
                ans+=top;
            }

            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() and st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }

            //remove the (
            if(st.top()=='(')st.pop();
        }
        else
        {
            ans+=s[i];
        }
    }

    //empty the stack at the end
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }        

    return ans;
}

int main(){

       string s;cin>>s;
       cout<<infixToPostfix(s);
  //infix to postfix

  
   
   

}

