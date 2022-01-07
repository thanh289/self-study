#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n, a, x, sum=0, ans=-1;; cin>>n>>x;
		for(int i=1; i<=n; i++)
		{
			cin>>a;
			sum+=a;
			if(sum%x) ans=max(ans, max(i,n-i));
		}
		cout<<ans<<endl;
	}
}
