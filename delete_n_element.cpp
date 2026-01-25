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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode*s=head;
       int count=0;
       if(head==NULL) return NULL;
       while(s!=NULL)
       {
        count++;
        s=s->next;
       }
     ListNode*m=head;
     ListNode*r;
        if (n == count) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
       int length=count-n;
       for(int i=0;i<length;i++)
       {
        r=m;
        m=m->next;
       }
       r->next=m->next;
       delete m;
       return head;
        
    }
};