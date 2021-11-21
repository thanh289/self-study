#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//cách 1: timelimit	
//set <ll> s;	
//ll n,m;
//ll sum1, sum2, ans, x;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	
//
//	cin>>n;
//	for(int i=0; i<n; i++) 
//	{
//		cin>>x;
//		sum1+=x;
//		s.insert(sum1);
//	}
//	
//	cin>>m; 
//	for(int i=0; i<m; i++) 
//	{
//		cin>>x;
//		sum2+=x;
//		if(s.count(sum2)) ans++;
//	}
//	cout<<((sum1==sum2)?ans:-1);	
//}

//cách 2
#define  z() for(ll i=0, r; i<n; i++)
#define k(i) scanf("%lld", &i)

ll n,s1,s2,ans;
map<ll,ll> m;
int main()
{
	k(n); z(){k(r); m[s1+=r]++;}
	k(n); z(){k(r); ans+=m[s2+=r];}
	cout<<((s1!=s2)?-1:ans);
}

//cách 3 (chi tiêt cách trên)
//ll n,s1,s2,ans;
//map<ll,ll> m;
//int main()
//{
//	cin>>n;
//	for(int i=0; i<n; i++)
//	{
//		int x; cin>>x; m[s1+=x]++;
//	}
//	cin>>n;
//	for(int i=0; i<n; i++)
//	{
//		int x; cin>>x; ans+=m[s2+=x];
//	}
//	cout<<((s1!=s2)?-1:ans);
//}
