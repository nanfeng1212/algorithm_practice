#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
int a[50][50];
int main()
{
    memset(a,0,sizeof(a));
    int n;
    cin >> n;
    a[1][n/2+1]=1;
    int square = n*n;
    int x = 1,y = n/2+1;
    for(int i =2;i<=square;i++){
        if(x==1 && y!=n){
            a[n][y+1]=i;
            x = n;
            y = y+1;
            //continue;
        }
        else if(y==n && x!=1){
            a[x-1][1]=i;
            x =x-1;
            y = 1;
            //continue;
        }
        else if(x==1 && y==n){
            a[x+1][y] = i;
            x = x+1;
            //continue;
        }
        else if(x!=1&&y!=n){
            if(a[x-1][y+1]==0){
                a[x-1][y+1] =i;
                x= x-1;
                y = y+1;
                //continue;
            }
            else{
                a[x+1][y] = i;
                x = x+1;
                //continue;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j =1;j <=n;j++){
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}
