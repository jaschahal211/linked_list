#include<iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> v;
        if (!head) return v;

        // left pointer at head
        ListNode* left = head;

        // right pointer at tail
        ListNode* right = head;
        while (right->next != NULL) {
            right = right->next;
        }

        // two-pointer approach
        while (left != right && right->next != left) {
            int sum = left->val + right->val;

            if (sum == target) {
                v.push_back({left->val, right->val});
                left = left->next;      // MOVE BOTH
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return v;
    }
};

