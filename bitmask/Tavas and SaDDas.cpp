#include <bits/stdc++.h>
using namespace std;
int n, m, a=1;
int main()
{
	cin>>n;	
	while(n>0)
	{
		if(n%7==0) m+=a;
		m+=a;
		n/=10;
		a<<=1; 
	}
	cout<<m<<endl;
}
