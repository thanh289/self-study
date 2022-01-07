//similar to the one in stack
//if don't understand, can turn back
#include <bits/stdc++.h>
using namespace std;
int ans=0;

//grid nxm
int solve_rec(int h[], int m)
{
	//smaller than h[i] and the nearest to i to the left
	vector <int> L;
	deque <int> dq1;
	dq1.clear();
	for(int i=0; i<m; i++)
	{
		while(dq1.size() && h[dq1.back()] >= h[i]) dq1.pop_back();
		int x=-1;
		if(dq1.size()) x=dq1.back();
		L.push_back(x);
		dq1.push_back(i);
	}
	
	//smaller than h[i] and the nearest to i to the right
	vector <int> R;
	deque <int> dq2;
	dq2.clear();
	for(int i=m-1; i>=0; i--)
	{
		while(dq2.size() && h[dq2.back()] >= h[i]) dq2.pop_back();
		int y=m;
		if(dq2.size()) y=dq2.back();
		R.push_back(y);
		dq2.push_back(i);
	}
	
	//largest area with each i = (Ri-Li-1)& h[i]
	//and then find wut is the largest of all
	for(int i=0; i<m; i++)
		ans=max(ans, (R[m-i-1]-L[i]-1)*h[i]);
}


int main()
{
	int n,m; cin>>n>>m;
	int grid[n][m];
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) cin>>grid[i][j];
	
	//we will consider each row of the grid. 
	//that mean we condier grid k*m (0<=k<n)
	//in each row, if we find 1, consider what is the height of the "column 1"
	//and then do similar to the basic "largest rectangle" in stack.	
	
	//if we find rec with just number 1
	int h1[m];
	for(int i=0; i<m; i++) h1[i]=0;
	
	for(int k=0; k<n; k++)
	{
		for(int j=0; j<m; j++)
		{
			if(grid[k][j]==1) ++h1[j];
			else h1[j]=0;
		}
		solve_rec(h1, m);
	}
	
	
	//if we find the rec with just number 0
	int h0[m];
	for(int i=0; i<m; i++) h0[i]=0;
	
	for(int k=0; k<n; k++)
	{
		for(int j=0; j<m; j++)
		{
			if(grid[k][j]==0) ++h0[j];
			else h0[j]=0;
		}
		solve_rec(h0, m);
	}
	
	cout<<ans<<endl;
}
