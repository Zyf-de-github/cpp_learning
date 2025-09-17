#if 1

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <new>
#include <stack>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    ListNode* ptr1;
    int flag = 0;
public:
    bool isPalindrome(ListNode* head) {
        ptr1 = head;
        if (head == nullptr)return true;
        finding(head);
        if (flag)return false;
        return true;
    }
    void finding(ListNode* head)
    {
        if (head->next != nullptr) finding(head->next);
        //if (head == ptr1 || head->next == ptr1)return;
        if (!flag)
        {
            if (head->val != ptr1->val)
            {
                flag = 1;
            }
            ptr1 = ptr1->next;
        }
    }

    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)return NULL;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while (slow != fast)
        {
            if (fast->next != NULL && fast->next->next != NULL) fast = fast->next->next;
            else
            {
                return NULL;
            }
            slow = slow->next;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    ListNode* temp2 = new ListNode(2);
    temp->next = temp2;
    temp = temp->next;
    temp2 = new ListNode(2);
    temp->next = temp2;
    temp = temp->next;
    temp2 = new ListNode(1);
    temp->next = temp2;
    temp = temp->next;
    
    Solution s;
    s.isPalindrome(head);
    return 0;
}

#endif