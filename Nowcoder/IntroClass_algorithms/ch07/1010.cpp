#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[3010][3010];
const int mod=2333;
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
int main()
{
    read(m);
    read(n);
    int k[3010][3010];
    int b[3010][3010];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            read(a[i][j]);
            if(a[i][j]==1)b[i][j]=-1;
        }
    /*for(int i=1;i<=m;i++)
    {
        if(b[n][i]==-1)break;
        k[n][i]=1%mod;
    }    
    for(int i=n;i>=1;i--)
    {
        if(b[1][i]==-1)break;
        k[1][i]=1%mod;
    }*/
    k[1][n]=1;
    for(int i=1;i<=m;i++)
    {
        
        for(int j=n;j>=1;j--)
        {
            if(i==1&&j==n)continue;
            if(b[i][j]==-1)k[i][j]=0;
            else{
                k[i][j]=(k[i][j+1]+k[i-1][j])%mod;
            }
        }
    }
    cout<<k[m][1]<<endl;
    return 0;
    
}