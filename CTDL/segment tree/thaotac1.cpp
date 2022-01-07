//https://vnoi.info/wiki/algo/data-structures/segment-tree-extend.md
//see for more detail

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int a[N], ST[N];
int n, l, r, i, v;
int h,k;


//truy v�n: A(i) = v;
//h�m c�p nh�t tr�n c�y ST
//c�p nh�t c�y con g�c id cho doan [l, r]
void update(int id, int l, int r, int i, int v)
{
	if(i<l || r<i)
	//i n�m ngo�i doan [l,r] n�n ta bo qua
		return ;
		
	if(l==r)
	{
		//doan chi g�m 1 ph�n tu, kh�ng c� n�t con
		ST[id]= v;
		return ;
	}
	
	//goi d� quy xu l� c�c n�t con cua n�t id hi�n tai
	int mid= (l + r) / 2;
	update(id*2, l, mid, i, v);
	update(id*2 + 1, mid+1, r, i, v);
	
	//c�p nh�t lai gi� tri max cua doan [l, r] theo 2 n�t con:
	ST[id] = max(ST[id*2], ST[id*2 + 1]);
} 

//truy v�n: t�m max doan [u, v]
int get(int id, int l, int r, int u, int v)
{
	if (v<l || r<u)
		//doan [u, v] kh�ng giao voi doan [l, r], n�n ta bo qua doan n�y
		return -INFINITY;
	
	if(u<=l && r<=v)
	//doan [l, r] ho�n to�n chua doan [u, v]
	//ta tra lai th�ng tin da luu o n�t id
		return ST[id];
}
int main()
{
	cin>>n;
	cin>>l>>r;
	cin>>i>>v;
	cin>>h>>k;
	for(int j=0; j<n; j++) cin>>a[j];
	update(1, l, r, i, v);
	cout<<get(1,l,r,h,k);
}
