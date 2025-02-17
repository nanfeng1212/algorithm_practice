#include<bits/stdc++.h>
using namespace std;
int d;
int n,m;
vector<int>edge[100010];
int in[100010];
int cnt;
int ans[100010];
void init() {
    memset(in,0,sizeof(in));
    memset(ans,0,sizeof(ans));
    memset(edge,0,sizeof(edge));
    cnt=0;
}
int main()
{
    cin>>d;
    while(d--)
    {
        init();
        priority_queue<int>q;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            edge[y].push_back(x);
            in[x]++;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(in[i]==0)q.push(i);
        while(!q.empty())
        {
            int i=q.top();
            q.pop();
            if(i!=0)ans[++cnt]=i;
            for(int j=0;j<edge[i].size();j++)
            {
                in[edge[i][j]]--;
                if(in[edge[i][j]]==0)
                    q.push(edge[i][j]);
            }
        }
        if(cnt!=n)cout<<"Impossible!\n";
        else{
            for(int i=cnt;i>=1;i--)
                cout<<ans[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
        
}