# TrieContact

A CLI-based Contact Manager implemented in C++ using dual Trie data structures for efficient prefix-based searching.

## Features

- Add Contact
- Delete Contact
- Update Contact
- Search by Name Prefix
- Search by Phone Prefix
- Prefix search using DFS traversal
- Bidirectional mapping using unordered_map
- Menu-driven CLI

## Data Structures Used

- Trie
- DFS
- unordered_map

## Time Complexity

| Operation | Complexity |
|----------|------------|
| Insert | O(L) |
| Search | O(L) |
| Delete | O(L) |
| Prefix Search | O(P + K) |

Where:
- L = length of the word
- P = length of the prefix
- K = number of matching contacts

## Project Structure

```
TrieContact/
│── main.cpp
│── Trie.cpp
│── Trie.h
│── ContactManager.cpp
│── ContactManager.h
```

## Build

```bash
g++ main.cpp Trie.cpp ContactManager.cpp -o TrieContact
```

## Run

```bash
./TrieContact
```

---

Developed using **C++**, **Trie**, **DFS**, and **unordered_map**.