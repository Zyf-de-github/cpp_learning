#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;



//class Solution {
//public:
//    int sum = 0;
//    int sumOfLeftLeaves(TreeNode* root) {
//        finding(root->left, true);
//        finding(root->right, false);
//        return this->sum;
//    }
//
//private:
//    void finding(TreeNode* mid, bool l_or_r)
//    {
//        if (mid == NULL)
//        {
//            return;
//        }
//        if (mid->left == NULL && mid->right == NULL && l_or_r)
//        {
//            this->sum += mid->val;
//            return;
//        }
//        finding(mid->left, true);
//        finding(mid->right, false);
//    }
//};


class Solution {
public:

    char findTheDifference(string s, string t) 
    {
        int count[26] = { 0 };
        for (auto it : s)
        {
            count[it - 'a']++;
        }
        for (auto it : t)
        {
            count[it - 'a']--;
            if (count[it - 'a'] < 0)
            {
                return it;
            }
        }
        return ' ';
    }

    bool isSubsequence(string s, string t) 
    {
        int i = 0, j = 0;
        for (i=0;i<t.size();i++)
        {
            if (j == s.size())
            {
                return true;
            }
            if (s[j] == t[i])
            {
                j++;
            }
        }
        if (j == s.size())
        {
            return true;
        }
        return false;
    }

    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (auto it : nums)
        {
            s.insert(it);
        }
        if (s.size() < 3)
        {
            return *s.rbegin();
        }
        else
        {
            int i = 0;
            for (auto it = s.rbegin(); it != s.rend(); it++, i++)
            {
                if (i == 2)
                {
                    return *it;
                }
            }
        }
    }


    int longestPalindrome(string s) {
        unordered_map<char, int> myMap;
        for (char c : s) 
        {
            myMap[c]++;
        }
        int length=0;
        int total=0;
        for (const auto& it : myMap) 
        {
            total += it.second;
            if (it.second % 2 == 0)
            {
                length += it.second;
            }
            if (it.second % 2 != 0)
            {
                length += it.second-1;
            }
        }
        if (total > length)
        {
            length += 1;
        }
        return length;
    }


    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size())
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        int size1 = num1.size() - 1;
        int size2 = num2.size() - 1;
        int mid = 0;
        string a;
        for (; size2 >= 0; size2--, size1--)
        {
            int x = num1[size1] - '0' + num2[size2] - '0' + mid;
            mid = 0;
            if (x >= 10)
            {
                mid = 1;
                a = (char)(x - 10 + '0') + a;
            }
            else
            {
                a = (char)(x + '0') + a;
            }
        }
        for (; size1 >= 0; size1--)
        {
            int x = num1[size1] - '0' + mid;
            mid = 0;
            if (x >= 10)
            {
                mid = 1;
                a = (char)(x - 10 + '0') + a;
            }
            else
            {
                a = (char)(x + '0') + a;
            }
        }
        if (mid == 1)
        {
            a = '1' + a;
        }
        return a;
    }

};




int main()
{
    Solution s1;
    //char a = s1.findTheDifference("abcd", "abcde");
    //bool a = s1.isSubsequence("abc", "ahbgdc");
    //int a = s1.longestPalindrome("abccccdd");

    //cout << a;
	return 0;
}