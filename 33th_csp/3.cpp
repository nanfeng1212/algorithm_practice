#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[45];
double a[45][45];
map<string,int>mp;
map<string,int>sx;
int cnt1=0,cnt2=0;
void slove(){
	int m;
	cin >> m;
	cnt1=0,cnt2=0;
	sx.clear();
	for(int i=1;i<=m;i++) {
		string s;
		cin >> s;
		int sum=0;
		string c="";
		mp.clear();
		int flag=0;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]>='a') {
				if (flag) {
					flag=0;
					mp[c]+=sum;
					sum=0;
					if(sx.find(c)==sx.end())
					{
						cnt1++;
						sx[c]=cnt1;
					}
					c="";	
				}
				c+=s[j];
			}
			else {
				flag=1;
				sum=sum*10+s[j]-'0';
			}
		}
		mp[c]+=sum;
		if(sx.find(c)==sx.end())
		{
			cnt1++;
			sx[c]=cnt1;
		}

		for(std::map<string,int>::iterator k=mp.begin();k!=mp.end();k++)
		{
			int x = sx[k->first];
			a[x][i]=k->second;
		}			
	}	
			
	int x=1,y=1;
	while(x<=cnt1&&y<=m)
	{
		int flag=0;
		int j;
		while(1&&y<=m){
			int flag1 = 0;
			for(j=x;j<=cnt1;j++)
			{
				if(fabs(a[j][y])>1e-6){
					flag1 = 1;
					break;
				}
			}
            if (flag1==0)y++;
            else break;
		}
		if (y>m)break;
		for(int k=y;k<=m;k++) {
			double temp1=a[x][k];
			a[x][k]=a[j][k];
			a[j][k]=temp1;
		}
		for(int k=x+1;k<=cnt1;k++) {
			if(fabs(a[k][y])<=1e-6) continue;
			double d1=a[k][y]/a[x][y];
			for(int q=y;q<=m;q++)
				a[k][q] -= a[x][q]*d1;
		}
		x++,y++;
	}
	
	int rank=0;
	for(int j=1;j<=cnt1;j++)
	{
		int flag2=0;
		for(int k=1;k<=m;k++)
			if(fabs(a[j][k])>1e-6)
			{
				flag2=1;
				break;
			}
		if(flag2)
			rank++;
	}
	if(rank<m)cout<<'Y'<<endl;
	else cout<<'N'<<endl;	
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=44;j++)
		{
			for (int k=0; k<=44; k++) a[j][k] = 0;
		}
		slove();
	}
}
