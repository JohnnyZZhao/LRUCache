#include "Cache.h"
#include <vector>


template <typename K = int, typename V = int>
class LRUCache : public Cache<K, V> {
public:
  LRUCache() = delete;
  LRUCache(int capacity) : m_nodes(0), m_index(0) {
    Cache<K, V>::cp = capacity;
    Cache<K, V>::tail = nullptr;
    Cache<K, V>::head = nullptr;
  };

  /// @brief Add the pair of key and value to the cache, if key already exists
  /// then update its value
  /// @param key
  /// @param value
  void set(K key, V value) override;

  /// @brief Get the value of the key
  /// @param key
  V get(K key) override;

protected:
  std::vector<std::pair<int, Node<K, V> *>> m_nodes;

private:
  int m_index;
};

extern template class LRUCache<int, int>;
extern template class LRUCache<int, float>;