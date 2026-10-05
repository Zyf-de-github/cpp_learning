    #include "bits/stdc++.h"
    using namespace std;

    bool is_back(vector<long long>& v)
    {
        int size=v.size();
        for(int i=0;i<size/2;i++)if(v[i]!=v[size-1-i])return false;
        return true;
    }
    // bool is_back(string v)
    // {
    //     int size=v.size();
    //     for(int i=0;i<size/2;i++)if(v[i]!=v[size-1-i])return false;
    //     return true;
    // }
    bool func(long long n,long long k)
    {
        vector<long long> v;
        string s;
        long long times=0,num=k;
        while(num)
        {
            num*=k;
            times++;
        }
        for(int i=times;i>=0;i--)
        {
            long long temp=(long long)pow(k,i);
            v.push_back(n/temp);
            s=s+to_string(n/temp);
            n%=temp;
        }
        return is_back(v);
        // return is_back(s);
    }
    int main() {
        int n;
        vector<bool> v;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            long long x1,x2;
            cin>>x1>>x2;
            if(x2==1)
            {
                v.push_back(true);
                continue;
            }
            v.push_back(func(x1,x2));
        }
        for(auto it:v)
        {
            if(it)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        return 0;
    }
    