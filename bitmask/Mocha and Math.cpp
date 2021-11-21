#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans; cin>>ans; n--;
		while(n--)
		{
			int x; cin>>x;
			ans&=x;
		}
		cout<<ans<<endl;
	}
}
