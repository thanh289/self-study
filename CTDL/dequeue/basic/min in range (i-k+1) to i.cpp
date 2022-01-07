#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k; cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int minRange[n]; //array store the answer: min in range [i-k+1, i]
	deque <int> dq;
	while(dq.size()) dq.pop_front();
	
	for(int i=0; i<n; i++)
	{
		//delete any element that > a[i]
		while(dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		//push i to the deque
		dq.push_back(i);
		//if the first element in the deque out of range that we need [i-k+1, i] then pop it
		if(dq.front()+k <=i) dq.pop_front();
		if(i>=k-1) minRange[i]=a[dq.front()];
	}
	
	for(int i=k-1; i<n; i++) cout<<minRange[i]<<" ";
	
	//actually, it will be easier for us to consider the for loop from 1->n than from 0->n-1
}
