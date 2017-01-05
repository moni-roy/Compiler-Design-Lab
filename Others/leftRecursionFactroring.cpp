#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s[100];
	map<int,int>mk;
	vector<int>mp[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		//~ for(int j=0;j<(int)s[i].size();j++){
			if(s[i][0]==s[i][3])
				mk[i]=1;
		//~ }
		int t = (int)s[i][0];
		mp[t].push_back(i);
	}
	cout<<"After Removing Left Recursion: "<<endl;
	for(int i=0;i<n;i++){
		if(mk[i]==0){
			cout<<s[i]<<endl;
		}
		else if(mk[i]==1){
			cout<<(char)s[i][0]<<"->";
			int f=0;
			for(int j=0;j<(int)mp[(int)s[i][0]].size();j++){
				int t= mp[(int)s[i][0]][j];
				if(mk[t]==0){
					if(f) cout<<"|";
					cout<<s[t].substr(3)<<char(s[i][0])<<'\'';
					f=1;
					mk[t]=-1;
				}
			}
			cout<<endl;
			cout<<(char)s[i][0]<<"\'->";
			f=0;
			for(int j=0;j<(int)mp[(int)s[i][0]].size();j++){
				int t= mp[(int)s[i][0]][j];
				if(mk[t]==1){
					if(f) cout<<"|";
					cout<<s[t].substr(4)<<char(s[i][0])<<'\'';
					f=1;
					mk[t]=-1;
				}
			}
			cout<<"|$"<<endl;
			mk[i]=-1;
		}
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
