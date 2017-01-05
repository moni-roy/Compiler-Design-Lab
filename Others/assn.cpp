#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{	
	freopen("input.in","r",stdin);
	freopen("output2.out","w",stdout);
	string rg[100],p;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>rg[i];
	}
	cin>>m;
	while(m--){
		cin>>p;
		vector<int>v;
		for(int i=1;i<=n;i++){
			regex RE(rg[i]);
			if(regex_match(p,RE)){
				v.push_back(i);
			}
		}
		if(v.size()==0) cout<<p<<" :: None"<<endl;
		else{
			cout<<p<<" :: ";
			for(int i=0;i<(int)v.size();i++){
				cout<<"\""<<rg[v[i]]<<"\" ";
			}
			//~ cout<<endl;
			cout<<endl;
		}
		v.clear();
	}
	return 0;
}
