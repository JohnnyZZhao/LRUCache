#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "LRUCache.h"

using namespace std;


template <typename K, typename V>
void LRUCache<K, V>::set(K key, V value) {
  auto found = Cache<K, V>::mp.find(key);
  if (found == Cache<K, V>::mp.end()) {
    // Not found, insert new key and value
    auto newNode = new Node(key, value);
    Cache<K, V>::mp[key] = newNode;
    m_index++;

    if (Cache<K, V>::head == nullptr) {
      // First node, Initialize
      Cache<K, V>::head = newNode;
      Cache<K, V>::tail = newNode;
    } else {
      newNode->next = Cache<K, V>::head;
      Cache<K, V>::head->prev = newNode;
      Cache<K, V>::head = newNode;
    }
    if (m_index > Cache<K, V>::cp) {
      // overflow, discard the last
      Cache<K, V>::mp.erase(Cache<K, V>::tail->key);
      Cache<K, V>::tail = Cache<K, V>::tail->prev;
      m_index = Cache<K, V>::cp;
    }
  } else {
    // Found,
    auto foundNode = found->second;
    // update the key's value
    foundNode->value = value;

    if (foundNode == Cache<K, V>::tail) {
      // update tail
      Cache<K, V>::tail = foundNode->prev;
    }
    if (foundNode != Cache<K, V>::head) {
      // replace head by found Node
      foundNode->next = Cache<K, V>::head;
      Cache<K, V>::head->prev = foundNode;
      Cache<K, V>::head = foundNode;
    }
  }

  /// Debugging
  // while (m_nodes.size() > cp) {
  //   std::vector<std::pair<int, Node *>> nodesTemp(
  //       std::next(m_nodes.begin()), m_nodes.end()); // What can be wrong?
  //   m_nodes = nodesTemp;
  // }
}

template<typename K, typename V>
V LRUCache<K, V>::get(K key) {
  auto found = Cache<K, V>::mp.find(key);
  if (found == Cache<K, V>::mp.end()) { // Not found
    return -1;
  } else {
    auto foundNode = found->second;

    if (foundNode == Cache<K, V>::tail) {
      // update tail
      Cache<K, V>::tail = foundNode->prev;
      foundNode->prev = nullptr;
    }
    if (foundNode != Cache<K, V>::head) {
      // replace head by found Node
      foundNode->next = Cache<K, V>::head;
      Cache<K, V>::head->prev = foundNode;
      Cache<K, V>::head = foundNode;
    }

    return foundNode->value;
  }
}

template class LRUCache<int, int>;