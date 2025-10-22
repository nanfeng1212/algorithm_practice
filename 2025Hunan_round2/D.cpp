#include<bits/stdc++.h>
using namespace std;

int t[100010];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >>t[i];
    sort(t+1,t+1+n);
    int cnt = 1;
    int cur = n/2+1;
    int i=cur-1,j=cur+1;
    int f = 0;
    cout << t[cur] << ' ';
    while (cnt<n) {
        if(!f){
            cout << t[i] << ' ';
            i--;
            f = 1;
        }
        else{
            cout <<t[j] << ' ';
            j++;
            f = 0;
        }
        cnt++;
    }
}