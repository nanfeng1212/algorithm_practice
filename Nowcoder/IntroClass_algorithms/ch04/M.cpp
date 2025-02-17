#include<iostream>
#include<deque>
using namespace std;
int n,k;
int a[1000010];
deque<int>mx,mn;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(!mn.empty()&&i-mn.front()>=k)mn.pop_front();
        while(!mn.empty()&&a[i]<=a[mn.back()])mn.pop_back();
        mn.push_back(i);
        if(i>=k)cout<<a[mn.front()]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(!mx.empty()&&i-mx.front()>=k)mx.pop_front();
        while(!mx.empty()&&a[i]>=a[mx.back()])mx.pop_back();
        mx.push_back(i);
        if(i>=k)cout<<a[mx.front()]<<" ";
    }
    return 0;
}