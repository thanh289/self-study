
#include <bits/stdc++.h>
using namespace std;

//way1: doing by my self but time limit 2/18 case
//int const k=10e4+5;
//int n, m, ans, a[k];
//
//bool P(int index, int target)
//{
//	if(a[index]>target)
//		return true;
//	else 
//		return false;
//}
//
//int binary_search(int target)
//{
//	int lo=0, hi=n-1;
//	while(lo<hi)
//	{
//		int mid=(lo+hi)/2+1;
//		if(P(mid, target)==true)
//			hi=mid-1;
//		else 
//			lo=mid;
//	}
//	return lo;
//}
//
//int main()
//{
//	cin>>n>>m;
//	for(int i=0; i<n; i++) cin>>a[i];
//	sort(a,a+n);
//	
//	int r=binary_search(m);
//
//	for(int i=0; i<=r; i++)
//	{
//		for(int j=i+1; j<=r; j++)
//		{
//			int x=m-a[i]-a[j];
//			if(x<=0) 
//				continue;
//			int y=binary_search(x);
//			if(y!=i && y!=j)
//				ans=max(ans, a[i]+a[j]+a[y]);
//			if(ans==m) break;
//		}
//	}
//	cout<<ans;
//}


//way2:
int main()
{
	int n, m; cin>>n>>m;
	vector<int> a;
	for(int i=0; i<n; i++)
	{
		int x; cin>>x;
		a.push_back(x);
	}
	
	sort(a.begin(), a.end());
	
	int ans=a[0]+a[1]+a[2];
	for(int i=2; i<n; i++)
	{
		int s=m-a[i];
		
		int j=i-1; k=0;
		while(k<j)
		{
			while(k<j && a[i]+a[j]>s) j--;
			while(k<j && a[i]+a[j]<s)
			{
				ans= max(ans, a[i]+a[j]+a[k]); k++;
			}
		}
	}
	cout<<ans<<endl;
}
