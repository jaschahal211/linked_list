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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode*s=head;
        while(s!=NULL)
        {
            v.push_back(s->val);
            s=s->next;
        }
        sort(v.begin(),v.end());
        ListNode*m=head;
        int i=0;
        while(m!=NULL)
        {
            m->val=v[i];
            i++;
            m=m->next;
        }
        return head;
        
    }
};