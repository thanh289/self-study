#include <bits/stdc++.h>
using namespace std;

vector<int> st;
vector<pair<int,int> > matches; //luu cap d�u ngoac tuong ung

bool solve(string s)
{	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='(')
			st.push_back(i);	//day d�u ngoac mo v�o trong stack
			
		else 
		{
			if(st.empty()) return false; //day kh�ng phai d�u ngoac dung
			matches.push_back({st.back(), i}); //t�m m�t cap tuong ung
			st.pop_back();
		}
	}
	
	if(!st.empty()) return false; //stack kh�ng r�ng th� day kh�ng dung
	return true;
}

int main()
{
	string s; cin>>s;
	cout<<solve(s);
}
