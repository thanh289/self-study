#include <bits/stdc++.h>
using namespace std;

string s;
deque<int> dq;
map<char, int> val;

int main()
{
	cin>>s;
	val['O']=16;
	val['C']=12;
	val['H']=1;
	val['(']=-1;
	val[')']=0;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] == '(')
			dq.push_back(val[s[i]]);
			
		else if(s[i]==')')
		{
			int v=val[')'], total=0;
			while(v != val['('])
			{
				v=dq.back();
				dq.pop_back();
				if(v != val['(']) total+=v;
			}
			dq.push_back(total);
		}
		
		//s[i]=='C' || s[i]=='H'|| s[i]=='O'
		else if(s[i]>=65 && s[i]<=90) //C, O, H
			dq.push_back(val[s[i]]);
			
		else	//2->9
		{
			int v=dq.back();
			dq.pop_back();
			dq.push_back(v * (int)(s[i] - '0'));
		}
	}
	
	int ans=0;
	while(dq.size())
	{
		int v=dq.back();
		dq.pop_back();
		ans+=v;
	}
	
	cout<<ans;

return 0;
}
