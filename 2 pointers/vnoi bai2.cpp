//given array a have n elements, sort increase. find 2 different index that sum of them equal to x.
//limit: 2<=n<=10e6; 0<=ai, x<=10e9;

#include <bits/stdc++.h>
using namespace std;
const int k=10e6;
int n,x,i,j, arr[k+10];
int main()
{
	cin>>n>>x;
	for(int z=1; z<=n; z++) cin>>arr[z];
	j=n;
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
	cout<<"NO SOLUTION"<<endl;
} 
