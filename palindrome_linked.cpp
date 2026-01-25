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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        // Step 1: Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* newhead = reverseLinked(slow->next);

        // Step 3: Compare
        ListNode* left = head;
        ListNode* right = newhead;

        while (right != NULL) {
            if (left->val != right->val) {
                reverseLinked(newhead); // restore list
                return false;
            }
            left = left->next;
            right = right->next;
        }

        // Step 4: Restore list
        reverseLinked(newhead);

        return true;
    }

    ListNode* reverseLinked(ListNode* head) {
        ListNode *r = head, *s = NULL;
        while (r != NULL) {
            ListNode* m = r->next;
            r->next = s;
            s = r;
            r = m;
        }
        return s;
    }
};
