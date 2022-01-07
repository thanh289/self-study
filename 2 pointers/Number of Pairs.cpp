#include <bits/stdc++.h>
using namespace std;
int t,n,l,r;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		int a[n];
		for(int x=0; x<n; x++) cin>>a[x];
		sort(a,a+n);
		int ans=0;
		for(int i=0; i<n; i++)   //l<a[i]<r -> the number of correct element: (r-a[i]) - (l-a[i])+1
		{
			ans+=(upper_bound(a+i+1, a+n, r-a[i])-lower_bound(a+i+1, a+n, l-a[i]));
		}
		cout<<ans<<endl;
	}
//	int a[]={1,2,3,4,5,6,7,8,9};
//	cout<<upper_bound(a, a+9, 5)-a<<" "<<lower_bound(a, a+9, 5)-a;//5 && 4
}



