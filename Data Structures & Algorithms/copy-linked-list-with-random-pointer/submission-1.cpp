/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Optimal approach is Insert a copy Node in between nodes
        //Firstly build next connections later random connections.
        Node *curr = head;
        while(curr != NULL){
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }
        //Now build random connections
        curr = head;
        while(curr != NULL){
            Node *copy = curr -> next;
            //next node to random is copynode for that
            if(curr->random != NULL) copy->random = curr->random->next;
            else copy->random = NULL;
            curr = curr -> next -> next;
        }
        //Now remove all connections and return head;
        Node *dNode = new Node(-1);
        Node* res = dNode;
        curr = head;
        while(curr != NULL){
            Node* copy = curr->next;
            res->next = copy;
            curr->next = curr->next->next;
            res = res -> next;
            curr = curr -> next;
        }
        return dNode->next;
    }
};
