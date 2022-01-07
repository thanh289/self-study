#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n; cin>>n;
	ll a[n];
	for(ll i=0; i<n; i++) 
		cin>>a[i];
	for(ll i=0; i<n; i++) 
	{
		ll x;cin>>x;
		a[i]-=x;
	}
	sort(a,a+n);
	ll ans=0, c=0, k=n-1;
	while(c<k)
	{
		if(a[c]+a[k]>0)
		{
			ans+=k-c;
			k--;
		}
		else c++;
	}
	cout<<ans;
}
