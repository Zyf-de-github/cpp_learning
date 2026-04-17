#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCircleNum1(vector<vector<int>> isConnected) {
        int n=isConnected.size();
        vector<int> is_used(n,0);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(is_used[i])continue;
            set<int>s;
            deque<int>dq;
            s.insert(i);
            dq.push_back(i);
            while(dq.empty()==false)
            {
                int temp=dq.front();
                dq.pop_front();
                for(int j=0;j<n;j++)
                {
                    if(isConnected[temp][j]&&s.find(j)==s.end())
                    {
                        dq.push_back(j);
                        s.insert(j);
                    }
                }
            }
            vector<int>temp;
            while(s.empty()==false)
            {
                temp.push_back(*s.begin());
                is_used[*s.begin()]=1;
                s.erase(s.begin());
            }
            ans.push_back(temp);
        }
        return ans.size();
    }
    int findCircleNum(vector<vector<int>> isConnected) {
        int n=isConnected.size();
        vector<int>v(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i])continue;
            dfs(isConnected,v,i);
            ans++;
        }
        return ans;
    }
    void dfs(vector<vector<int>>& isConnected,vector<int>& v,int num)
    {
        if(v[num])return;
        v[num]=1;
        for(int i=0;i<v.size();i++)
        {
            if(isConnected[num][i])dfs(isConnected,v,i);
        }
        return;
    }
};
class Solution2 {
public:
    int maximumDetonation(vector<vector<int>> bombs) {
        int n=bombs.size();
        vector isConnected(n,vector(n,0));
        for(int i=0;i<n;i++)
        {
            isConnected[i][i]=1;
            for(int j=i+1;j<n;j++)
            {
                float dist = pow(bombs[i][0]-bombs[j][0],2)+pow(bombs[i][1]-bombs[j][1],2);
                float x=sqrt(dist);
                if(bombs[i][2]>=x)isConnected[i][j]=1;
                if(bombs[j][2]>=x)isConnected[j][i]=1;
            }
        }
        int max_ans=0;
        for(int i=0;i<n;i++)
        {
            set<int>s;
            deque<int>dq;
            s.insert(i);
            dq.push_back(i);
            while(dq.empty()==false)
            {
                int temp=dq.front();
                dq.pop_front();
                for(int j=0;j<n;j++)
                {
                    if(isConnected[temp][j]&&s.find(j)==s.end())
                    {
                        s.insert(j);
                        dq.push_back(j);
                    }
                }
            }
            max_ans=max(max_ans,(int)s.size());
        }
        return max_ans;
    }
};
class Solution3 {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> queries) {
        int size=queries.size();
        vector dp(size+1,vector(n,0));
        map<int,vector<int>>m;
        for(int i=0;i<=size;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i==0)dp[i][j]=dp[i][j-1]+1;
                else 
                {
                    if(m.find(j)!=m.end())
                    {
                        for(auto it:m[j])
                        {
                            if(dp[i][j]==0)dp[i][j]=min(dp[i][j-1]+1,dp[i][it]+1);
                            else dp[i][j]=min(dp[i][j],dp[i][it]+1);
                        }           
                    }
                    else dp[i][j]=dp[i][j-1]+1;
                }
            }
            if(i!=size)m[queries[i][1]].push_back(queries[i][0]);
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)ans.push_back(dp[i+1][n-1]);
        return ans;
    }
};

int main()
{
    cout<<"ok"<<endl;
    // Solution s;
    // s.findCircleNum({{1,1,0},{1,1,0},{0,0,1}});
    // Solution2 s;
    // s.maximumDetonation({{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}});
    // Solution3 s;
    // s.shortestDistanceAfterQueries(5,{{2,4},{0,2},{0,4}});
    return 0;
}