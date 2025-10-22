#include<iostream>
using namespace std;
int a[10010];
int n,cnt=0;
void push(int x)
{
    cnt++;
    a[cnt]=x;
    int j=cnt,i=j/2;
    while(i!=0&&a[i]>a[j])
    {
        swap(a[i],a[j]);
        j/=2;
        i/=2;
    }
}
int top()
{
    return a[1];
}
void pop()
{
    a[1]=a[cnt];
    cnt--;
    int i=1,j=i*2;
    if(j+1<=cnt&&a[j]>a[j+1])j=j+1;
    while(j<=cnt&&a[j]<a[i])
    {
        swap(a[i],a[j]);
        i=j;
        j=i*2;
        if(j+1<=cnt&&a[j]>a[j+1])j=j+1;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; 
        cin>>x;
        push(x);
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        int x1=top();
        pop();
        int x2=top();
        pop();
        ans+=x1+x2;
        push(x1+x2);
    }
    cout<<ans;
    return 0;
}