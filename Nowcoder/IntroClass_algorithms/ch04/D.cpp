#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int n;
int a[1010];
int main(){
    while(cin>>n)
    {
        if(n==0)
            break;
        memset(a,0,sizeof(a));
        while(cin>>a[1])
        {
            if(a[1]==0)
                break;
            for(int i=2;i<=n;i++)
                cin>>a[i];
            int j=1;
            bool flag=1;
            stack<int>stac;
            for(int i=1;i<=n;i++)
            {
                while(j!=a[i])
                {
                    if(a[i]>j||stac.empty())
                    {
                        stac.push(j);
                        j++;
                    }
                    else if(a[i]==stac.top())
                    {
                        stac.pop();
                        break;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    
                }
                if(flag==0)break;
                if(j==a[i])j++;
            }
            if(flag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cout<<endl;
    }
}