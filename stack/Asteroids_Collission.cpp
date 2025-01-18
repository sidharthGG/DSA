#include<bits/stdc++.h>
using namespace std;

/*
    Problem: https://leetcode.com/problems/asteroid-collision/
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
            }
            else
            {
                int cur_ast = asteroids[i];
                while(!st.empty() and st.top()>0 and cur_ast<0)
                {
                    int top = st.top();
                    if( abs(top) == abs(cur_ast))
                    {
                        st.pop();
                        cur_ast = 0;
                        break;
                    }
                    else if( abs(top) < abs(cur_ast))
                        st.pop();
                    else
                    {
                        cur_ast = 0;
                        break;
                    }
                }

                if(cur_ast)st.push(cur_ast);

            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }

int main()
{
    vector<int> asteroids = {-1,-2,2,1};
    vector<int> ans = asteroidCollision(asteroids);
    for(auto ast:ans)
    {
        cout<<ast<<" ";
    }
    cout<<"\n";
}