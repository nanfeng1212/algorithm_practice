#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
int main()
{
    int t,n,k,a[5000010];
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            a[i]=read();
        }
        sort(a+1,a+1+n);
        cout<<a[k]<<endl;
    }
}