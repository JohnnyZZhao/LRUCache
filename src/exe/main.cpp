#include "LRUCache.h"
#include "iostream"

using namespace std;

int main() {
  int n, capacity, i;
  cout << "Please provide the Number of operations and the cache's Capacity, "
          "seperated by spaces."
       << endl;

  cin >> n >> capacity;

  LRUCache lruCahce(capacity);

  for (i = 0; i < n; i++) {
    cout << "--------------------------------\n";
    cout << "Please provide the #" << i + 1 << " operation [get|set]" << endl;

    string command;
    cin >> command;
    if (command == "get") {
      cout << "Please provide the key" << endl;

      int key;
      cin >> key;
      cout << lruCahce.get(key) << endl;
    } else if (command == "set") {
      cout << "Please provide the key and the value" << endl;

      int key, value;
      cin >> key >> value;
      lruCahce.set(key, value);
    } else {
      cout << "Invalid Operation!" << endl;
      
      return -1;
    }
  }

  cout << "Operation Finished!" << endl;
  return 0;
}