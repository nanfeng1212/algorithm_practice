#include<bits/stdc++.h>
using namespace std;

int M,N,L,T;
bool s1[62][1288][130];
bool s2[62][1288][130];
struct ty{
    int x,y,z;
};
int single;
int sum = 0;
int direction[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
int main(){
    cin>>M>>N>>L>>T;
    int t;
    for(int i=1; i<=L; i++){
        for(int j=1; j<=M; j++){
            for(int k=1; k<=N; k++){
                cin >> t;
                if(t)
                    s1[i][j][k]=true;
            }
        }
    }
    struct ty n1,n2;
    queue<struct ty>q;
    for(int i=1; i<=L; i++){
        for(int j=1; j<=M; j++){
            for(int k=1; k<=N; k++){
                single=0;
                if(s1[i][j][k]&&!s2[i][j][k]){
                    s2[i][j][k]=true;
                    single++;
                    n1.z=i;
                    n1.x=j;
                    n1.y=k;
                    q.push(n1);
                    while(!q.empty()){
                        n1=q.front();
                        q.pop();
                        for(int l=0; l<6; l++){
                            int nextx=n1.x+direction[l][0];
                            int nexty=n1.y+direction[l][1];
                            int nextz=n1.z+direction[l][2];
                            if(s1[nextz][nextx][nexty]&&!s2[nextz][nextx][nexty]){
                                n2.z=nextz;
                                n2.x=nextx;
                                n2.y=nexty;
                                q.push(n2);
                                single++;
                                s2[nextz][nextx][nexty]=true;
                            }
                        }
                    }
                }
                if(single>=T)
                    sum+=single;
            }
        }
    }
    cout<<sum;
    return 0;
}