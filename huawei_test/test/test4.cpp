#include <bits/stdc++.h>
using namespace std;

typedef struct prefix 
{
    uint32_t ip;
    int length;
}prefix;
uint32_t ip_count(struct prefix a[], uint32_t n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i].ip==-1)continue;
        for(int j=i+1;j<n;j++)
        {
            if(a[j].ip==-1)continue;
            int times=32-min(a[i].length,a[j].length);
            uint32_t temp_i=a[i].ip,temp_j=a[j].ip;
            temp_i>>times;
            temp_j>>times;
            if(temp_i==temp_j)
            {
                if(a[i].length>=a[j].length)
                {
                    a[i].ip=-1;
                    a[i].length=-1;
                }
                else
                {
                    a[j].ip=-1;
                    a[j].length=-1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].length==-1)continue;
        ans+=pow(2,32-a[i].length);
    }
    return ans;
}
// 192.168.1.0/24
// 192.168.2.0/24
// 192.168.0.0/16
// 10.0.0.0/8


int main()
{
    cout<<"helloworld";
    return 0;
}
