#include "contactManager.h"
#include "Trie.h"
#include<bits/stdc++.h>

using namespace std;

void ContactManager::addContact(const string& name,const string& phone){

    if(nameToPhone.count(name)){
        cout<<"Contact already exists.\n";
        return;
    }

    nameTrie.insert(name);
    phoneTrie.insert(phone);

    nameToPhone[name]=phone;
    phoneToName[phone]=name;
}

void ContactManager::deleteContact(const string& name){

    if(!nameToPhone.count(name)){
        cout<<"Contact not found.\n";
        return;
    }

    string phone=nameToPhone[name];

    nameTrie.remove(name);
    phoneTrie.remove(phone);

    nameToPhone.erase(name);
    phoneToName.erase(phone);

    cout<<"Contact deleted.\n";
}

void ContactManager::updateContact(const string& name,const string& newPhone){

    if(!nameToPhone.count(name)){
        cout<<"Contact not found.\n";
        return;
    }

    string oldPhone=nameToPhone[name];

    phoneTrie.remove(oldPhone);

    phoneTrie.insert(newPhone);

    phoneToName.erase(oldPhone);

    phoneToName[newPhone]=name;

    nameToPhone[name]=newPhone;

    cout<<"Contact updated.\n";
}

void ContactManager::searchByName(const string& prefix){

    vector<string> names=nameTrie.startsWith(prefix);

    if(names.empty()){
        cout<<"No contacts found.\n";
        return;
    }

    for(auto &name:names){
        cout<<name<<" : "<<nameToPhone[name]<<endl;
    }
}

void ContactManager::searchByPhone(const string& prefix){

    vector<string> phones=phoneTrie.startsWith(prefix);

    if(phones.empty()){
        cout<<"No contacts found.\n";
        return;
    }

    for(auto &phone:phones){
        cout<<phoneToName[phone]<<" : "<<phone<<endl;
    }
}