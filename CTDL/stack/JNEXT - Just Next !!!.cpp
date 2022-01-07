//có hàm next_permuation() tra vê hoán vi có giá tri cao hon giá tri hiên tai
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	stack<int> st;
	vector<int> nsl;	//next smaller to left
	for(int i=0; i<n ;i++)
	{
		while(!st.empty() && a[st.top()] >=a[i]) st.pop();
		nsl.push_back(!st.empty() ? st.top() : -1);
		st.push(i);
	}
	
	int ind=-1, key=-1;
	for(int i=0; i<n; i++)	//find the rightmost nsl for i
	{
		if(ind < nsl[i]) 
		{
			ind=nsl[i];
			key=i;
		}
	}

	if(ind == -1)	//if no nsl print -1
	{
		cout<<-1<<endl;
		return ;
	}
	
	//swap the rightmost nsl[i] and "i"
	swap(a[ind], a[key]);
	
	//sort the element after nsl[i]
	vector <int> tmp;
	for(int i=ind+1; i<n; i++)	tmp.push_back(a[i]);
	sort(tmp.begin(), tmp.end());
	
	for(int i=ind+1; i<n; i++) a[i]=tmp[i-ind-1];
	
	for(int i=0; i<n; i++) cout<<a[i];
	cout<<"\n";
}


int main()
{
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}
