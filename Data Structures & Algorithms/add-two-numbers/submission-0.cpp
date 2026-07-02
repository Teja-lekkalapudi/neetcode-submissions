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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        int carry = 0;
        while(curr1 != NULL || curr2 != NULL){
            int sum = carry;
            if(curr1) sum += curr1->val;
            if(curr2) sum += curr2->val;
            carry = sum/10;
            sum = sum%10;
            ListNode* res = new ListNode(sum);
            temp->next = res;
            temp = temp->next;
            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
        }
        if(carry){
            ListNode* res = new ListNode(carry);
            temp->next = res;
        }
        return dNode -> next ;
    }
};
