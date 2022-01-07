#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, ans;
vector <int> boy, girl;

int main()
{
	int n, m;
	vector <int> boy, girl;
	cin>>n; 
	for(int i=0; i<n;i++)
	{
		int x; cin>>x;
		boy.push_back(x);
	}
	sort(boy.begin(), boy.end());
	
	cin>>m;
	for(int i=0; i<m; i++)
	{
		int x; cin>>x;
		girl.push_back(x);
	}
	sort(girl.begin(), girl.end());
	
	while(i<n && j<m)
	{
		if(abs(boy[i]-girl[j]) <=1)
		{
			ans++; i++; j++;
		}
		
		else if(boy[i]-girl[j] >1) j++;
		else if(girl[j]-boy[i] >1) i++;
	}
	cout<<ans<<endl;
}
