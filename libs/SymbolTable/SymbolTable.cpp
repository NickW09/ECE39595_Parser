#include "SymbolTable.h"

SymbolTable* SymbolTable::symTab = nullptr;

//Constructor
SymbolTable::SymbolTable(){
    std::map<std::pair<int, std::string>, TableEntry> map;
    //idx = 0;
    
    subLv = 0; //depth into subroutines, 0 for main and 1 for subroutine
    subLength = 0; //not supported for nested subroutines


    //parserActions.pdf pg 2 : "we do not have nested subroutines or functions"
}

//possibly creates then returns singleton
SymbolTable* SymbolTable::getInstance(){
    if(symTab == nullptr) {
        symTab = new SymbolTable();
    }
    return symTab;
}

void SymbolTable::push(std::string str, TableEntry te) {
    if (subLv == 1) {
        subLength += te.getLength();
    }
    
    map.insert(std::pair<std::pair<int, std::string>, TableEntry>(std::pair<int, std::string>(subLv, str), te));
}

//returns table entry at last key match
TableEntry SymbolTable::getData(std::string key) {
    std::map<std::pair<int, std::string>, TableEntry>::iterator it;
    for (int i = subLv; i >= 0; i--) {
        it = map.find(std::pair<int, std::string>(i, key));
        if (it != map.end()) {
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
    std::map<std::pair<int, std::string>, TableEntry>::iterator it = map.begin();
    while (it != map.end()) {
        if ((*it).first.first == subLv) {
            break;
        }
        it++;
    }
    map.erase(it, map.end());
 
    subLv--;
    subLength = 0; //BE CAREFUL THAT YOU DONT ERASE IT BEFORE YOU NEED IT
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
    return (int) map.size();
}

int SymbolTable::getSubLength() {
    return subLength;
}

int SymbolTable::getCurrLoc() {
    return (int) map.size();
}

std::pair<std::pair<int, std::string>, TableEntry> SymbolTable::getEntryAtIndex(int i) {
    std::map<std::pair<int, std::string>, TableEntry>::iterator it = map.begin();
    for (int j = 0; j < i; j++)
        it++;
    return *(it);
}

int SymbolTable::getTotalLength() {
    int length = 0;

    std::map<std::pair<int, std::string>, TableEntry>::iterator it = map.begin();
    while (it != map.end()) {
        length += (*it).second.getLength();
        it++;
    }

    return length;
}