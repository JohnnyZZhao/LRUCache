#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "LRUCache.h"

using namespace std;

void LRUCache::set(int key, int value) {
  auto found = mp.find(key);
  if (found == mp.end()) {
    // Not found, insert new key and value
    auto newNode = new Node(key, value);
    mp[key] = newNode;
    m_index++;

    if (head == NULL) {
      // First node, Initialize
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    if (m_index > cp) {

      // overflow, discard the last
      mp.erase(tail->key);
      tail = tail->prev;
      m_index = cp;
    }
  } else {
    // Found,
    auto foundNode = found->second;
    // update the key's value
    foundNode->value = value;

    if (foundNode == tail) {
      // update tail
      tail = foundNode->prev;
    }
    if (foundNode != head) {
      // replace head by found Node
      foundNode->next = head;
      head->prev = foundNode;
      head = foundNode;
    }
  }

  /// Debugging
  // while (m_nodes.size() > cp) {
  //   std::vector<std::pair<int, Node *>> nodesTemp(
  //       std::next(m_nodes.begin()), m_nodes.end()); // What can be wrong?
  //   m_nodes = nodesTemp;
  // }
}

int LRUCache::get(int key) {
  auto found = mp.find(key);
  if (found == mp.end()) { // Not found
    return -1;
  } else {
    auto foundNode = found->second;

    if (foundNode == tail) {
      // update tail
      tail = foundNode->prev;
      foundNode->prev = nullptr;
    }
    if (foundNode != head) {
      // replace head by found Node
      foundNode->next = head;
      head->prev = foundNode;
      head = foundNode;
    }

    return foundNode->value;
  }
}
