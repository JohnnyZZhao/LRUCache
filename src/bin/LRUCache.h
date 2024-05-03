#include "Cache.h"
#include <vector>

class LRUCache : public Cache {
public:
  LRUCache() = default;
  LRUCache(int capacity) : m_nodes(0), m_index(0) {
    cp = capacity;
    tail = nullptr;
    head = nullptr;
  };

  void set(int key, int value) override;
  int get(int key) override;

protected:
  std::vector<std::pair<int, Node *>> m_nodes;

private:
  int m_index;
};