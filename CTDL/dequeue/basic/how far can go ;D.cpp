#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int H[n+1];
	deque <int> dq;
	for(int i=1; i<=n; i++) cin>>H[i];
	
	
	dq.clear();
	//L[k]: leftmost of H[k] that H[k] max;
	int L[n+1];
	for (int k = 1; k <= n; k++) 
	{
   		while (dq.size() && H[dq.back()] <= H[k]) dq.pop_back();
    	if (dq.size()) L[k] = dq.back() + 1;
    	else L[k] = k;
    	dq.push_back(k);
	}

	
	dq.clear();
	//R[k]: Rightmost of H[k] that H[k] max;
	int R[n+1];
	for(int k=n; k>=1; k--)
	{
		while(dq.size() && H[dq.back()] <= H[k]) dq.pop_back();
		if (dq.size()) R[k] = dq.back() - 1;
		else R[k] = k;
		dq.push_back(k);
	}

	dq.clear();
	//l[k]: leftmost of H[k] that H[k] min;
	int l[n+1];
	for(int k=1; k<=n; k++)
	{
		while(dq.size() && H[dq.back()] >= H[k]) dq.pop_back();
		if (dq.size()) l[k] = dq.back() + 1;
		else l[k] = k;
		dq.push_back(k);
	}
	
	dq.clear();
	//r[k]: rightmost of H[k] that H[k] min;
	int r[n+1];
	for(int k=n; k>=1; k--)
	{
		while(dq.size() && H[dq.back()] >= H[k]) dq.pop_back();
		if (dq.size()) r[k] = dq.back() - 1;
		else r[k] = k;
		dq.push_back(k);
	}
	
	//creat graph
	vector <vector<int> > G(n+1);
	//way 1
	for(int i=1; i<=n; i++) G[i].push_back(i+1);
	//way 2
	for(int k=1; k<=n; k++)
	{
		if(H[k] < min(H[L[k]-1], H[R[k]+1]) )
			G[L[k]-1].push_back(R[k]+1);
	}
	//way 3
	for(int k=1; k<=n; k++)
	{
		if(H[k] > max(H[l[k]-1], H[r[k]+1]) )
			G[l[k]-1]. push_back(r[k]+1);
	}
	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<G[i].size(); j++)
			cout<<G[i][j]<<" ";
		cout<<"\n";
	}
}

