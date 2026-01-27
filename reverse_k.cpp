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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;

        // Step 1: check k nodes
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head;   // less than k nodes
            curr = curr->next;
        }

        // Step 2: reverse first k nodes
        ListNode* prev = NULL;
        ListNode* next = NULL;
        curr = head;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: recursive call for remaining list
        head->next = reverseKGroup(curr, k);

        // Step 4: prev is new head
        return prev;
    }
};
