#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(s=="++X" || s=="X++") ans++;
		else ans--;
	}
	cout<<ans;
}
