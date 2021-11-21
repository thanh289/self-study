#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n=5; int m=6;
	int a[n]={1,3,6,8,10};
	int b[m]={2,6,7,12,14,15};
	
	int i=0, j=0;
	vector <int> ans;
	while(i<n || j<m)
	{
		if(j==m || (a[i]<=b[j] && i<n))
			ans.push_back(a[i++]);
		else ans.push_back(b[j++]);
	}
	
	for(int x=0; x<ans.size(); x++)
		cout<<ans[x]<<endl;
}
