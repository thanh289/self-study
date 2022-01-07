//phân cuôi bai stack
//print j that the nearest to i, (j<i or j>i and i,j are index of array) and a[j]>a[i]. if can't find return -1
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int a[n]; vector<int> ans;
	for(int i=0; i<n; i++) cin>>a[i];
	
	stack <int> st1;
	for(int i=0; i<n; i++)
	{
		while(!st1.empty() && a[st1.top()] <=a[i])
			st1.pop();
		int x=-1;
		if(!st1.empty())
			x=st1.top();
		ans.push_back(x);
		st1.push(i);
	}
	
	stack<int> st2;
	for(int i=n-1; i>=0; i--)
	{
		while(!st2.empty() && a[st2.top()]<=a[i])
			st2.pop();
		int y=-1;
		if(!st2.empty())
			y=st2.top();
		if(ans[i] ==-1 && y!=-1) ans[i]=y;
		else if(ans[i]-i > y-i && y!=-1) ans[i]=y;
		st2.push(i);
	}
	
	for(int i=0; i<n; i++) cout<<ans[i]<<" ";
}

