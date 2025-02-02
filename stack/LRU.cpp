#include<bits/stdc++.h>
using namespace std;

class dll{
public:

    int key,val;
    dll* next;
    dll* prev;
    dll()
    {

    }
    dll(int key, int val)
    {
        this->key = key;
        this->val = val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    dll* head;
    dll* tail;
    int cap,size;
    unordered_map<int,dll*> m; //key to node address

    void deleteNode(dll* node)
    {
        m.erase(node->key);
        size--;
        if(node==head and node==tail)
        {
            head=NULL;
            tail=NULL;
        }
        else if(node == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if(node == tail)
        {
            tail = tail->prev;
            tail->next=NULL;
        }
        else 
        {
            dll* node_next = node->next;
            dll* node_prev = node->prev;

            node_prev->next=node_next;
            node_next->prev=node_prev;
        }
 
    }

    void addNode(dll* node)
    {
        m[node->key] = node;
        node->next = head;
        if(head)head->prev = node;
        head = node;
        if(tail==NULL)tail=node;
        size++;
    }

    LRUCache(int capacity) {

        this->cap = capacity;
        this->size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        
        if(head and head->key == key)
        {
            cout<<head->val;
            return head->val;
        }
        
        if(m.find(key)==m.end())
        {
            cout<<-1<<endl;
            return -1;
        }
        
        dll* node = m[key];
        deleteNode(node);
        addNode(node);
        cout<<head->val;
        return head->val;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end())
        {
            //key exists already
            dll* node = m[key];
            deleteNode(node);

            dll* newnode = new dll(key,value);
            addNode(newnode);
            return;
        }

        if(cap == size)
        {
            deleteNode(tail);
            
        }

        dll* newnode = new dll(key, value);
        addNode(newnode);
        
    }

};



int main()
{
LRUCache* lRUCache = new LRUCache(2);
lRUCache->put(2, 1); // cache is {1=1}
lRUCache->put(2, 2); // cache is {1=1, 2=2}
lRUCache->get(2);    // return 1
// lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache->get(2);    // returns -1 (not found)
// lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache->get(1);    // return -1 (not found)
// lRUCache->get(3);    // return 3
// lRUCache->get(4);    // return 4
}