//https://vnoi.info/wiki/algo/data-structures/segment-tree-extend.md
//see for more detail

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int a[N], ST[N];
int n, l, r, i, v;
int h,k;


//truy vân: A(i) = v;
//hàm câp nhât trên cây ST
//câp nhât cây con gôc id cho doan [l, r]
void update(int id, int l, int r, int i, int v)
{
	if(i<l || r<i)
	//i nàm ngoài doan [l,r] nên ta bo qua
		return ;
		
	if(l==r)
	{
		//doan chi gôm 1 phân tu, không có nút con
		ST[id]= v;
		return ;
	}
	
	//goi dê quy xu lí các nút con cua nút id hiên tai
	int mid= (l + r) / 2;
	update(id*2, l, mid, i, v);
	update(id*2 + 1, mid+1, r, i, v);
	
	//câp nhât lai giá tri max cua doan [l, r] theo 2 nút con:
	ST[id] = max(ST[id*2], ST[id*2 + 1]);
} 

//truy vân: tìm max doan [u, v]
int get(int id, int l, int r, int u, int v)
{
	if (v<l || r<u)
		//doan [u, v] không giao voi doan [l, r], nên ta bo qua doan này
		return -INFINITY;
	
	if(u<=l && r<=v)
	//doan [l, r] hoàn toàn chua doan [u, v]
	//ta tra lai thông tin da luu o nút id
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
