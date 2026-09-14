#include <bits/stdc++.h>
using namespace std;



class RangeFreqQuery {
public:
    map<int, vector<int>> mp;
    RangeFreqQuery(vector<int> arr) {
        for(int i=0;i<arr.size();i++)mp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        if(mp.find(value)==mp.end())return 0;
        int ptrl1=0,ptrr1=mp[value].size();
        while(ptrl1<ptrr1)
        {
            int mid=(ptrl1+ptrr1)/2;
            if(mp[value][mid]>=left)ptrr1=mid;
            else ptrl1=mid+1;
        }
        int ptrl2=0,ptrr2=mp[value].size();
        while(ptrl2<ptrr2)
        {
            int mid=(ptrl2+ptrr2)/2;
            if(mp[value][mid]>right)ptrr2=mid;
            else ptrl2=mid+1;
        }
        return ptrl2-ptrl1;
    }
};
class Solution0 {
public:
    long long countFairPairs(vector<int> nums, int lower, int upper) {
        long long ans=0;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-1;i++)
        {
            ans+=func(nums,i+1,size,lower-nums[i],upper-nums[i]);
        }
        return ans;
    }
    long long func(vector<int>& nums,int begin,int end,int lower,int upper)
    {
        long long ptrl1=begin,ptrr1=end;
        while(ptrl1<ptrr1)
        {
            int mid=(ptrr1+ptrl1)/2;
            if(nums[mid]>=lower)ptrr1=mid;
            else ptrl1=mid+1;
        }
        long long ptrl2=begin,ptrr2=end;
        while(ptrl2<ptrr2)
        {
            int mid=(ptrr2+ptrl2)/2;
            if(nums[mid]>upper)ptrr2=mid;
            else ptrl2=mid+1;
        }
        return ptrl2-ptrl1;
    }
};
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> items, vector<int> queries) {
        sort(items.begin(),items.end(),[&](vector<int> a,vector<int> b){
            return a[0]==b[0]?(a[1]<b[1]):a[0]<b[0];
        });
        vector<vector<int>> item_new;
        vector<int> temp=items[0];
        for(int i=1;i<items.size();i++)
        {
            if(temp[0]!=items[i][0])
            {
                item_new.push_back(temp);
                temp[0]=items[i][0];
                temp[1]=max(temp[1],items[i][1]);
            }
            else temp[1]=max(temp[1],items[i][1]);
        }
        item_new.push_back(temp);
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int ptrl=0,ptrr=item_new.size();
            while(ptrl<ptrr)
            {
                int mid=(ptrr+ptrl)/2;
                if(item_new[mid][0]>queries[i])ptrr=mid;
                else ptrl=mid+1;
            }
            if(ptrl>0)ans.push_back(item_new[ptrl-1][1]);
            else ans.push_back(0);
        }
        return ans;
    }
};

int main()
{
    // RangeFreqQuery q({3,4,5,3,3,2,2,2,5,4});
    // q.query(0,3,3);
    Solution s;
    // s.countFairPairs({0,1,7,4,4,5},3,6);
    // s.maximumBeauty({{1,2},{3,2},{2,4},{5,6},{3,5}},{1,2,3,4,5,6});
    // s.maximumBeauty({{10,1000}},{5});
    s.maximumBeauty({{193,732},{781,962},{864,954},{749,627},{136,746},{478,548},{640,908},{210,799},{567,715},{914,388},{487,853},{533,554},{247,919},{958,150},{193,523},{176,656},{395,469},{763,821},{542,946},{701,676}},{885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584});
    return 0;
}