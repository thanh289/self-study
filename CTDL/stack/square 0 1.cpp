//nearly the same with rectangle 0 1
//now we have to find the side of the possible largest square (but 0 or 1 is both OK)

#include <bits/stdc++.h>
using namespace std;
int ans=0;

void solve_rec(int h[], int m)
{
	//smaller than h[i] and the nearest to i to the left
	vector<int> L;
	stack<int> st1;
	for(int i=0; i<m; i++)
	{
		while(st1.size() && h[st1.top()] >= h[i]) st1.pop();
		int x=-1;
		if(st1.size()) x=st1.top();
		L.push_back(x);
		st1.push(i);
	}
	
	//smaller than h[i] and the nearest to i to the right
	vector<int> R;
	stack<int> st2;
	for(int i=m-1; i>=0; i--)
	{
		while(st2.size() && h[st2.top()] >= h[i]) st2.pop();
		int y=m;
		if(st2.size()) y=st2.top();
		R.push_back(y);
		st2.push(i);
	}
	
	//largest area with each i = (Ri-Li-1)& h[i]
	//and then find wut is the largest of all
	for(int i=0; i<m; i++)
	{
		ans=max(ans, min((R[m-i-1]-L[i]-1),h[i]));
	}
}


int main()
{
	int n,m; cin>>n>>m;
	int grid[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) cin>>grid[i][j];
	
	//if we find square with just number 1
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
	
	
	//if we find the square with just number 0
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
