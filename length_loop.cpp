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
    int findLengthOfLoop(ListNode *head) {
        if (head == NULL) return 0;
        int count=0;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                count=1;
                fast=fast->next;
                while(slow!=fast){
                fast=fast->next;
                count++;
                }
                 return count;
            }
        }
      
        return 0;
 
    }
};

