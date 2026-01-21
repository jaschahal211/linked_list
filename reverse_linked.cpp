#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recursion_reverse(head, head, nullptr);
    }

    ListNode* recursion_reverse(ListNode* head, ListNode* curr, ListNode* prev) {
        if (curr == nullptr)
            return prev;   // prev is the new head

        ListNode* m = curr->next;
        curr->next = prev;
        return recursion_reverse(head, m, curr);
    }
};


