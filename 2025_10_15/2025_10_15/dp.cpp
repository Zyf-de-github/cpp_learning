#if 1

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;

class Solution1 {
public:
    vector<long long>memo;
    int size;
    long long mostPoints(vector<vector<int>>& questions) {
        size = questions.size();
        memo.assign(size, -1);
        return dfs(0, questions);
    }
    long long dfs(int i, vector<vector<int>>& questions)
    {
        if (i >= size)return 0;
        if (memo[i] != -1)return memo[i];
        long long x1 = dfs(i + 1, questions);
        long long x2 = dfs(i + questions[i][1] + 1, questions) + questions[i][0];
        x1 > x2 ? memo[i] = x1 : memo[i] = x2;
        return memo[i];
    }
};
class Solution2 {
public:

    int coinChange(vector<int>& coins, int amount) {
        if (!amount)return 0;
        int size = coins.size();
        vector<int> memo(amount + 1, -1);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++)
        {
            int temp = -1;
            for (auto it : coins)
            {
                if (i - it < 0)break;
                else if (i - it == 0)
                {
                    temp = 1;
                    break;
                }
                else if (memo[i - it] != -1 && temp == -1)temp = memo[i - it]+1;
                else if (memo[i - it] != -1 && temp != -1)temp = min(temp, memo[i - it]+1);
            }
            memo[i] = temp;
        }
        return memo[amount];
    }
};
class Solution3 {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> memo(high + 1, 0);
        for (int i = 1; i <= high; i++)
        {
            long long temp = 0;
            if (i == zero)temp += 1;
            if (i == one)temp += 1;
            if (i - zero > 0)temp += memo[i - zero];
            if (i - one > 0)temp += memo[i - one];
            memo[i] = temp % (1000000000 + 7);
        }
        long long ans = 0;
        for (int i = low; i <= high; i++)
        {
            ans += memo[i];
            ans %= 1000000000 + 7;
        }
        return ans;
    }
};

int main()
{
    Solution2 s;
    vector<int> v = { 1,2,5 };
    s.coinChange(v, 11);
    return 0;
}
#endif