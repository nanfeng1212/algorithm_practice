#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[40][40];
int fun(int i,int j)
{
    if(i==0)
    {
        if(j==1)
            return 1;
        else
            return 0;
    }
    if(a[i][j]!=-1)return a[i][j];
    else{
        if(j==1)return a[i][j]=fun(i-1,n)+fun(i-1,2);
        if(j==n)return a[i][j]=fun(i-1,n-1)+fun(i-1,1);
        return a[i][j]=fun(i-1,j-1)+fun(i-1,j+1);
    }
}
int main()
{
    memset(a,-1,sizeof(a));
    cin>>n>>m;
    //a[1][2]=a[1][n]=1;
    cout<<fun(m,1);
    return 0;
}