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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL,*curr = head,*upcoming=NULL;

        while(curr){
            upcoming = curr->next;
            curr->next = prev;
            prev = curr;
            curr = upcoming;
        }

        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        bool recurse = false;
        int nodes = 0;
        ListNode* temp = head;

        while(temp){
            nodes++;
            if(nodes==k){
                recurse = true;
                break;
            }
            temp = temp->next;
        }

        if(!recurse) return head;

        ListNode* head1 = head;
        ListNode* head2 = temp->next;
        temp->next = NULL;

        ListNode* newhead1 = reverse(head1);
        ListNode* newhead2 = reverseKGroup(head2,k);
        head1->next = newhead2;
        return newhead1;
    }
};
