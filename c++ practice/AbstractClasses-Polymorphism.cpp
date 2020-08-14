#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

//====================================================

class LRUCache : public Cache{
    public:
        LRUCache(int c) {
            cp = c;
            tail = nullptr;
            head = nullptr;
        }
        void set (int x, int y) override {
            if (mp.find(x) != mp.end()) {
                mp[x]->value = y;
            } else {
                mp[x] = new Node(head, nullptr, x,y);
                if (head) head->next = mp[x];
                head = mp[x];
                if (!tail) tail = head;
                if ((int)mp.size() > cp) {
                    mp.erase(tail->key);
                    tail = tail->next;
                    delete tail->prev;
                    tail->prev = nullptr;
                }
            }
        }
        int get (int x) override {
            if (mp.find(x) != mp.end()) {
                if (!mp[x]->prev)
                    tail = mp[x]->next;
                Node* temp = head;
                head = mp[x];
                head->prev = temp;
                head->next = nullptr;
                return mp[x]->value;
            } else 
                return -1;
        }
};

//=================================================

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
