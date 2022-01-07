#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t, n, s, p, c;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n; s=0;
		cin>>p; n--;
		while(n--)
		{
			cin>>c;
			if(p*c>0)
			{
				if(c>p) p=c;
			}
			else
			{
				s+=p; p=c;
			}
		}
		cout<<s+p<<endl;
	}
}
