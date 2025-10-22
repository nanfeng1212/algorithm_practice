#include<bits/stdc++.h>
using namespace std;
long long f[12][1<<12];
int h,w;
bool fun(int x)
{
    int ww=w;
    int cnt=0;
    while(ww--)
    {
        if(x&1){
            if(cnt&1)return 0;
            cnt=0;
        }
        else cnt++;
        x>>=1;
    }
    if(cnt&1)return 0;
    return 1;
}
int main()
{
    while(cin>>h>>w)
    {
        memset(f,0,sizeof(f));
        if(h==0&&w==0)break;
        int len=(1<<w)-1;
        f[0][0]=1;
        for(int i=1;i<=h;i++)
            for(int j=0;j<=len;j++)
            {
                if((i==h)&&j)break;
                f[i][j]=0;
                for(int k=0;k<=len;k++)
                {
                    if(k&&(i==1))break;
                    if(k&j)continue;
                    if(!fun(k|j))continue;
                    f[i][j]+=f[i-1][k];
                }
            }
        cout<<f[h][0]<<endl;
    }
}
