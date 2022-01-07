#include <bits/stdc++.h>
using namespace std;
//do uu tien cac dau 
int priority(char op)
{
	if(op == '+' || op == '-') return 1;
	else return 2;
}

//xu li toan tu, cap nhat truc tiep vao mang val
void process_op(vector<int>& val, char op)
{
	int r=val.back(); val.pop_back();
	int l=val.back(); val.pop_back();
	//we can use "if" instead of "switch"
	switch(op)
	{
		case '+' : val.push_back(l+r); break;
		case '-' : val.push_back(l-r); break;
		case '*' : val.push_back(l*r); break;
		case '/' : val.push_back(l/r); break;
	}
}


//tinh gia  tri bieu thuc tu string	
int evaluate(string s)
{
	vector <int> val; //luu toan hang
	vector <char> op; //luu toan tu
	
	for(int i=0; i<(int)s.size(); i++)
	{
		if(isdigit(s[i]))
		{
			int number=0; //gia tri toan hang dang xet
			while(i<(int)s.size() && isdigit(s[i]))
			{
				number=number*10 + s[i] -'0';
				++i;
			}
			val.push_back(number);
			--i;
		}
		
		//step 1
		else
		{
			char cur_op=s[i]; //toán tu hiên tai
			while(!op.empty() && priority(op.back()) >=priority(cur_op) )
			{
				process_op(val, op.back());
				op.pop_back();
			}
			op.push_back(cur_op);
		}
	}
	
	//step 2
	while(!op.empty())
	{
		process_op(val, op.back());
		op.pop_back();
	}
	return val.back();
}

int main()
{
	string s; cin>>s;
	cout<<evaluate(s);
}


//xet vi du: 2x3-4x5
//	step 1:
// 		(val)        (op)
//		2
//		2			x
//		2;3			x
//		6			x(delete);-  //(priority(x)> priority(-) so we calculate right at that time
//		6;4
//		6;4			-;x
//		6;4;5

//sau step1, các toán tu trong (op) có dô uu tiên sap xep tang dan

//	step 2:
//		(val)		(op)
//		6;4;5		-;x
//		6;20		-;x(delete)
//		-14			-(delete)

