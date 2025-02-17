#include<iostream>
using namespace std;
int n; int cnt = 0;
int a[2010];
int b[2010];
void sorted1(int l, int mid, int r)
{
    int p = l, q = mid+1;
    for (int i = l; i <= r; i++)
    {
        if ((q >r)|| (p <= mid && a[p] <= a[q]))b[i] = a[p++];
        else {
            cnt+=mid-p+1;
            b[i] = a[q++];
        }
    }
    for (int i = l; i <= r; i++)a[i] = b[i];
}
void sorted(int l, int r)
{
    if (l == r)return;
    int mid = (l + r) / 2;
    sorted(l, mid);
    sorted(mid+1, r);
    sorted1(l, mid, r);
}
int main()
{
    cin >> n; 
    for (int i = 1; i <= n; i++)cin >> a[i];
    sorted(1, n);
    cout << cnt<<endl;
    return 0;
}