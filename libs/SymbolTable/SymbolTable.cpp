#include "SymbolTable.h"

SymbolTable* SymbolTable::symTab = nullptr;

//Constructor
SymbolTable::SymbolTable(){
    std::map<std::string, TableEntry> map;
    std::map<std::string, TableEntry> mapSub;
    //idx = 0;
    
    subLv = 0; //depth into subroutines, 0 for main and 1 for subroutine


    //parserActions.pdf pg 2 : "we do not have nested subroutines or functions"
}

SymbolTable::~SymbolTable() {
    map.clear();
    mapSub.clear();
    symTab = nullptr;
}

//possibly creates then returns singleton
SymbolTable* SymbolTable::getInstance(){
    if(symTab == nullptr) {
        symTab = new SymbolTable();
    }
    return symTab;
}

void SymbolTable::push(std::string str, TableEntry te) {
    if (subLv == 0) {
        map.insert(std::pair<std::string, TableEntry>(str, te));
    }
    else {
        mapSub.insert(std::pair<std::string, TableEntry>(str, te));
    }
    
}

//returns table entry at last key match
TableEntry SymbolTable::getData(std::string key) {
    std::map<std::string, TableEntry>::iterator it;
    if (!mapSub.empty()) {
        it = mapSub.find(key);
        if (it != mapSub.end()) {
            return it->second;
        }
    }
    if (!map.empty()) {
        it = map.find(key);
        if (it != map.end()) {
            return it->second;
        }
    }
    return TableEntry(-99, -99);
}

TableEntry SymbolTable::getDataFromSub(std::string key) {
    std::map<std::string, TableEntry>::iterator it;
    if (!mapSub.empty()) {
        it = mapSub.find(key);
        if (it != mapSub.end()) {
            return it->second;
        }
    }
    return TableEntry(-99, -99);
}

void SymbolTable::enterSubroutine() {
    subLv++;
}

//erases subroutine symbols and decrements the subLv
void SymbolTable::exitSubroutine() {
    mapSub.clear(); //BE CAREFUL THAT YOU DONT CLEAR IT BEFORE YOU NEED IT
    subLv--;
}


//return the current subroutine level
int SymbolTable::getSubLv() { 
    return subLv;
}

//set the current subroutine level
void SymbolTable::setSubLv(int lv) {
    subLv = lv;
}

int SymbolTable::getNumEntries() {
    return (int) (map.size() + mapSub.size());
}

int SymbolTable::getSubLength() {
    std::map<std::string, TableEntry>::iterator it = mapSub.begin();
    int length = 0;
    while (it != mapSub.end()) {
        length += (*it).second.getLength();
        it++;
    }
    return length;
}

int SymbolTable::getCurrLoc() {
    return getTotalLength();
    /*if (subLv == 0) { // wrong
        return (int) map.size();
    }
    else {
        return subLength;
    }*/
}

//may lead to bad results but only for printing purposes
std::pair<std::string, TableEntry> SymbolTable::getEntryAtIndex(int i) {
    std::map<std::string, TableEntry>::iterator it;
    if (i < map.size()) {
        it = map.begin();
    }
    else {
        i -= map.size();
        it = mapSub.begin();
    }
    for (int j = 0; j < i; j++)
        it++;
    return *(it);
    
}

int SymbolTable::getTotalLength() {
    int length = 0;

    std::map<std::string, TableEntry>::iterator it = map.begin();
    while (it != map.end()) {
        length += (*it).second.getLength();
        it++;
    }
    it = mapSub.begin();
    while (it != mapSub.end()) {
        length += (*it).second.getLength();
        it++;
    }
    return length;
}