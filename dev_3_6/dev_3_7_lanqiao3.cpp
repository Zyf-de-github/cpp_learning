////#include <bits/stdc++.h>
////#define endl '\n'
////using namespace std;
////
////
////
////int main()
////{
////	//处理输入转为字符串 
////	string A,B;
////	int flag_a=1,flag_b=1;
////	cin>>A;
////	cin>>B;
////	if(A[0]=='-')
////	{
////		flag_a*=-1;
////		string a(A.begin()+1,A.end());
////		A=a;
////	}
////	if(B[0]=='-')
////	{
////		flag_b*=-1;
////		string b(B.begin()+1,B.end());
////		B=b;
////	}
////	
////	//处理A和B变为A+B和A-B; 
////	if(flag_a==flag_b)
////	{
////		
////		if(flag_a==-1)
////		{
////			
////		}
////	}
////	else
////	{
////		if(flag_a==1)
////		{
////			if(A>B)
////			{
////				
////			}
////			if(A<B)
////			{
////				
////			}
////		}
////		else
////		{
////			if(A>B)
////			{
////				
////			}
////			if(A<B)
////			{
////				
////			}
////		}
////	}
////	
////	
////	vector<string> v;
////
////	for(int i=B.size()-1;i>=0;i--)
////	{
////		int crr=0;
////		string temp;
////		for(int j=A.size()-1;j>=0;j--)
////		{
////			int x=B[i]-'0'
////		}
////	}
////	return 0;
////}
//
//
//
//
//
#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int val;
    vector<int> child;
    tree(int val):val(val){};
};

map<int,int> finding(vector<tree>& v,int ptr,map<int,int> color,int& ans)
{
    map<int,int> temp,color_temp=color;
    for (int i=0;i<v[ptr].child.size();i++)
    {
        temp=finding(v,v[ptr].child[i],color,ans);
        for (auto it:temp)color_temp[it.first]+=it.second;

    }
    color=color_temp;
    color[v[ptr].val]++;
    int flag=1;
    int color_size=-1;
    for (auto it:color)
    {
        if (color_size==-1&&it.second!=0)color_size=it.second;
        else if (it.second!=0&&color_size!=it.second)
        {
            flag=0;
            break;
        }
    }
    if (flag)ans++;
    return color;
}
int main()
{
    int n;
    // scanf("%d",&n);
    cin>>n;
    vector<tree> v(n+1,tree(0));
    for (int i = 0; i < n; i++)
    {
        int c,f;
        // scanf("%d %d",&c,&f);
        cin>>c>>f;
        v[f].child.push_back(i+1);
        v[i+1].val=c;
    }

    int ans=0;
    map<int,int> color;
    finding(v,1,color,ans);
    cout<<ans<<'\n';
    return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//int add(int a,int b)
//{
//	return a+b;
//}

//int main()
//{
//	int a,b;
//	cin>>a>>b;
//	cout<<a<<b<<'\n';
//	cout<<add(a,b);
//	return 0;
//}
