#include "Cache.h"
#include <vector>

class LRUCache : public Cache {
public:
  LRUCache() = default;
  LRUCache(int capacity) {
    head = nullptr;
    tail = nullptr;
    cp = capacity;
    index = 0;
  }

  void set(int key, int value) override;
  int get(int key) override;

protected:
  int index;
  std::vector<std::pair<int, Node *>> nodes;
};