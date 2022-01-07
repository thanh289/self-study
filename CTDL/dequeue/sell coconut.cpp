#include <bits/stdc++.h>
using namespace std;
int ans=0;

int main()
{
	int n; cin>>n;
	int board[n];
	for(int i=0; i<n; i++) cin>>board[i];
	
	deque <int> dq;
	vector <int> l;
	for(int i=0; i<n; i++)
	{
		while(dq.size() && board[dq.back()] >= board[i]) dq.pop_back();
		int x=-1;
		if(dq.size()) x=dq.back();
		l.push_back(x);
		dq.push_back(i);
	}

	
	dq.clear();
	vector <int> r;
	for(int i=n-1; i>=0; i--)
	{
		while(dq.size() && board[dq.back()] >= board[i]) dq.pop_back();
		int y=n;
		if(dq.size()) y=dq.back();
		r.push_back(y);
		dq.push_back(i);
	}
	reverse(r.begin(), r.end());
	
	for(int i=0; i<n; i++)
	{
		int tem=min(board[i], r[i]-l[i]-1);
		ans=max(ans,tem);
	}
	cout<<ans<<endl;
}
