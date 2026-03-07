// // #include <iostream>
// // using namespace std;
// // int main()
// // {
// //     cout<<15<<endl;
// //     return 0;
// // }
//
//
// // #include <cmath>
// // #include <iostream>
// // using namespace std;
// // int main()
// // {
// //     int ans=0;
// //     for(int i=1;i<=10000;i++)
// //     {
// //         int temp=1;
// //         int itemp=i;
// //         while(itemp)
// //         {
// //             itemp/=10;
// //             temp*=10;
// //         }
// //         if((i*i*i)%temp==i)ans++;
// //     }
// //     cout<<ans<<endl;
// //     return 0;
// // }
//
//
// // #include <iostream>
// // #include <set>
// // using namespace std;
// // int main()
// // {
// //     // cout<<69*69*69<<endl;
// //     // cout<<69*69<<endl;
// //     set<int> s;;
// //     for (int i=47;i<=100;i++)
// //     {
// //         int flag=1;
// //         int i2=i*i,i3=i2*i;
// //         while (i2)
// //         {
// //             int temp=i2%10;
// //             i2/=10;
// //             if (s.find(temp)!=s.end())
// //             {
// //                 flag=0;
// //                 break;
// //             }
// //             s.insert(temp);
// //         }
// //         while (flag&&i3)
// //         {
// //             int temp=i3%10;
// //             i3/=10;
// //             if (s.find(temp)!=s.end())
// //             {
// //                 flag=0;
// //                 break;
// //             }
// //             s.insert(temp);
// //         }
// //         if (flag==1)
// //         {
// //             cout<<i<<endl;
// //             return 0;
// //         }
// //         else s.clear();
// //     }
// //     return 0;
// // }
//
//
// //
// // #include <iostream>
// // using namespace std;
// // int main()
// // {
// //     int ans=0;
// //     int n=0;
// //     cin>>n;
// //     int gaizi=n;
// //     while(n)
// //     {
// //         ans+=n;
// //         n=gaizi/3;
// //         gaizi%=3;
// //         gaizi+=n;
// //     }
// //     cout<<ans<<endl;
// //     return 0;
// // }
//
//
//
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// int dev_num=1000000007;
//
// int opp(int b)
// {
//     if(b==1)return 4;
//     else if(b==2)return 5;
//     else if(b==3)return 6;
//     else if(b==4)return 1;
//     else if(b==5)return 2;
//     else if(b==6)return 3;//映射到朝下
// }
//
// int main()
// {
//     int num,n;
//     cin>>num>>n;
//     map<int,vector<int>>m;
//     for(int i=0;i<n;i++)
//     {
//         int a,b;
//         cin>>a>>b;
//         m[a].push_back(opp(b));
//         m[b].push_back(opp(a));
//     }
//     vector<vector<int>> dp(num,vector<int>(6));
//     for(int i=0;i<num;i++)
//     {
//         for(int j=0;j<6;j++)
//         {
//             if(i==0)dp[i][j]=4;//初始化第一层
//             else//累加上一层的情况
//             {
//                 if(m.find(j+1)==m.end())//没有排斥限制的情况下
//                 {
//                     int temp=0;
//                     for(int k=0;k<6;k++)temp+=dp[i-1][k];
//                     dp[i][j]=4*temp%dev_num;
//                 }
//                 else//有排斥限制的情况下
//                 {
//                     int temp=0;
//                     for(int k=0;k<6;k++)if(find(m[j+1].begin(), m[j+1].end(), k+1) == m[j+1].end())temp+=dp[i-1][k];
//                     dp[i][j]=4*temp%dev_num;
//                 }
//             }
//         }
//     }
//     int ans=0;
//     for(int i=0;i<6;i++)ans=(ans+dp[num-1][i])%dev_num;
//
//     cout<<ans<<endl;
//     return 0;
// }



// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
//
//
//
// int main()
// {
//     vector<vector<int>> dp(31,vector<int>(10));
//     dp[0][0]=1;
//     for(int i=1;i<=30;i++)
//     {
//         int total=0;
//         for(int j =1;j<10;j++)
//         {
//             total+=dp[i-1][j];
//             dp[i][j]=dp[i-1][j-1];
//         }
//         dp[i][0]=total+dp[i-1][0];
//     }
//     int ans=0;
//     for(int i=0;i<=30;i++)
//     {
//         ans+=dp[i][7];
//     }
//     cout<<ans<<endl;
//     return 0;
// }



// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
//
//
//
// int main()
// {
//     string s;//="1457642162359754645814576421623597546458145764216235975464581457642162359754645814576421623597546458";
//     cin>>s;
//     deque<char> dq;
//     int ans=0;
//     for (int i=0; i<s.size()-1; i++)
//     {
//         char head=s[i];
//         for (int j=i+1; j<s.size(); j++)
//         {
//             dq.push_back(s[j]);
//             if (head>s[j])
//             {
//                 ans++;
//                 continue;
//             }
//             else if (head==s[j])
//             {
//                 deque<char> temp=dq;
//                 while (temp.empty()==false&&temp.front()==temp.back())
//                 {
//                     temp.pop_back();
//                     temp.pop_front();
//                 }
//                 if (temp.empty()||temp.front()>temp.back())ans++;
//             }
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
//
// struct tree
// {
//     int val;
//     vector<int> child;
//     tree(int val):val(val){};
// };
//
// map<int,int> finding(vector<tree>& v,int ptr,map<int,int> color,int& ans)
// {
//     map<int,int> temp,color_temp=color;
//     for (int i=0;i<v[ptr].child.size();i++)
//     {
//         temp=finding(v,v[ptr].child[i],color,ans);
//         for (auto it:temp)color_temp[it.first]+=it.second;
//
//     }
//     color=color_temp;
//     color[v[ptr].val]++;
//     int flag=1;
//     int color_size=-1;
//     for (auto it:color)
//     {
//         if (color_size==-1&&it.second!=0)color_size=it.second;
//         else if (it.second!=0&&color_size!=it.second)
//         {
//             flag=0;
//             break;
//         }
//     }
//     if (flag)ans++;
//     return color;
// }
// int main()
// {
//     int n;
//     // scanf("%d",&n);
//     cin>>n;
//     vector<tree> v(n+1,tree(0));
//     for (int i = 0; i < n; i++)
//     {
//         int c,f;
//         // scanf("%d %d",&c,&f);
//         cin>>c>>f;
//         v[f].child.push_back(i+1);
//         v[i+1].val=c;
//     }
//
//     int ans=0;
//     map<int,int> color;
//     finding(v,1,color,ans);
//     cout<<ans<<endl;
//     return 0;
// }

// 6
// 2 0
// 2 1
// 1 2
// 3 3
// 3 4
// 1 4

// 11
// 1 0
// 2 1
// 3 1
// 2 2
// 2 2
// 3 3
// 3 3
// 1 4
// 1 5
// 2 6
// 1 7


// #include <bits/stdc++.h>
// using namespace std;
//  int main()
//  {
//      int n;
//      cin>>n;
//      vector<int> v;
//      for (int i = 0; i < n; i++)
//      {
//          int temp;
//          cin>>temp;
//          v.push_back(temp);
//      }
//      int ans=0,size=v.size();
//      for (int i=0;i<size;i++)
//      {
//          int x=v[i];
//          for (int j=i;j<size;j++)
//          {
//              if (i!=j)x^=v[j];
//              ans+=x;
//          }
//      }
//      cout<<ans<<endl;
//      return 0;
//  }

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



string addStrings(string num1, string num2) {
	string result;
	int carry = 0;
	int i = num1.size() - 1;
	int j = num2.size() - 1;

	// 从低位到高位相加
	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0) sum += num1[i--] - '0';
		if (j >= 0) sum += num2[j--] - '0';

		carry = sum / 10;           // 进位
		result.push_back(sum % 10 + '0');  // 当前位
	}

	// 反转结果
	reverse(result.begin(), result.end());
	return result;
}
// 比较两个字符串数字的大小
bool isGreaterOrEqual(string& num1, string& num2) {
	if (num1.length() != num2.length())
		return num1.length() > num2.length();
	return num1 >= num2;
}

string subtractStrings(string num1, string num2) {
	// 确保 num1 >= num2
	bool negative = false;
	if (!isGreaterOrEqual(num1, num2)) {
		swap(num1, num2);
		negative = true;
	}

	string result;
	int borrow = 0;
	int i = num1.size() - 1;
	int j = num2.size() - 1;

	while (i >= 0) {
		int digit1 = num1[i--] - '0' - borrow;
		int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

		if (digit1 < digit2) {
			digit1 += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}

		result.push_back((digit1 - digit2) + '0');
	}

	// 去掉前导零
	while (result.size() > 1 && result.back() == '0') {
		result.pop_back();
	}

	if (negative) result.push_back('-');
	reverse(result.begin(), result.end());
	return result;
}
string multiplyStrings(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";

	int len1 = num1.size();
	int len2 = num2.size();
	vector<int> result(len1 + len2, 0);

	// 从低位到高位相乘
	for (int i = len1 - 1; i >= 0; i--) {
		for (int j = len2 - 1; j >= 0; j--) {
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = mul + result[i + j + 1];

			result[i + j] += sum / 10;      // 进位
			result[i + j + 1] = sum % 10;    // 当前位
		}
	}

	// 转换为字符串
	string res;
	for (int num : result) {
		if (!(res.empty() && num == 0)) {  // 跳过前导零
			res.push_back(num + '0');
		}
	}
	return res.empty() ? "0" : res;
}
int main()
{
	//处理输入转为字符串
	string A,B;
	int flag_a=1,flag_b=1;
	cin>>A;
	cin>>B;
	if(A[0]=='-')
	{
		flag_a*=-1;
		string a(A.begin()+1,A.end());
		A=a;
	}
	if(B[0]=='-')
	{
		flag_b*=-1;
		string b(B.begin()+1,B.end());
		B=b;
 	}
	string AaddB;
	string AsubB;
	string ans;
	if (flag_a==flag_b)
	{
		AaddB=addStrings(A,B);
		if (A>B)
		{
			AsubB=subtractStrings(A,B);
			ans=multiplyStrings(AsubB,AaddB);
		}
		else
		{
			AsubB=subtractStrings(B,A);
			ans='-'+multiplyStrings(AsubB,AaddB);
		}
	}
	else
	{
		AsubB=addStrings(A,B);
		if (A>B)
		{
			AaddB=subtractStrings(A,B);
			ans=multiplyStrings(AsubB,AaddB);
		}
		else
		{
			AaddB=addStrings(B,A);
			ans='-'+multiplyStrings(AsubB,AaddB);
		}
	}
	cout<<ans<<endl;
	return 0;
}