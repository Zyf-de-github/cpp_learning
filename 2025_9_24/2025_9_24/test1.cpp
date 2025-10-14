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
using namespace std;

class Solution0 {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int ptr1 = 0, ptr2 = 0, size1 = word1.size(), size2 = word2.size();
        while (!(ptr1 == size1 && ptr2 == size2))
        {
            if (ptr1 != size1)
            {
                ans += word1[ptr1];
                ptr1++;
            }
            if (ptr2 != size2)
            {
                ans += word2[ptr2];
                ptr2++;
            }
        }
        return ans;
    }
};
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n)return false;
        unordered_map<char, int>c;
        for (int i = 0; i < m; i++)
        {
            c[s[i]]++;
            c[t[i]]--;
        }
        for (auto it : c)
        {
            if (it.second != 0)return false;
        }
        return true;
    }
};
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        string x;
        int size = s.size();
        for (int i = 0; i < size / 2; i++)
        {
            x += s[i];
            if (size % (i + 1) != 0)continue;
            string temp;
            while (true)
            {
                if (temp.size() == s.size() && temp == s)return true;
                else if (temp.size() > s.size())break;
                temp += x;
            }
        }
        return false;
    }
};
class Solution3 {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)return 0;
            else if (nums[i] < 0)ans *= -1;
        }
        return ans;
    }
};
class Solution4 {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int con = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] != con)return false;
        }
        return true;
    }
};
class Solution5 {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)return true;
        int flag = 0;
        for (int i = 1; i < size; i++)
        {
            if (flag == 0)
            {
                if (nums[i] - nums[i - 1] > 0)flag = 1;
                else if (nums[i] - nums[i - 1] < 0)flag = -1;
            }
            else if (flag == 1)
            {
                if (nums[i] - nums[i - 1] < 0)return false;
            }
            else
            {
                if (nums[i] - nums[i - 1] > 0)return false;
            }
        }
        return true;
    }
};

















int main()
{

    return 0;
}



#endif