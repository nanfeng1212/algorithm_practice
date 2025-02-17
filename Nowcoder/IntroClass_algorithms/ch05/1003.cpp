#include<bits/stdc++.h>
using namespace std;
int n,m,k;
priority_queue<int,vector<int>,less<int>>q;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(q.size()<k)q.push(x);
        else{
            if(q.top()>x){
                q.pop();
                q.push(x);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a;
        if(a==1){
            cin>>b;
            if(q.size()<k)q.push(b);
            else{
            if(q.top()>b){
                q.pop();
                q.push(b);
                }
            }
            
        }
        else if(a==2)
        {
            if(q.size()<k)cout<<-1<<endl;
            else cout<<q.top()<<endl;
        }
    }
    return 0;
}