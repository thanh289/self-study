#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	//smaller than a[i] and the nearest to i to the left
	vector<int> L;
	stack<int> st1;
	for(int i=0; i<n; i++)
	{
		while(!st1.empty() && a[st1.top()] >=a[i]) st1.pop();
		int x=-1;
		if(!st1.empty()) x=st1.top();
		L.push_back(x);
		st1.push(i);
	}
//	for(int i=0; i<n; i++) cout<<L[i]<<" ";


	//smaller than a[i] and the nearest to i to the right 
	vector<int> R;
	stack<int> st2;
	for(int i=n-1; i>=0; i--)
	{
		while(!st2.empty() && a[st2.top()] >= a[i]) st2.pop();
		int y=n;
		if(!st2.empty()) y=st2.top();
		R.push_back(y);
		st2.push(i);
	}

	//largest rectangle with each i is (Ri-Li-1)*Hi	
	int ans=0;
	for(int i=0; i<n; i++)
	{
		ans=max(ans, (R[n-i-1]-L[i]-1)*a[i]);
	}
	cout<<ans ;

}
