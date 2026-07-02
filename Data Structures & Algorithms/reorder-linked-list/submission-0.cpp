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
    ListNode* findMiddle(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps
        }
        return slow; // middle node
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* nextNode = curr->next; // save next
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev
            curr = nextNode;                 // move curr
        }
        return prev; // new head
    }

    void reorderList(ListNode* head) {
        ListNode* slow = findMiddle(head);
        ListNode* second = slow->next;
        slow->next = NULL;
        second = reverseList(second);
        ListNode* first = head;
        while(second != nullptr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
