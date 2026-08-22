#include "bits/stdc++.h"
using namespace std;


class Solution1 {
public:
    long long countBadPairs(vector<int> nums) {
        map<int,int> m;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=i-nums[i];
            if(m.find(temp)==m.end()&&i!=0)ans=ans+i;
            else ans=ans+i-m[temp];
            m[temp]++;
        }
        return ans;
    }
};
class Solution2 {
public:
    int countNicePairs(vector<int> nums) {
        unordered_map<int,int> m;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i]-func_rev(nums[i]);
            if(m.find(temp)!=m.end())
            {
                ans=ans+m[temp];
                ans%=(int)1e9+7;
            }
            m[temp]++;
        }
        return ans;
    }
private:
    int func_rev(int a)
    {
        string temp=to_string(a);
        reverse(temp.begin(),temp.end());
        return stoi(temp);
    }
};
class Solution3 { // 时间复杂度太大，需要使用线段树或者树状数组优化
public:
    long long numberOfPairs(vector<int> nums1, vector<int> nums2, int diff) {
        map<int,int> m;
        long long ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            int temp=nums1[i]-nums2[i];
            for(auto it:m)
            {
                if(temp+diff>=it.first)ans+=it.second;
            }
            m[temp]++;
        }
        return ans;
    }
};
class Solution4 {
public:
    long long maximumTripletValue(vector<int> numsx) {
        vector<long long>nums(numsx.begin(),numsx.end());
        deque<long long>  dq_k,dq_ij;
        long long curi=nums[0],size=nums.size(),curk=nums[size-1],ans=0;
        for(long long i=1;i<size;i++)
        {
            dq_ij.push_back(curi-nums[i]);
            curi=max(curi,nums[i]);
        }
        for(long long i=size-1;i>=2;i--)
        {
            curk=max(curk,nums[i]);
            dq_k.push_front(curk);
        }
        while(!dq_k.empty())
        {
            ans=max(ans,dq_ij.front()*dq_k.front());
            dq_ij.pop_front();
            dq_k.pop_front();
        }
        return ans;
    }
};



int main() {
    Solution s;
    cout<<s.maximumTripletValue({1,10,3,4,19});
    return 0;
}

