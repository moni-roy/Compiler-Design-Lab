/// write a C program to recognize string
/// under: "a*b+"

#include <bits/stdc++.h>
using namespace std;


bool check(string s){
	int l = s.size();
	int cnt = 0;
	int f = 0,fb = 0;
	if(s[0]=='a'){
		for(int i=0;i<l;i++){
			if(s[i]=='b'){
				fb = 1;
				f = 1;
			}
			if(fb && s[i]!='b') cnt++;
			if(s[i]=='a' || s[i]=='b'){}
			else cnt++;
		}
	}
	else{
		for(int i=0;i<l;i++){
			if(s[i]!='b'){
				cnt++;
			}
			else f=1;
		}
	}
	if(f==0 || cnt ) return false;
	return true;
}

int main()
{
	string s;
	cin>>s;
	if(check(s)) cout<<"Accepted"<<endl;
	else cout<<"Rejected"<<endl;
	main();
	return 0;
}
