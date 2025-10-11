#if 1

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
using namespace std;


class StackOfPlates {
public:
    vector<stack<int>> v;
    int num = 0;
    int size;

    StackOfPlates(int cap)
    {
        size = cap;
        if (cap > 0) v.push_back(stack<int>());
    }

    void push(int val) {
        if (v.empty()) {
            v.push_back(stack<int>());
            num = 0;
        }

        if (v[num].size() == size) {
            num++;
            v.push_back(stack<int>());
        }
        v[num].push(val);
    }

    int pop() {
        if (v.empty()) return -1;
        while (!v.empty() && v[num].empty()) {
            v.pop_back();
            num--;
        }

        if (v.empty()) return -1;

        int temp = v[num].top();
        v[num].pop();

        if (v[num].empty()) {
            v.pop_back();
            num--;
        }

        return temp;
    }

    int popAt(int index) {
        if (index < 0 || index >= (int)v.size()) return -1;
        if (v[index].empty()) return -1;

        int temp = v[index].top();
        v[index].pop();

        if (v[index].empty()) {
            v.erase(v.begin() + index);
            num = (int)v.size() - 1;
        }

        return temp;
    }
};
class Solution0 {
public:
    int m;
    int n;
    int num;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        num = image[sr][sc];
        finding(image, sr, sc, newColor);
        return image;
    }

    void finding(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)return;
        if (image[sr][sc] == num)image[sr][sc] = newColor;
        else return;
        if (sr + 1 < m)finding(image, sr + 1, sc, newColor);
        if (sr - 1 >= 0)finding(image, sr - 1, sc, newColor);
        if (sc + 1 < n)finding(image, sr, sc + 1, newColor);
        if (sc - 1 >= 0)finding(image, sr, sc - 1, newColor);
        return;
    }
};
class Solution1 {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        finding("", n, n);//n « £”‡ ˝¡ø
        return ans;
    }
    void finding(string S, int front, int back)
    {
        if (front < 0 || back < 0)return;
        if (front == 0 && back == 0)
        {
            ans.push_back(S);
            return;
        }
        if (front > back)return;
        finding(S + '(', front - 1, back);
        finding(S + ')', front, back - 1);
        return;
    }
};
class Solution2 {
public:
    vector<string> permutation(string S) {
        int size = S.size();//a b c d
        vector<string> ans;
        ans.push_back(S);
        for (int i = 0; i < size - 1; i++)
        {
            int temp = ans.size();
            for (int j = i + 1; j < size; j++)
            {
                for (int k = 0; k < temp; k++)
                {
                    string x = ans[k];
                    swap(x[i], x[j]);
                    ans.push_back(x);
                }
            }
        }
        set<string>temp(ans.begin(), ans.end());
        vector<string> a(temp.begin(), temp.end());
        return a;
    }
};
class Solution3 {
public:
    vector<string> permutation(string S) {
        int size = S.size();//a b c d
        vector<string> ans;
        ans.push_back(S);
        for (int i = 0; i < size - 1; i++)
        {
            int temp = ans.size();
            for (int j = i + 1; j < size; j++)
            {
                for (int k = 0; k < temp; k++)
                {
                    string x = ans[k];
                    swap(x[i], x[j]);
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};
class Solution4 {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i > 24)
            {
                dp[i] = dp[i - 25] + dp[i - 10] + dp[i - 5] + dp[i - 1];
            }
            else if (i > 9)
            {
                dp[i] = dp[i - 10] + dp[i - 5] + dp[i - 1];
            }
            else if (i > 4)
            {
                dp[i] = dp[i - 5] + dp[i - 1];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};
class Solution5 {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int ptr = m + n - 1;
        m = m - 1;
        n = n - 1;
        while (n >= 0)
        {
            if (m == -1 || A[m] < B[n])
            {
                A[ptr] = B[n];
                ptr--;
                n--;
            }
            else
            {
                A[ptr] = A[m];
                ptr--;
                m--;
            }
        }
        return;
    }
};
class Solution6 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }
        for (auto it : m)
        {
            vector<string> temp;
            for (int i = 0; i < it.second.size(); i++)
            {
                temp.push_back(strs[it.second[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};



int main()
{
    Solution4 s;
    cout<<s.waysToChange(26);
    return 0;
}
#endif