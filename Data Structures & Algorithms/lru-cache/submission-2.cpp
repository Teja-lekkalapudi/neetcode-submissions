class Node{
public:
    int key;
    int val;
    Node* left;
    Node* right;
    public:
    Node(int key1,int val1){
        key = key1;
        val = val1;
        left = NULL;
        right = NULL;
    }
};
class LRUCache {
public:

    int Capacity = 0;
    unordered_map<int,Node*> cache;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    void deleteNode(Node* node){
        Node* prev = node->left;
        Node* nxt = node->right;
        prev->right = nxt;
        nxt->left = prev;
    }

    void insertAfterHead(Node* node){
        node->right = head->right;
        head -> right = node;
        node->left = head;
        node->right->left = node;
    }

    LRUCache(int capacity) {
        Capacity = capacity;
        head -> right = tail;
        tail -> left = head;
        //clear is the command to completely remove elements in the map
        cache.clear();
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        Node* temp = cache[key];
        deleteNode(temp);
        insertAfterHead(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            // If its already there just update and change it to most recently used
            Node* node = cache[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }   
        else{
            //If not present, we have to insert it into the cache.
            //Check the cache size , if less than capacity insert directly.
            //if greater than or equal to Capacity then remove the lru element.
            if(Capacity <= cache.size()){
                cache.erase(tail->left->key);
                deleteNode(tail->left);
            }
            Node* node = new Node(key,value);
            insertAfterHead(node);
            cache[key] = node;
        }
    }
};
