#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int a, b, c, d, hoi;
int dif1, dif2;
float tu, mau;

int factorial(int n)
{
	int kq=1;
	for(int i=1; i<=n; i++) kq*=i;
	return kq;
}

int main()
{
	cin>>s1>>s2;
	for(int i=0; i<s1.size(); i++)
	{
		s1[i]=='+'? a++ : b++;
		s2[i]=='+'? c++ : s2[i]=='-'? d++ : hoi++;
	}

 	dif1= a-c; //number of '+' we need 
 	dif2= b-d; //number of '-' we need 
 	mau= 1<<hoi;
 	
	if(dif1>=0 && dif2>=0)
	{ 
		tu=(factorial(hoi)/(factorial(dif1)*factorial(hoi-dif1))); //nCk
		printf("%0.9f",tu/mau);
	}
	else printf("%0.9f",0);
}
