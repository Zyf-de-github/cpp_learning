#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
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


    int titleToNumber(string columnTitle)
    {
        int len = columnTitle.size();
        int result = 0;
        for (int i = 0; i < len; i++)
        {
            result = result * 26 + (int)(columnTitle[i] - 'A' + 1);
        }
        return result;
    }


    int reverseBits(int n) {
        vector<int> v;
        for (int i = 0; i < 32; i++)
        {
            v.push_back(n % 2);
            n = n / 2;
        }
        int result = 0;
        for (auto it : v)
        {
            result = result * 2 + it;
        }
        return result;
    }

    int hammingWeight(int n) {
        vector<int> v;
        for (int i = 0; i < 32; i++)
        {
            v.push_back(n % 2);
            n = n / 2;
        }
        int result = 0;
        for (auto it : v)
        {
            if (it)
            {
                result += 1;
            }
        }
        return result;
    }

//public:
//        bool isHappy(int n)
//        {
//            this->judge(n);
//            return this->flag;
//        }
//
//private:
//    bool flag = false;
//    int times = 0;
//    void judge(int num)
//    {
//        times += 1;
//        if (times > 100000)
//        {
//            return;
//        }
//        if (num == 1)
//        {
//            flag = true;
//        }
//        else
//        {
//            int next = 0;
//            while (num)
//            {
//                int temp = num % 10;
//                next += temp * temp;
//                num /= 10;
//            }
//            judge(next);
//        }
//        return;
//    }

//ListNode* removeElements(ListNode* head, int val) {
    //    ListNode* my_head = new ListNode();
    //    ListNode* result = my_head;
    //    while (true)
    //    {
    //        if (head == NULL)
    //        {
    //            return result->next;
    //        }
    //        if (head->val == val)
    //        {
    //            head = head->next;
    //        }
    //        else
    //        {
    //            ListNode* temp = new ListNode(head->val);
    //            my_head->next = temp;
    //            my_head = my_head->next;
    //            head = head->next;
    //        }
    //    }
    //}

    bool isIsomorphic(string s, string t) {
        map<char, char> s_t;
        for (int i = 0; i < s.size(); i++)
        {
            if (s_t.find(s[i]) == s_t.end())
            {
                s_t[s[i]] = t[i];
                unordered_set<char> seenValues;
                for (const auto& it : s_t)
                {
                    if (!seenValues.insert(it.second).second)
                    {
                        return false;
                    }
                }
            }
            else
            {
                if (s_t[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isPowerOfThree(int n) {
        if (n <= 0)
        {
            return false;
        }
        while (n != 1)
        {
            if (n != 1 && n % 3 != 0) {
                return false;
            }
            n = n / 3;
        }
        return true;
    }

    vector<int> countBits(int n) {
        vector<int> v1;
        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int n = i;
            while (n)
            {
                if (n % 2)
                {
                    count++;
                }
                n = n / 2;
            }
            v1.push_back(count);
        }
        return v1;
    }

    bool isPowerOfFour(int n) {
        if (n <= 0)
        {
            return false;
        }
        while (n != 1)
        {
            if (n != 1 && n % 4 != 0) {
                return false;
            }
            n = n / 4;
        }
        return true;
    }

    void reverseString(vector<char>& s) {
        int size = s.size();
        for (int i = 0; i < size / 2; i++)
        {
            char temp = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = temp;
        }
    }

    string reverseVowels(string s) {
        int left = 0, right = s.size();
        std::unordered_set<char> s1 = { 'a', 'e', 'i', 'o', 'u','A','E','I','O','U' };
        while (left < right)
        {
            if (!s1.count(s[left]))
            {
                left++;
            }
            if (!s1.count(s[right]))
            {
                right--;
            }
            if (s1.count(s[left]) && s1.count(s[right]))
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        for (auto it : nums1)
        {
            s1.insert(it);
        }
        for (auto it : nums2)
        {
            s2.insert(it);
        }
        auto ptr1 = s1.begin();
        auto ptr2 = s2.begin();
        vector<int> r;
        while (ptr1 != s1.end() && ptr2 != s2.end())
        {
            if (*ptr1 == *ptr2)
            {
                r.push_back(*ptr1);
                if (ptr1 != s1.end()) ptr1++;
                if (ptr2 != s2.end()) ptr2++;
            }
            if (*ptr1 > *ptr2)
            {
                if (ptr2 != s2.end()) ptr2++;
            }
            if (*ptr1 < *ptr2)
            {
                if (ptr1 != s1.end()) ptr1++;
            }
        }
        return r;
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