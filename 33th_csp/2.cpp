/*#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    set<string>a,b;
    for (int i=1; i<=n; i++) {
        string k;
        cin >> k;
        for (int j=0; j<k.size(); j++) {
            if (k[j]>='A'&&k[j]<='Z') k[j] = 'a'+(k[j]-'A');
        }
        a.insert(k);
    }
    for (int i=1; i<=m; i++) {
        string k;
        cin >> k;
        for (int j=0; j<k.size(); j++) {
            if (k[j]>='A'&&k[j]<='Z') k[j] = 'a'+(k[j]-'A');
        }
        b.insert(k);
    }
    set<string> fz;
    set<string>fm = a;
    for (auto i:b) {
        if (a.count(i)) fz.insert(i);
        else fm.insert(i);
    }
    cout << fz.size() << endl;
    cout << fm.size() << endl;

}*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int>a;
map<string,int>b;
map<string,int>c;
string s1,s2;
int main()
{
	int n,m;
	cin >> n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >> s1;
		s2="";
		for(int j=0;j<s1.length();j++)
		{
			char p=s1[j];
			if(p<'a'){
				char c = 'a'+(p-'A');
				s2+=c;
			}
			else s2+=p;
		}
		a[s2]=1;
	}

	for(int i=1;i<=m;i++)
	{
		cin >> s1;
		s2="";
		for(int j=0;j<s1.length();j++)
		{
			char p=s1[j];
			if(p<'a'){
				char c = 'a'+(p-'A');
				s2+=c;
			}
			else s2+=p;
		}

		b[s2]=1;
	}  
	for(std::map<string,int>::iterator i=a.begin();i!=a.end();i++){
		if(b.find(i->first)!=b.end())
			c[i->first]=1;		
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	for(std::map<string,int>::iterator i=a.begin();i!=a.end();i++){
		if(b.find(i->first)==b.end())
			b[i->first]=1;		
	}
	cout<<c.size()<<endl;
	cout<<b.size()<<endl;
	
}