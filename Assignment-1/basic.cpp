#include <bits/stdc++.h>
using namespace std;

string keyWords[]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

bool MathOP(string s){
	if(s=="+") return true;
	if(s=="++") return true;
	if(s=="-") return true;
	if(s=="-") return true;
	if(s=="=") return true;
	if(s=="*") return true;
	if(s=="/") return true;
	if(s=="%") return true;
	if(s=="&") return true;
	if(s=="|") return true;
	if(s=="^") return true;
	return false;
}
bool LogicOP(string s){
	if(s=="==") return true;
	if(s=="<=") return true;
	if(s==">=") return true;
	if(s==">") return true;
	if(s=="<") return true;
	if(s=="!") return true;
	if(s=="!=") return true;
	if(s=="&&") return true;
	if(s=="||") return true;
	return false;
}

bool KeyWord(string s){
	for(int i=0;i<32;i++){
		if(keyWords[i]==s) return true;
	}
	return false;
}
bool Others(char c){
	if(c==';') return true;
	if(c==',') return true;
	if(c==')') return true;
	if(c=='(') return true;
	if(c=='"') return true;
	if(c=='{') return true;
	if(c=='}') return true;
	if(c==']') return true;
	if(c=='[') return true;
	return false;
}
bool NumericValue(string s){
	int f = 0;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='E'||s[i]=='e'){
			if(i==0) return false;
			else if(s[i-1]=='.') return false;
			if(i==(int)(s.size()-1)) return false;
			else if(s[i+1]=='+' || s[i+1]=='-') i++;
			if(i==(int)(s.size()-1)) return false;
			f=1;
		}
		else if(s[i]>='0' && s[i]<='9'){}
		else if(s[i]=='.'){
			if(f) return false;
		}
		else return false;
	}
	return true;
}

bool Identifier(string s){
	if(s[0]>='0' && s[0]<='9') return false;
	for(int i=0;i<(int)s.size();i++){
		if(isalpha(s[i]) || (s[i]>='0' && s[i]<='9')||s[i]=='_'){}
		else return false;
	}
	return true;
}
	
int main () {
	ifstream is("input.txt");  
	set<string>key,id,math,logic,unrecognized;
	set<char>other;
	vector<string>number; 
	char c;
	string s="";
	while (is.get(c)){
		if(c=='\n' || c == ' ' || c=='\t'){
			//~ cout<<c<<"+"<<s<<endl;
			if(s!=""){
				if(KeyWord(s)){
					key.insert(s);
				}
				else if(MathOP(s)){
					math.insert(s);
				}
				else if(LogicOP(s)){
					logic.insert(s);
				}
				else if(NumericValue(s)){
					number.push_back(s);
				}
				else if(Identifier(s)){
					id.insert(s);
				}
				else unrecognized.insert(s);
				s="";	
			}
		}
		else if(Others(c)){
			//~ cout<<c<<"+"<<s<<endl;
			other.insert(c);
			if(s!=""){
				if(KeyWord(s)){
					key.insert(s);
				}
				else if(MathOP(s)){
					math.insert(s);
				}
				else if(LogicOP(s)){
					logic.insert(s);
				}
				else if(NumericValue(s)){
					number.push_back(s);
				}
				else if(Identifier(s)){
					id.insert(s);
				}
				else unrecognized.insert(s);
				s="";
			}
		}
		else{
			if((c>='0'&&c<='9')||isalpha(c)){
				if(s!=""){
					if(MathOP(s)){
						math.insert(s);
						s="";
					}
					else if(LogicOP(s)){
						logic.insert(s);
						s="";
					}
				}
			}
			string cp = "";
			cp+=c;
			if(MathOP(cp) || LogicOP(cp)){
				if(s!=""){
					if(Identifier(s)){
						id.insert(s);
						s="";
					}
				}
			}
			s+=c;
			//~ cout<<c<<"==="<<s<<endl;
		}
		
		if(s=="/*"){
			while(is.get(c)){
				if(c=='*'){
					is.get(c);
					if(c=='/'){
						 unrecognized.insert(s);
						 s="";
						 break;
					 }
				}
			}
		}
		if(s=="//"){
			while(is.get(c)){
				if(c=='\n'){
					unrecognized.insert(s);
					s="";
					break;
				}
			}
		}
	}
	is.close();
	
	/**OUTPUT**/
	cout<<"Keywords :";
	set<string>::iterator it;
	for(it = key.begin();it!=key.end();it++)
	{
		if(it==key.begin()) cout<<" "<<*it;
		else cout<<", "<<*it;
	}
	cout<<endl;
	cout<<"Identifiers :";
	for(it = id.begin();it!=id.end();it++)
	{
		if(it==id.begin()) cout<<" "<<*it;
		else cout<<", "<<*it;
	}
	cout<<endl;
	cout<<"Math Operators :";
	for(it = math.begin();it!=math.end();it++)
	{
		if(it==math.begin()) cout<<" "<<*it;
		else cout<<", "<<*it;
	}
	cout<<endl;
	cout<<"Logical Operators :";
	for(it = logic.begin();it!=logic.end();it++)
	{
		if(it==logic.begin()) cout<<" "<<*it;
		else cout<<", "<<*it;
	}
	cout<<endl;
	cout<<"Numerical Values :";
	for(int i=0;i<(int)number.size();i++){
		if(i==0) cout<<" "<<number[i];
		else cout<<", "<<number[i];
	}
	cout<<endl;
	cout<<"other :";
	set<char>::iterator ii;
	for(ii = other.begin();ii!=other.end();ii++)
	{
		if(ii==other.begin()) cout<<" "<<*ii;
		else cout<<*ii;
	}
	cout<<endl<<endl;
	cout<<"Unrecognized :";
	for(it = unrecognized.begin();it!=unrecognized.end();it++)
	{
		if(it==unrecognized.begin()) cout<<" "<<*it;
		else cout<<", "<<*it;
	}
	cout<<endl;
	
	return 0;
}
