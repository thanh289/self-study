#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int k=10e6;
int n,x,i,j, arr[k+10];
int main()
{
	cin>>n>>x;
	for(int z=1; z<=n; z++) cin>>arr[z];
	i=1;j=n;
	while(i<j)
	{
		if(arr[i]+arr[j] ==x) 
		{
			cout<<i<<" "<<j<<endl;
			return 0;
		}
		if(arr[i]+arr[j] <x) i++;
		else j--;
	}
	cout<<"No solution"<<endl;
} 
