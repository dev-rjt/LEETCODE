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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head,*slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                temp->next = head1;
                head1 = head1->next;
            }
            else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if(head1!=NULL) temp->next = head1;
        if(head2!=NULL) temp->next = head2;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* mid = findMiddle(head);
        ListNode* head1 = head;
        ListNode* head2 = mid->next;
        mid->next = NULL;

        head1 = sortList(head1);
        head2 = sortList(head2);
        head = merge(head1,head2);
        return head;
    }
};
