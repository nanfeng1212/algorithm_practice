#include<iostream>
using namespace std;
int cal(int n,int m){
    if(n<m)swap(n,m);
    if(n%m==0)return m;
    else return cal(m,n%m);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    cout<<cal(n,m);
    return 0;
}