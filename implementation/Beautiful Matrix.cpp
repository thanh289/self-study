#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,k;
	while(cin>>t && !t) k++;
	cout<<abs(k/5-2)+abs(k%5/2)<<endl;
}
