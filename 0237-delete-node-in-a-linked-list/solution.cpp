/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;

        while(node->next){
            node->val = node->next->val;
            node = node->next;
        }

        while(temp->next->next){
            temp = temp->next;
        }
        temp->next = NULL;
    }
};
