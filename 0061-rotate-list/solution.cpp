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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        
        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp->next;
        }

        k=k%len;
        if(k==0) return head;

        ListNode* slow=head,*fast = head;

        for(int i=0;i<k;i++) fast = fast->next;

        while(fast){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* head1 = slow;
        temp = head1;

        while(temp->next!=head1){
            if(temp->next==NULL) temp->next = head;
            temp = temp->next;
        }
        temp->next = NULL;
        return head1;
    }
};
