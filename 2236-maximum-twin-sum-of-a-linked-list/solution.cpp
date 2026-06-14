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
    int pairSum(ListNode* head) {
        // finding middle
        ListNode* slow = head,*fast = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = NULL;

        ListNode* prev=NULL,*curr = head1,*upcoming = NULL;
        while(curr){
            upcoming = curr->next;
            curr->next = prev;
            prev = curr;
            curr = upcoming;
        }

        head1 = prev;
        int ans = INT_MIN;

        while(head1 && head2){
            ans = max(head1->val + head2->val,ans);
            head1= head1->next;
            head2 = head2->next;
        }

        return ans;

    }
};
