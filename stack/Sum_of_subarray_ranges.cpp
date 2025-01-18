#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;


int sumSubarrayMins(vector<int>& arr) {
  vector<int> a;
  a.push_back(0);
  for(int it:arr)a.push_back(it);
  a.push_back(0);
  
  //idx from 1 to n
  int n = a.size()-1;
  stack<int> st;

  vector<int> sl(a.size()),sr(a.size());

  for(int i=1;i<n;i++)
  {
    while(!st.empty() and a[st.top()]>=a[i])st.pop();
    if(st.empty())
    {
      sl[i] = 0;
    }
    else
    {
      sl[i] = st.top();
    }
    st.push(i);
  }

  while(!st.empty())st.pop();

  for(int i=n-1;i>0;i--)
  {
    while(!st.empty() and a[st.top()]>=a[i])st.pop();
    if(st.empty())
    {
      sr[i] = n;
    }
    else
    {
      sr[i] = st.top();
    }
    st.push(i);
  }

  int ans = 0;
  for(int i=1;i<n;i++)
  {
    //subarry within the min range containing this very element
    ans += (a[i]%mod)*((i-sl[i])%mod)*((sr[i]-i)%mod)%mod;

    cout<<i<<"-> "<<sl[i]<<" : "<<sr[i]<<endl;
  }

  return ans;
}

int main()
{
    vector<int> arr = {71,55,82,55};
    cout<<sumSubarrayMins(arr)<<"\n";
}

/*
 0 71 55 82 55 0
 */