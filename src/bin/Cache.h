#include <map>

using namespace std;

template<typename K = int, typename V = int>
struct Node {
  Node *next;
  Node *prev;
  V value;
  K key;
  Node(Node *p, Node *n, K k, V val)
      : prev(p), next(n), key(k), value(val){};
  Node(K k, V val) : prev(NULL), next(NULL), key(k), value(val){};
};

// Abstract Cache
template<typename K = int, typename V = int>
class Cache {
protected:
  map<int, Node<K, V> *> mp;            // map the key to the node in the linked list
  int cp;                         // capacity
  Node<K, V> *tail;                     // double linked list tail pointer
  Node<K, V> *head;                     // double linked list head pointer
  virtual void set(K, V) = 0; // set function
  virtual V get(K) = 0;       // get function
};