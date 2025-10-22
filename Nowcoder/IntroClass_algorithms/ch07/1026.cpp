#include<bits/stdc++.h>
using namespace std;
char a[60],b[60];
bool dp[55][55][55][55];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> a+1 >> b+1;
        int n1=strlen(a+1);
        int n2=strlen(b+1);
        int ans=0;
        for(int x=0;x<=n1;x++)
            for(int y=0;y<=n2;y++)
                for(int l1=1,r1=x+l1-1;r1<=n1;r1++,l1++)
                    for(int l2=1,r2=y+l2-1;r2<=n2;r2++,l2++)
                    {   
                        if(x+y<=1)dp[l1][r1][l2][r2]=1;
                        else{
                            if(a[r1]==a[l1])dp[l1][r1][l2][r2]|=dp[l1+1][r1-1][l2][r2];
                            if(a[l1]==b[r2])dp[l1][r1][l2][r2]|=dp[l1+1][r1][l2][r2-1];
                            if(b[l2]==a[r1])dp[l1][r1][l2][r2]|=dp[l1][r1-1][l2+1][r2];
                            if(b[l2]==b[r2])dp[l1][r1][l2][r2]|=dp[l1][r1][l2+1][r2-1];
                        } 
                        if(dp[l1][r1][l2][r2])ans=max(ans,x+y);
                    }
        cout << ans << endl;
    }
}