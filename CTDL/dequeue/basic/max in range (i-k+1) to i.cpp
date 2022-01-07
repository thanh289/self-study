//nearly the same with the min in range
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k; cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int maxRange[n];
	deque<int> dq;
	while(dq.size()) dq.pop_front();
	
	for(int i=0; i<n; i++)
	{
		while(dq.size() && a[dq.back()] <= a[i]) dq.pop_back();
		dq.push_back(i);
		if(dq.front()+k <= i) dq.pop_front();
		if(i>=k-1) maxRange[i] = a[dq.front()];	
	}
	
	for(int i=k-1; i<n; i++) cout<<maxRange[i]<<" ";
}

//if anything u don't understand, please see the min in range (i-k+1) to i.
