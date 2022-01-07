#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,t,a[310];
int main()
{
	cin>>t;
	while(t--)
	{
		int n; cin>>n;
		for(i=j=0; j<n; j++) cin>>a[j];
		for(k=0; i<j; k++)
		{
			if(k%2) cout<<a[--j]<<" ";
			else cout<<a[i++]<<" ";
		}
		cout<<endl;
	}
}
