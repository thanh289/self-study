#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	//dk bài cho (idk wut to do:vv)
	int x; cin>>x;
	if(x==0)
	{
		stack<int> st;
		int k=1;
		for(int i=0; i<n; i++)
		{
			while(!st.empty() && st.top()==k)
			{
				k++; st.pop();
			}
			if(a[i]!=k) st.push(a[i]);
			else k++;
		}
	
		while(!st.empty() && st.top()==k)
			{
				k++; st.pop();
			}
		
		(k==n+1) ? cout<<"yes" : cout<<"no" ;
	}
	
	else return 0;
}
