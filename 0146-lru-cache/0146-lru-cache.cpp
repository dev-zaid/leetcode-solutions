class Node {
public:
    int key;
    int value;
    Node *prev, *next;

    Node(int key, int val) {
        this->key = key;
        this->value = val;
        prev = next = NULL;
    }
}; 

class LRUCache{
    unordered_map<int, Node*> activeKeys;

public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity;

    LRUCache(int capacity) {
        // Initialise lly linked list
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Creates a new Node and attaches it to the head
    Node* addNode(int key, int value){
        Node* newNode = new Node(key, value);

        // attach to head
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;

        //update map
        activeKeys[key] = newNode;

        return newNode;
    }

    void delNode(Node* node){
        // detach the old node
        node->prev->next = node->next;
        node->next->prev = node->prev;

        //update map
        activeKeys.erase(node->key);
        
        delete(node);
    }

    /**
    * Move the node to head
    **/
    Node* latestAccessed(Node* node) {    
        // 1. Detach from current position
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // 2. Attach behind head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

        return node;
    }

    int get(int key) {
        if (activeKeys.find(key) == activeKeys.end()) {
            return -1;
        }

        Node* node = latestAccessed(activeKeys[key]);

        // return value
        return node->value;
    }

    void put(int key, int value) {
        if (activeKeys.find(key) != activeKeys.end()) {
            Node* node = latestAccessed(activeKeys[key]);
            node->key = key;
            node->value = value;

            activeKeys[key] = node;
            return;
        }

        //if node not found

        // 1. Check capacity and remove tail
        if(activeKeys.size() >= this->capacity){
            activeKeys.erase(tail->prev->key);
            delNode(tail->prev);
        }

        // 2. Add new node
        Node* node = addNode(key,value);
        activeKeys[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */