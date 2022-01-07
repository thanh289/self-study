#include <bits/stdc++.h>
using namespace std;
const int N=10e6+10;
int n, k, i, j, ans, a[N], c=1;
map<int,int> m;
int main()
{
	cin>>n>>k;
	for(int x=0; x<n; x++) 
	{
		cin>>a[x];
		m[a[x]]++;
	}

	j=n-1; 
	while(i<j)
	{
		if(a[i]+a[j] == k) 
		{
			if(a[i]!=a[j])
			{
				ans+=m[a[j]];
				i++;
			}
			else 
			{
				ans+=m[a[j]]-c;
				i++; c++;
			}
		}
		else if(a[i]+a[j]<k) i++;
		else j--;
	}
	cout<<ans;
}
