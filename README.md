# Trie Contact Manager

A **CLI-based Contact Manager** built in **C++** using **dual Trie data structures** for efficient prefix-based searching. The application supports contact management through CRUD operations and enables fast lookups by both **name prefix** and **phone number prefix**.

---

## Features

- Add Contact
- Delete Contact
- Update Contact
- Search Contacts by Name Prefix
- Search Contacts by Phone Prefix
- Prefix search using DFS traversal
- Bidirectional contact mapping using `unordered_map`
- Menu-driven Command Line Interface (CLI)

---

## Data Structures Used

- **Trie** – Efficient prefix-based searching
- **Depth First Search (DFS)** – Retrieve all matching contacts from a prefix
- **unordered_map** – Constant-time mapping between names and phone numbers

---

## Project Structure

```
TrieContact/
│── main.cpp
│── Trie.h
│── Trie.cpp
│── ContactManager.h
│── ContactManager.cpp
│── README.md
```

---

## How It Works

### Name Search

```
Input:
Go

Output:
Govind : 7974519229
Gopal  : 9876543210
```

The application traverses the **Name Trie** until the prefix node is found and then performs **DFS** to retrieve all matching contacts.

---

### Phone Search

```
Input:
79

Output:
Govind : 7974519229
```

A separate **Phone Trie** enables efficient prefix-based phone number searches.

---

## Time Complexity

| Operation | Complexity |
|----------|------------|
| Insert Contact | O(L) |
| Search Contact | O(L) |
| Delete Contact | O(L) |
| Prefix Search | O(P + K) |
| HashMap Lookup | O(1) Average |

Where:

- **L** = Length of the contact name or phone number
- **P** = Length of the search prefix
- **K** = Number of matching contacts returned by DFS

---

## Technologies Used

- C++
- Object-Oriented Programming
- Trie
- DFS
- unordered_map
- STL

---

## Build

```bash
g++ main.cpp Trie.cpp ContactManager.cpp -o TrieContact
```

---

## Run

### Windows

```bash
./TrieContact.exe
```

### Linux / macOS

```bash
./TrieContact
```

---

## Learning Outcomes

This project helped me understand:

- Trie implementation from scratch
- Prefix searching
- DFS traversal
- Recursive Trie deletion
- Efficient data organization using hash maps
- Object-Oriented Design in C++

---