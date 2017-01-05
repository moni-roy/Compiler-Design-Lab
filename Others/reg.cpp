#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{	
	string rg[100],p;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>rg[i];
	}
	cin>>m;
	while(m--){
		cin>>p;
		int f=1;
		for(int i=1;i<=n;i++){
			regex RE(rg[i]);
			if(regex_match(p,RE)){
				cout<<"YES, "<<i<<endl;
				f=0;
			}
		}
		if(f==1) cout<<"NO, 0"<<endl;
	}
	return 0;
}
