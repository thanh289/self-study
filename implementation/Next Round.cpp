#include <bits/stdc++.h>
using namespace std;
//gia tri khoi tao la 0
int n, k, i, j, arr[51];
int main()
{
	cin>>n>>k;
	while(n>i)	cin>>arr[i++];
	while(arr[j] && arr[j]>=arr[k-1]) ++j;
	cout<<j<<endl;
}
