//my way

//#include <bits/stdc++.h>
//using namespace std;
//int n, i, j, a[1010], S, D;
//int main()
//{
//	cin>>n;
//	for(int x=0; x<n; x++) cin>>a[x];
//	j=n-1;
//	while(i<=j)
//	{
//		if(a[i]>a[j])
//		{
//			S+=a[i]; a[i]=0; i++;
//		}
//		
//		else
//		{
//			S+=a[j]; a[j]=0; j--;
//		}
//			
//		if(a[i]>a[j])
//		{
//			D+=a[i]; a[i]=0; i++;
//		}
//		
//		else
//		{
//			D+=a[j]; a[j]=0; j--;
//		}
//	}
//	cout<<S<<" "<<D<<endl;
//}

//other way

#include <bits/stdc++.h>
using namespace std;
int v[1000], a[2];
int main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	int c=0, k=n-1;
	for(int i=0;i<n;i++)
	{
		if(v[c]<v[k]) a[i%2]+=v[k--];
		else a[i%2]+=v[c++];
	}
	cout<<a[0]<<" "<<a[1];
}
