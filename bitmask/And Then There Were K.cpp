#include <bits/stdc++.h>
using namespace std;

//c�ch n�y timelimit
int t, n, a;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=n;
		while(a)
		{
			a&=(n-1); n--;
		}
		cout<<n<<endl;
	}
}


//c�ch kh�c
int t, n;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int m=1;
		while((m<<1) <= n) m<<=1;
		cout<<m-1<<endl;
	}
}

//c�ch kh�c
int t, n;
int main()
{
	for(cin>>t; t--;)
	{
		cin>>n; cout<<(1<<int(log2(n)))-1<<endl;
	}
}
