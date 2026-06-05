/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL || head->next==NULL) return NULL;

        ListNode* temp = new ListNode(1,head);
        ListNode* ptr = head;

        while(ptr && ptr->next){
            ptr = ptr->next->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
