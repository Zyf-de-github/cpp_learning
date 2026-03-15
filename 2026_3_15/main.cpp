// #include <bits/stdc++.h>
// using namespace std;
//
// int main()
// {
//     int a;
//     cin>>a;
//     vector<string> v(a);
//     for (int i=0;i<a;i++)
//     {
//         double n,k,x;
//         int ans=0;
//         cin>>n>>k>>x;
//         if (n==1)
//         {
//             v[i]="inf";
//             continue;
//         }
//         double temp=k*n/1e8;
//         while (temp<x)
//         {
//             ans++;
//             temp*=n;
//         }
//         v[i]=to_string(ans);
//     }
//     for (auto i:v)cout<<i<<endl;
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;
//
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for (int i=0;i<n;i++)
//     {
//         for (int j=0;j<6;j++)
//         {
//             int temp=0;
//             cin>>temp;
//             a[i]=max(a[i],temp);
//         }
//     }
//     sort(a.begin(),a.end(),[&](int a,int b)
//     {
//         return a>b;
//     });
//     for (auto i:a)cout<<i;
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
//
//
// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     vector<int> v(n);
//     int max_num=n,min_num=1;;
//     for (int i=0;i<n;i++)
//     {
//         if (k>=n-1-i)
//         {
//             v[i]=max_num--;
//             k-=n-1-i;
//         }
//         else v[i]=min_num++;
//     }
//     for (auto i:v)cout<<i<<" ";
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

pair<int,int> fenshu_add(pair<int,int> a,pair<int,int> b)
{
    int down=a.second*b.second;
    int up=a.first*b.second+a.second*b.first;
    for (int i=up;i>1;i--)
    {
        if (down%i==0&&up%i==0)
        {
            down/=i;
            up/=i;
        }
    }
    return {up,down};
}
pair<int,int> fenshu_mul(pair<int,int> a,pair<int,int> b)
{
    int down=a.second*b.second;
    int up=a.first*b.first;
    for (int i=up;i>1;i--)
    {
        if (down%i==0&&up%i==0)
        {
            down/=i;
            up/=i;
        }
    }
    return {up,down};
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> a(n+1,{0,1});
    a[0]={1,1};
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[i+1]=fenshu_mul(a[i],{u,v});
    }
    long long temp=a[n].second;
    for (int i=0;i<M;i++)
    {
        temp*=temp;
        temp%=M;
    }
    cout<<a[n].first*temp%M;
    return 0;
}