//sort array a. for each element in array b, binary search in array a to find the nearest element with -b[j]

#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
int n, a[N], b[N];

void update(int i, int j, int &ans)
{
	if(0<=i && i<n && abs(a[i]+b[j]) < ans)
		ans= abs(a[i]+b[j]);
}

int main()
{
	cin>>n;
	for(int x=0; x<n; x++) cin>>a[x];
	for(int x=0; x<n; x++) cin>>b[x];
	
	sort(a,a+n);
	
	int ans=abs(a[0]+b[0]);
	for(int j=0; j<n; j++)
	{
		//binary search
		int i=lower_bound(a, a+n, -b[j])-a;//pointer
		update(i, j ,ans);
		update(i-1, j, ans);
	}
	cout<<ans;
}
