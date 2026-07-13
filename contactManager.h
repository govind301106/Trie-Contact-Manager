#pragma once

#include "Trie.h"
#include <unordered_map>

using namespace std;

class ContactManager{

private:
    Trie nameTrie;
    Trie phoneTrie;

    unordered_map<string,string> nameToPhone;
    unordered_map<string,string> phoneToName;

public:
    void addContact(const string& name,const string& phone);

    void deleteContact(const string& name);

    void updateContact(const string& name,const string& newPhone);

    void searchByName(const string& prefix);

    void searchByPhone(const string& prefix);
};