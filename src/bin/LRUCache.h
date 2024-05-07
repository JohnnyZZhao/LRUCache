#include "Cache.h"
#include <vector>

class LRUCache : public Cache {
public:
  LRUCache() = delete;
  LRUCache(int capacity) : m_nodes(0), m_index(0) {
    cp = capacity;
    tail = nullptr;
    head = nullptr;
  };

  /// @brief Add the pair of key and value to the cache, if key already exists
  /// then update its value
  /// @param key
  /// @param value
  void set(int key, int value) override;

  /// @brief Get the value of the key
  /// @param key
  int get(int key) override;


protected:
  std::vector<std::pair<int, Node *>> m_nodes;

private:
  int m_index;
};