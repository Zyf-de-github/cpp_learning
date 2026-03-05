// #include <climits>
// #include <algorithm>
// #include <ctime>
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
//  struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
//
// class Solution1 {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode* dummy = new ListNode(INT_MIN,head);
//         ListNode* ptr=head;
//         ListNode* pre_ptr=dummy;
//         while(ptr)
//         {
//             ListNode* temp=dummy;
//             while(temp->next->val<ptr->val)
//             {
//                 temp=temp->next;
//             }
//             if(temp->next->val>=ptr->val&&temp->next!=ptr)
//             {
//                 pre_ptr->next=ptr->next;
//                 ptr->next=temp->next;
//                 temp->next=ptr;
//                 ptr=pre_ptr->next;
//             }
//             else
//             {
//                 pre_ptr=ptr;
//                 ptr=ptr->next;
//             }
//         }
//         return dummy->next;
//     }
// };
// class Solution {
// public:
//     int numberOfBeams(vector<std::string>& bank) {
//         int ans=0,last_r=0;
//         for(int i=0;i<bank.size();i++)
//         {
//             int temp=0;
//             for(auto it:bank[i])
//             {
//                 if(it=='1')temp++;
//             }
//             if(temp)
//             {
//                 ans+=last_r*temp;
//                 last_r=temp;
//             }
//         }
//         return ans;
//     }
// };
//
//
// int main()
// {
//     // Solution s;
//     // ListNode* a = new ListNode(3);
//     // ListNode* b = new ListNode(3,a);
//     // ListNode* c = new ListNode(1,b);
//     // ListNode* d = new ListNode(2,c);
//     // ListNode* head = new ListNode(4,d);
//     // s.insertionSortList(head);
//     return 0;
// }