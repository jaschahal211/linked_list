#include<iostream>
using namespace std;
  struct ListNode {
     int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*slow=head;ListNode*fast=head;
       if (head == NULL || head->next == NULL)
            return NULL;
        while(fast!=NULL &&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*m=head;
        while(m->next!=slow)
        {
            m=m->next;
        }
        m->next=slow->next;
        delete slow;
        return head;

        
    }
};
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if (head == NULL || head->next == NULL)
//             return NULL;

//         ListNode *slow = head, *fast = head;
//         ListNode *prev = NULL;

//         while (fast != NULL && fast->next != NULL) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // delete middle node
//         prev->next = slow->next;
//         delete slow;

//         return head;
//     }
// };
