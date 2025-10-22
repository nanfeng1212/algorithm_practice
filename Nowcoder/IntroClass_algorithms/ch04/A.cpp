#include<bits/stdc++.h>
using namespace std;
 
int n,a[1000100],maxn[1000100];
stack<int> st;
 
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    for(int i = n;i >= 1;i--)
        maxn[i] = max(a[i],maxn[i + 1]);
    for(int i = 1;i <= n;i++)
    {
        st.push(a[i]);
        while(!st.empty() && st.top() >= maxn[i+1])
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}