#include <bits/stdc++.h>
using namespace std;

void solve(string &a, string &b)
{
	string ans;
	int i=0, j=0, n=a.size(), m=b.size();
	while (i<n || j<m)
	{
		if(j==m || (i<n && a[i]<b[j])) 
			ans+=a[i++];
		else 
			ans+=b[j++];
	}
	cout<<ans<<endl;
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
		string s,a,b; cin>>s;
		for(int x=0; x<s.size(); x++) 
		{
			if(s[x]%2) a+=s[x]; 
			else b+=s[x];
		}
		solve(a,b);	
	}
}
