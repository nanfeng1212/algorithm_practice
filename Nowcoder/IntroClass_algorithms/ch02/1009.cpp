#include<iostream>
using namespace std;
int n;
int cnt;
void fun(char a,char b,char c,int n)
{
    if(n==0)return ;
    fun(a,b,c,n-1);
    cnt++;
    fun(c,b,a,n-1);
    cnt++;
    fun(a,b,c,n-1);
}
int main()
{
    while(scanf("%d", &n) != EOF){
        cnt=0;
        fun('a','b','c',n);
        cout<<cnt<<endl;
    }
}