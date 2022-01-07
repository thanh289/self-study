#include <bits/stdc++.h>
using namespace std;
int const k=10e5+10;
int n, t, l, r, sum, ans,a[k];
int main()
{
	cin>>n>>t;
	for(int i=0; i<n; i++) cin>>a[i];
	for(int l=0, r=0; r<n; r++)
	{
		sum+=a[r];
		while(sum>t)
		{
			sum-=a[l++];
		}
		ans=max(ans, r-l+1);
	}
	cout<<ans;
}
