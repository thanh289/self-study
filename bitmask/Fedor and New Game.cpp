#include <bits/stdc++.h>
using namespace std;
int n, m, k, Fedor, ans;
vector <int> v;
int main()
{
	cin>>n>>m>>k;
	for(int i=0; i<m; i++)
	{
		int x; cin>>x;
		v.push_back(x);
	}
	cin>>Fedor;
	for(int i=0; i<m; i++)
		if(__builtin_popcount(v[i] ^ Fedor)<=k) ans++;
	cout<<ans<<endl;
}

