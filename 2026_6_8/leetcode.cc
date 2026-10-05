#include <bits/stdc++.h>
using namespace std;

class Solution0 {
public:
    int maxSatisfied(vector<int> customers, vector<int> grumpy, int minutes) {
        int max_customers=0,temp_customers=0,total_customers=0;
        for(int i=0;i<customers.size();i++)
        {
            total_customers+=(grumpy[i]==1?0:customers[i]);
            temp_customers+=(grumpy[i]==1?customers[i]:0);
            if(i-minutes+1>0)temp_customers-=grumpy[i-minutes]==1?customers[i-minutes]:0;
            max_customers=max(max_customers,temp_customers);
        }
        return total_customers+max_customers;
    }
};
class Solution1 {
public:
    int minArrivalsToDiscard(vector<int> arrivals, int w, int m) {
        unordered_map<int,int> mp;
        vector<int> v(arrivals.size(),0);
        int ans=0;
        for(int i=0;i<arrivals.size();i++)
        {
            if(i-w+1>0&&v[i-w])mp[arrivals[i-w]]--;
            if(mp[arrivals[i]]<m)
            {
                mp[arrivals[i]]++;
                v[i]=1;
            }
            else ans++;
        }
        return ans;
    }
};

int main()
{
    // cout<<"hello"<<endl;
    // Solution s;
    // cout<<s.minArrivalsToDiscard({7,3,9,9,7,3,5,9,7,2,6,10,9,7,9,1,3,6,2,4,6,2,6,8,4,8,2,7,5,6},10,1);
    // cout<<s.maxSatisfied({1,0,1,2,1,1,7,5},{0,1,0,1,0,1,0,1},3);
    return 0;
}