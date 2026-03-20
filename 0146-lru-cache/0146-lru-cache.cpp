class Node {
public:
    int val;
    int key;
    Node* left;
    Node* right;
    Node(int key, int value) {
        left = NULL;
        right = NULL;
        this->key = key;
        val = value;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> m;
    int size;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        // cout<<"Constructor";
        size = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        Node* t = m[key];
        if(t == tail) {
            return t->val;
        }
        else if(t == head) {
            head = head->right;
            head->left = NULL;
            t->left = tail;
            t->right = NULL;
            tail->right = t;
            tail = t;
        } 
        else{
            t->left->right = t->right;
            t->right->left = t->left;
            tail->right = t;
            t->left = tail;
            t->right = NULL;
            tail = t;
        }
            
        
        return tail->val;
    }
    
    void put(int key, int value) {
        // cout<<"Inside put";
        int sz= m.size();
        if(m.find(key) != m.end()) {
            Node* t = m[key];
            t->val = value;
            get(key);
        }
        else if(sz >= size) {
            if(size == 1) {
                Node* t = head;
                m.erase(t->key);
                delete t;
                t = new Node(key, value);
                head = tail = t;
                m[key] = tail;
            } 
            else {
                Node* t = head;
                head = head->right;
                head->left = NULL;
                t->right = NULL;
                m.erase(t->key);
                delete t;
                t = new Node(key, value);
                tail->right = t;
                t->left = tail;
                tail = t;
                m[key] = tail;
            }
            
        } else if(!tail) {
            head = new Node(key, value);
            tail = head;
            m[key] = tail;
        } else {
            Node* t = new Node(key, value);
            tail->right = t;
            t->left = tail;
            tail = t;
            m[key] = tail;
        }
        // cout<<m[key]->val<<endl;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */