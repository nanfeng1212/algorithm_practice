#include<iostream>
#include<string.h>
using namespace std;
char z[9],h[9];
void fun(int zl,int zr,int hl,int hr)
{
    if(zl>zr)return ;
    if(zl==zr)
    {
        cout<<z[zr];
        return;
    }
    cout<<h[hr];
    int pos=zl;
    while(z[pos]!=h[hr]&&pos<=zr)pos++;
    fun(zl,pos-1,hl,pos-1-zl+hl);
    fun(pos+1,zr,pos+1-zr+hr-1,hr-1);
    return;
}
int main()
{
    cin>>z>>h;
    int lz=strlen(z);
    int lh=strlen(h);
    fun(0,lz-1,0,lh-1);
    return 0;
}