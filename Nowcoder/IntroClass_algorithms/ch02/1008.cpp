#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
int n;
int c[100010];
int a[100010];
int b[100010];
int m;
long long cnt = 0;
void sorted(int l, int r, int mid) {
    int p = l, q = mid + 1;
    for (int i = l; i <= r; i++)
    {
        if ((q > r) || (p <= mid && a[p] <= a[q])) b[i] = a[p++];
        else
        {
            cnt += mid - p + 1;
            b[i] = a[q++];
        }
    }
    for (int i = l; i <= r; i++)a[i] = b[i];
}
void sor(int l, int r)
{
    if (l >= r)return;
    int mid = (l + r)/2;
    sor(l, mid);
    sor(mid + 1, r);
    sorted(l, r, mid);
}
int main()
{
    memset(c, -1, sizeof(c));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        c[i]=a[i];
    }

    sor(1, n);
    scanf("%d", &m);
    int k=cnt%2;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int p=(r-l+1)/2;
        if(p&1) k=(k+1)%2;
        if(k==1)cout<<"dislike\n";
        else cout<<"like\n";
}
    return 0;
}