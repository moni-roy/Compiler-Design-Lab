#include <bits/stdc++.h>
using namespace std;

const int nn = -2; // this for normal
const int nc = -1; // this can not in pattern
const int an = 0; // this can any in pattern
const int zm = 1; // this can zero or more in pattern
const int om = 2; // this can one or more in pattern
const int on = 3; // this can one or not in pattern
const int et = 4; // this can exacty lenght in pattern
const int ek = 5; // this can one time in pattern
const int eta= 6; // this can one character any in pattern
const int neta= 7; // this can not one charater any in pattern

vector<pair<string,pair<int,int> > > sv,RE[1000];

bool check(string s)
{
	int l=s.size(),mn=0,flag=0;
	int  i = 0;
	for(int k=0;k<(int)sv.size();k++){
		string  p = sv[k].first;
		int x = sv[k].second.first;
		int y = sv[k].second.second;
		//~ cout<<p<<" "<<i<<" "<<x<<" "<<y<<" "<<mn<<endl;
		if(y==0){
			if(x==1){
				int f = 0;
				mn=i;
				while(1){
					f=0;
					for(int j=0;j<(int)p.size();j++){
						if(p[j]==s[i] && i<l) {
							i++;
							f=1;
							flag = 1;
						}
					}
					if(!f) break;
				}
				//~ cout<<i<<" "<<mn<<endl;
			}
			if(x==2){
				int f = 0;
				for(int j=0;j<(int)p.size();j++){
					if(p[j]==s[i] && i<l) {
						i++;
						f=1;
					}
				}
				if(!f){
					f=0;
					if(flag){
						for(int j=i;j>=mn;j--){
							for(int jj=0;jj<(int)p.size();jj++){
								if(p[jj]==s[j]) {
									i++;
									f=1;
								}
							}
							if(f){
								i=j;
								break;
							}
						}
					}
					if(!f) return 0;
				}
				mn=i;
				flag=0;
				while(1){
					for(int j=0;j<(int)p.size();j++){
						if(p[j]==s[i] && i<l) {
							i++;
							f=1;
							flag = 1;
						}
					}
					if(!f) break;
				}
			}
			if(x==3){
				
				int f=0;
				for(int j=0;j<(int)p.size();j++){
					if(p[j]==s[i] && i<l) {
						i++;
						f=1;
					}
				}
				if(f){
					flag=0;
					mn=i;
				}
			}
			if(x==5){
				int f = 0;
				for(int j=0;j<(int)p.size();j++){
					if(p[j]==s[i] && i<l) {
						i++;
						f=1;
					}
				}
				mn=i;
				if(!f){
					f=0;
					if(flag){
						for(int j=i;j>=mn;j--){
							for(int jj=0;jj<(int)p.size();jj++){
								if(p[jj]==s[j]) {
									i++;
									f=1;
								}
							}
							if(f){
								i=j;
								break;
							}
						}
					}
					if(!f) return 0;
				}
				mn=i;
				flag=0;
			}
			
		}
		else if(y==-1){
			// let's try if need
			if(x==5){
				int f=0;
				for(int j=0;j<(int)p.size();j++){
					if(s[i]==p[j]) f=1;
				}
				if(f) return 0;
				i++;
			}
		}
		else if(y==-2){
			string pp = s.substr(i,p.size());
			if(x==1){
				while(pp==p){
					i+=p.size();
					pp = s.substr(i,p.size());
				}
			}
			if(x==2){
				//~ cout<<mn<<endl;
				if(pp!=p){
					int f=0;
					if(flag){
						for(int j=i;j>=mn;j--){
							pp=s.substr(j,p.size());
							if(p==pp) f=1;
							if(f){
								i=j;
								break;
							}
						}
					}
					if(!f) return 0;
				}
				mn=i;
				while(pp==p){
					i+=p.size();
					pp = s.substr(i,p.size());
				}
				flag=0;
			}
			if(x==3){
				if(p==pp){
					 i+=p.size();
					 flag=0;
				 }
			}
			if(x==5){
				if(p==pp) i+=p.size();
				else {
					int f=0;
					if(flag){
						for(int j=i;j>=mn;j--){
							pp=s.substr(j,p.size());
							if(p==pp) f=1;
							if(f){
								i=j;
								break;
							}
						}
					}
					if(!f) return 0;
				}
				flag=0;
			}
		}
		else if(x==6){
			string pp = s.substr(i,y);
			for(int j=0;j<y;j++){
				int ff=0;
				for(int jj = 0;jj<(int)p.size();jj++){
					if(pp[j]==p[jj]) ff=1;
				}
				if(ff==0) return 0;
			}
			i+=y;
			flag=0;
		}
		else if(x==7){
			string pp = s.substr(i,y);
			for(int j=0;j<y;j++){
				int ff=0;
				for(int jj = 0;jj<(int)p.size();jj++){
					if(pp[j]==p[jj]) ff=1;
				}
				if(ff==1) return 0;
			}
			i+=y;
			flag=0;
		}
		else if(x==4){
			for(int j=0;j<y;j++){
				string pp=s.substr(i,p.size());
				if(pp==p){
					i+=p.size();
				}
				else return 0;
			}
		}
	}
	if(i!=l) return 0;
	return true;
}

void find(string s){
	string p="",pp="";
	int l=s.size();
	for(int i=0;i<l;){
		if(s[i]=='('){
			int f=0;
			p="";
			for(i=i+1;i<l;i++){
				if(s[i]==')') {
					i++;
					break;
				}
				p+=s[i];
			}
			if(i<=l-1){
				if(s[i]=='*'){
					sv.push_back(make_pair(p,make_pair(zm,-2)));
					i++;
					f=1;
				}
				else if(s[i]=='+'){
					sv.push_back(make_pair(p,make_pair(om,-2)));
					i++;
					f=1;
				}
				else if(s[i]=='?'){
					sv.push_back(make_pair(p,make_pair(on,-2)));
					i++;
					f=1;
				}
			}
			pp="";
			if(s[i]=='{' && i<l-1){
				for(i=i+1;i<l;i++){
					if(s[i]=='}'){
						i++;
						break;
					 }
					pp+=s[i];
				}
				int k = atoi(pp.c_str());
				sv.push_back(make_pair(p,make_pair(et,k)));
				f=1;
			}
			if(!f) sv.push_back(make_pair(p,make_pair(ek,-2)));
			
		}
		else if(s[i]=='['){
			int f=0,fl=0;
			p="";
			for(i=i+1;i<l;i++){
				if(s[i]==']'){
					i++;
					break;
				}
				if(s[i]!='-') p+=s[i];
				else{
					for(int j=s[i-1]+1;j<=s[i+1]-1;j++) p+=(char)(j);
				}
			}
			if(p[0]=='^'){
				p=p.substr(1,p.size()-1);
				fl=1;
			}
			if(i<=l-1){
				if(fl==1){
					if(s[i]=='*'){
						sv.push_back(make_pair(p,make_pair(zm,nc)));
						i++;
						f=1;
					}
					else if(s[i]=='+'){
						sv.push_back(make_pair(p,make_pair(om,nc)));
						i++;
						f=1;
					}
					else if(s[i]=='?'){
						sv.push_back(make_pair(p,make_pair(on,nc)));
						i++;
						f=1;
					}
				}
				else{
					if(s[i]=='*'){
						sv.push_back(make_pair(p,make_pair(zm,an)));
						i++;
						f=1;
					}
					else if(s[i]=='+'){
						sv.push_back(make_pair(p,make_pair(om,an)));
						i++;
						f=1;
					}
					else if(s[i]=='?'){
						sv.push_back(make_pair(p,make_pair(on,an)));
						i++;
						f=1;
					}
				}
			}
			pp="";
			if(s[i]=='{' && i<l-1){
				for(i=i+1;i<l;i++){
					if(s[i]=='}'){
						i++;
						break;
					 }
					pp+=s[i];
				}
				int k = atoi(pp.c_str());
				if(fl) sv.push_back(make_pair(p,make_pair(neta,k)));
				else sv.push_back(make_pair(p,make_pair(eta,k)));
				f=1;
			}
			if(!f)
			{ 
				if(fl) sv.push_back(make_pair(p,make_pair(ek,nc)));
				else sv.push_back(make_pair(p,make_pair(ek,an)));
			}
		}
		else{
			p=s[i];
			i++;
			int f=0;
			if(i<=l){
				if(s[i]=='*'){
					sv.push_back(make_pair(p,make_pair(zm,-2)));
					i++;
					f=1;
				}
				else if(s[i]=='+'){
					sv.push_back(make_pair(p,make_pair(om,-2)));
					i++;
					f=1;
				}
				else if(s[i]=='?'){
					sv.push_back(make_pair(p,make_pair(on,-2)));
					i++;
					f=1;
				}
			}
			pp="";
			if(s[i]=='{' && i<l-1){
				for(i=i+1;i<l;i++){
					if(s[i]=='}'){
						i++;
						break;
					 }
					pp+=s[i];
				}
				int k = atoi(pp.c_str());
				sv.push_back(make_pair(p,make_pair(et,k)));
				f=1;
			}
			if(!f) sv.push_back(make_pair(p,make_pair(ek,-2)));
		}
	}
}

int main()
{
	//~ freopen("input.in","r",stdin);
	//~ freopen("output.out","w",stdout);
	string rg[100],p;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>rg[i];
		find(rg[i]);
		RE[i]=sv;
		for(int j=0;j<(int)sv.size();j++)
		{	
			cout<<sv[j].first<<" "<<sv[j].second.first<<" "<<sv[j].second.second<<endl;
		}
		sv.clear();
	}
	cin>>m;
	while(m--){
		cin>>p;
		vector<int>v;
		for(int i=1;i<=n;i++){
			sv = RE[i];
			if(check(p)){
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
