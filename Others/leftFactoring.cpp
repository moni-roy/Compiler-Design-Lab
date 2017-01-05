#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s[100],cs[100];
	map<int,int>mk,mc;
	vector<int>mp[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i][0]==s[i][3])
			mk[i]=1;
		int t = (int)s[i][0];
		mp[t].push_back(i);
		mc[t]=1;
	}
	cout<<"After Removing Left Recursion: "<<endl;
	int k=0;
	for(int i=0;i<n;i++){
		if(mk[i]==0){
			cs[k++]=s[i];
		}
		else if(mk[i]==1){
			
			string ss="";
			char tc;
			for(int j='A';j<='Z';j++){
				if(mc[j]==0){
					tc = char(j);
					break;
				}
			}
			for(int j=0;j<(int)mp[(int)s[i][0]].size();j++){
				int t= mp[(int)s[i][0]][j];
				if(mk[t]==0){
					ss=s[i][0];
					ss+="->";
					ss+=s[t].substr(3);
					ss+=tc;
					cs[k++]=ss;
					mk[t]=-1;
					mc[(int)(tc)]=1;
				}
			}
			
			for(int j=0;j<(int)mp[(int)s[i][0]].size();j++){
				int t= mp[(int)s[i][0]][j];
				if(mk[t]==1){
					ss=tc;
					ss+="->";
					ss+=s[t].substr(4);
					ss+=tc;
					cs[k++]=ss;
					mk[t]=-1;
				}
			}
			ss=tc;
			ss+="->#";
			cs[k++]=ss;
			mk[i]=-1;
		}
	}
	for(int i=0;i<k;i++){
		cout<<cs[i]<<endl;
	}
	
	return 0;
}

/*
7
S->E
E->E+F
E->E-F
E->F
F->F*T
F->T
T->n
*/
