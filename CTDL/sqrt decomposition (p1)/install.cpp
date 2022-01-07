//given array A with N elements
//Q test (l, r,  k) 
//which mean find how many number k in range [l,r]
//A, N, Q <= 1e5
#include <bits/stdc++.h>
using namespace std;

//sqrt(1e5) ~320
const int BLOCK_SIZE =320;
const int N = 1e5 +2 ;

int n;
//each row present each block of array;
int cnt[N / BLOCK_SIZE + 2][N];
int a[N];

//pretreatment
void preprocess()
{
	for(int i=0; i<n; i++)
	{
		cnt[i / BLOCK_SIZE][a[i]]++;
	}
}

int query(int l, int r, int k)
{
	//blockL là block dâu tiên bên phai l
	//blockR là block có r
	int blockL = (l + BLOCK_SIZE -1) / BLOCK_SIZE;
	int blockR = r / BLOCK_SIZE;
	
	//if l and r belong to the same block of array
	if(blockL >= blockR)
		return count(a+l, a+r+1, k);
		
	int sum=0;
	for(int i= blockL; i<blockR; i++)
		sum += cnt[i][k];
		
	//we must check incomplete block at the begin and the and of range[l,r]
	for(int i=l, lim =blockL* BLOCK_SIZE; i<lim; i++)
		if(a[i] == k) sum++;
		
	for(int i=blockR * BLOCK_SIZE; i<=r; i++)
		if(a[i] == k) sum++;
		
	return sum;
}

//in case we need to change an element
void update (int u, int v) //update positon u with value v
{
	int block = u / BLOCK_SIZE;
	cnt[block][a[u]]--;
	a[u]=v;
	cnt[block][a[u]]++;
}
int main()
{
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	preprocess();
	cout<<query(4, 10, 1);
}
