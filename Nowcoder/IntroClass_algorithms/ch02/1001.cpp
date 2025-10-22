#include<iostream>
using namespace std;
int cal(int n)
{
    if(n<10)return n;
    int x=0;
    while(n)
    {
        x+=n%10;
        n/=10;
    }
    return cal(x);
}
int main()
{
    int n;
    cin>>n;
    cout<<cal(n);
    return 0;
}