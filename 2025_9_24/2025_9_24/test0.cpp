#if 1

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
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

#endif