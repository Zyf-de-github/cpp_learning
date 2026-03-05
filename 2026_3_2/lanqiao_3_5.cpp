// #include <iostream>
// using namespace std;
// int main()
// {
//     cout<<15<<endl;
//     return 0;
// }


// #include <cmath>
// #include <iostream>
// using namespace std;
// int main()
// {
//     int ans=0;
//     for(int i=1;i<=10000;i++)
//     {
//         int temp=1;
//         int itemp=i;
//         while(itemp)
//         {
//             itemp/=10;
//             temp*=10;
//         }
//         if((i*i*i)%temp==i)ans++;
//     }
//     cout<<ans<<endl;
//     return 0;
// }


// #include <iostream>
// #include <set>
// using namespace std;
// int main()
// {
//     // cout<<69*69*69<<endl;
//     // cout<<69*69<<endl;
//     set<int> s;;
//     for (int i=47;i<=100;i++)
//     {
//         int flag=1;
//         int i2=i*i,i3=i2*i;
//         while (i2)
//         {
//             int temp=i2%10;
//             i2/=10;
//             if (s.find(temp)!=s.end())
//             {
//                 flag=0;
//                 break;
//             }
//             s.insert(temp);
//         }
//         while (flag&&i3)
//         {
//             int temp=i3%10;
//             i3/=10;
//             if (s.find(temp)!=s.end())
//             {
//                 flag=0;
//                 break;
//             }
//             s.insert(temp);
//         }
//         if (flag==1)
//         {
//             cout<<i<<endl;
//             return 0;
//         }
//         else s.clear();
//     }
//     return 0;
// }


//
// #include <iostream>
// using namespace std;
// int main()
// {
//     int ans=0;
//     int n=0;
//     cin>>n;
//     int gaizi=n;
//     while(n)
//     {
//         ans+=n;
//         n=gaizi/3;
//         gaizi%=3;
//         gaizi+=n;
//     }
//     cout<<ans<<endl;
//     return 0;
// }



#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int dev_num=1000000007;


int main()
{
    int num,n;
    cin>>num>>n;
    map<int,vector<int>>m;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(b==1)b=4;
        else if(b==2)b=5;
        else if(b==3)b=6;
        else if(b==4)b=1;
        else if(b==5)b=2;
        else if(b==6)b=3;//映射到朝下
        m[a].push_back(b);
        m[b].push_back(a);
    }
    vector<vector<int>> dp(num,vector<int>(6));
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(i==0)dp[i][j]=4;//初始化第一层
            else//累加上一层的情况
            {
                if(m.find(j+1)==m.end())//没有排斥限制的情况下
                {
                    int temp=0;
                    for(int k=0;k<6;k++)temp+=dp[i-1][k];
                    dp[i][j]=4*temp%dev_num;
                }
                else//有排斥限制的情况下
                {
                    int temp=0;
                    for(int k=0;k<6;k++)if(find(m[j+1].begin(), m[j+1].end(), k+1) == m[j+1].end())temp+=dp[i-1][k];
                    dp[i][j]=4*temp%dev_num;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<6;i++)ans=(ans+dp[num-1][i])%dev_num;

    cout<<ans<<endl;
    return 0;
}