#include <bits/stdc++.h>
using namespace std;

//apply monotonous stack
int main()
{
	int ans=0;
	stack <int> s; //smaller than a[i] to the left
	int n; cin>>n;
	for(int i=0; i<n; i++)
	{
		int x; cin>>x;
		while(!s.empty())
		{
			ans=max(ans, x^s.top());
			if(s.top()>x) break;
			s.pop();	
		}	
		s.push(x);
	}
	cout<<ans;
}
