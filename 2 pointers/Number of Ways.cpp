#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
long long sum[500005];
int main()
{
	int n; cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	
	if(sum[n]%3!=0)
	{
		cout<<0; return 0;
	}
	
	ll s=sum[n]/3;
	int cnt=0, ans=0;
	for(int i=1; i<n; i++)
	{
		if(sum[i]==s*2) ans+=cnt;
		if(sum[i]==s) cnt++;
	}
	cout<<ans;
}
