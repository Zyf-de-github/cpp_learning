// #include <bits/stdc++.h>
// using namespace std;
//
// static bool flag=false;
// void judjement(vector<int> v)
// {
//     int i=0;
//     while (i<10&&v[i]==0){i++;}
//     if (i==10){flag=true;return;}
//     if (v[i]>=3)
//     {
//         v[i]-=3;
//         judjement(v);
//         if (flag)return;
//         v[i]+=3;
//     }
//     if (i<=7&&v[i]>0&&v[i+1]>0&&v[i+2]>0)
//     {
//         v[i]--;
//         v[i+1]--;
//         v[i+2]--;
//         judjement(v);
//         if (flag)return;
//     }
// }
// bool is_ok(vector<int> v)
// {
//     for (int i=1;i<=9;i++)
//     {
//         flag=false;
//         vector<int> temp=v;
//         if (v[i]>=2)
//         {
//             temp[i]-=2;
//             judjement(temp);
//         }
//         if (flag)return true;
//     }
//     return false;
// }
//
// int main()
// {
//     vector<int> v(10),ans;
//     for (int i=0;i<13;i++)
//     {
//         int temp;
//         cin>>temp;
//         v[temp]++;
//     }
//     for (int i=1;i<=9;i++)
//     {
//         if (v[i]==4)continue;
//         vector<int> temp=v;
//         temp[i]++;
//         if (is_ok(temp))ans.push_back(i);
//     }
//     if (ans.empty())cout<<0<<endl;
//     else for (auto i:ans)cout<<i<<" ";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
//
//
// int main()
// {
//     int ans=0,money=0;
//     cin>>money;
//     int num=0;
//     num=1024-money;
//     ans+=num/64;
//     num%=64;
//     ans+=num/16;
//     num%=16;
//     ans+=num/4;
//     num%=4;
//     ans+=num;
//     cout<<ans<<endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++){cin>>v[i];}
    int rptr=100000,lptr=0;
    while (lptr<rptr)
    {
        int mid=(rptr+lptr)/2;
        int temp=mid;
        for (int i=0;i<n;i++)
        {
            if (v[i]>temp)temp-=v[i]-temp;
            else temp+=temp-v[i];
            if (temp<0)break;
        }
        if (temp<0)lptr=mid+1;
        else rptr=mid;
    }
    cout<<lptr<<endl;
    return 0;
}