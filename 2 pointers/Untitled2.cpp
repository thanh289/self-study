#include <bits/stdc++.h>
using namespace std;
int n, ans, i, j; 
int main()
{
	cin>>n;
	int b[n], c[n];
	for(int x=0; x<n; x++) cin>>b[x];
	for(int x=0; x<n; x++) cin>>c[x];
	
	sort(b, b+n); sort(c,c+n);
	j=n-1;
	while(i<=n-1 || j>=0)
	{
		ans=min(ans, abs(b[i]+c[j]));
		if(ans==0)
		{
			cout<<ans; return 0;
		}
		else if(b[i]+c[j]<0) i++;
		else j++;
	}
	cout<<ans;
}
