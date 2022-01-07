//still too hard for me right now;v

#include <bits/stdc++.h>
using namespace std;
const int N=1e5 +2;
const int BLOCK_SIZE =320;
int a[N], lazy[N / BLOCK_SIZE + 2][101];;
int n;

void block_update(int id, int oval, int nval)
{
	for(int i=1; i<=100; i++)
	{
		if(lazy[id][i]==oval)
			lazy[id][i]=nval;
	}
}

void dozary(int id)
{
	int L= id *BLOCK_SIZE;
	int R= min(n-1, (id+1) * BLOCK_SIZE - 1);
	for(int i=L; i<=R; i++)
	{
		a[i]= lazy[id][a[i]];
	}
	
	for(int i=1; i<=100; i++)
		lazy[id][a[i]]= i;
}

void manualUpdate(int L, int R, int oval, int nval)
{
	dozary(R/BLOCK_SIZE);
	for(int i=L; i<=R; i++)
	{
		if(a[i] == oval)
			a[i] == nval;
	}
}

int main()
{
	int l=1,r=6;
	cin>>n;
	//blockL là block dâu tiên bên phai l
	//blockR là block có r
	int blockL = (l + BLOCK_SIZE -1) / BLOCK_SIZE;
	int blockR = r / BLOCK_SIZE;
	int oval=1, nval=2;
	
	for(int i=1; i<=(n/BLOCK_SIZE);i++)
		for(int j=1; j<=100; j++)
			lazy[i][j]=j;
			
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=(n/BLOCK_SIZE);i++)
		block_update(i, oval, nval)
	
	for()
	manualUpdate(l, blockL * BLOCK_SIZE - 1, oval, nval);
	manualUpdate(blockR * BLOCK_SIZE, r, oval, nval);
	
	for(int i=1; i<=n; i++) cout<<a[i]<<" ";
}


