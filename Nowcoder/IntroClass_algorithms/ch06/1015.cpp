#include<bits/stdc++.h>
using namespace std;
const int N=363000;  
string s="",t="12345678x"; //输入的字符串和目标字符串
map<string,int>mp;  //存每个状态的编号
string bianhao[N];  //存每个编号对应的字符串
int last[N];   //存上一个状态
int cnt=0;  
queue<int>p;
char from[N];  //村步骤
char dir1[4]={'r','l','u','d'};
int dir[4][2]={0,1,0,-1,-1,0,1,0};
bool bfs(string s,string t)
{
    //给各个维护的容器做初始化
    mp[s]=1;
    cnt=1;
    bianhao[1]=s;
    last[1]=0;
    p.push(1);
    //开始搜索
    while(!p.empty())
    {
        int temp=p.front();
        p.pop();
        string cur=bianhao[temp];
        int pos=cur.find('x');
        int x=pos/3,y=pos%3; //返回每个状态中'x'的坐标
        //进行四个方向的具体搜索
        for(int i=0;i<4;i++)
        {
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(dx<0||dy<0||dx>=3||dy>=3)continue;
            string nxt=cur;
            swap(nxt[pos],nxt[dx*3+dy]);
            if(mp.find(nxt)!=mp.end())continue;
            mp[nxt]=++cnt;
            bianhao[cnt]=nxt;
            from[cnt]=dir1[i];
            last[cnt]=temp;
            if(nxt==t)return 1;
            p.push(cnt);
        }
    }
    return 0;
    
}
//打印步骤
void dfs(int x)
{
    if(last[x]!=0)
    {
        dfs(last[x]);
        cout<<from[x];
    }
}
int main()
{
    for(int i=1;i<=9;i++)
    {
        char x;
        cin>>x;
        s+=x;
    }
    if(!bfs(s,t))cout<<"unsolvable"<<endl;
    else{
        dfs(cnt);
    }
}