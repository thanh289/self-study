#include <bits/stdc++.h>
using namespace std;

vector<int> st;
vector<pair<int,int> > matches; //luu cap dâu ngoac tuong ung

bool solve(string s)
{	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='(')
			st.push_back(i);	//day dâu ngoac mo vào trong stack
			
		else 
		{
			if(st.empty()) return false; //day không phai dâu ngoac dung
			matches.push_back({st.back(), i}); //tìm môt cap tuong ung
			st.pop_back();
		}
	}
	
	if(!st.empty()) return false; //stack không rông thì day không dung
	return true;
}

int main()
{
	string s; cin>>s;
	cout<<solve(s);
}
