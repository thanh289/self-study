#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n; //n_max=50
		int a[101]={0};
		for(int i=0; i<n; i++)
		{
			int x; cin>>x;
			a[x]++; //count the number of each element
		}
		for(int i=1; i<=100; i++) //i is sum_index
		{
			int cnt=0;
			for(int j=0; j<=i; j++)
			{
				cnt+=min(a[j], a[i-j]); // j and (i-j) is a pair, so cnt is to count the number of pair(i, i-j)
										//but for ex: i=6, when j=2 -> i=j=4 and when j=4 -> i-j=2
										//then pair(2,4) is counted 2 times, so we have to divided by 2
				ans=max(ans, cnt/2);
			}
		}
		cout<<ans<<endl;
	}
}
