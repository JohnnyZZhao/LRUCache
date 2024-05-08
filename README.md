# LRUCache

Least recently used (LRU) cache that discards the least recently used item. For example, a LRUCache with a capacity of 2 will discard the first time when a third item is added.

It supports two operations: set and get. 
- Set is to insert a new item with a key or update an existing item if the key is already present.
- Get is to retrieve an existing item with a key. If the key is not present, it gives minus one. (For now, please bare with me that -1 is the default error behavior)

An operated item is ordered as the most recently used item. For example, a LRUCache with capacity of two.
`set(key=0, v0), set(key=1, v1), get(key=0), set(key=2, v2)` 
After above operations, the item associated with key equals 1 is discarded.

## Build and Run

### Build the CLI application:
`mkdir build && cd build && cmake ..`

### Run:
`./build/src/exe/LRUCacheApp`
Follow the prompt message

### (Optional) Build unit tests target
`cmake -DENABLE_UT ..`
It requires googletest

### Run:
`./build/src/test/LRU_Test`