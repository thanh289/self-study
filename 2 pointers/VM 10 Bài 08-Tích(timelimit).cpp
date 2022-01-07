#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll p; cin>>p;
	ll x=1, y=1;
	ll product=1;
	while(product != p)
	{
		if(p%y!=0)
		{
			y++; x=y;product=1;
		}
		product *= y;y++;
		while(product>p)
		{
			product/=x; x++;
		}
	}
	cout<<x<<" "<<y-1;
}
