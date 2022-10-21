#include "SymbolTable.h"

SymbolTable* SymbolTable::symTab = nullptr;

//Constructor
SymbolTable::SymbolTable(){
    std::map<std::pair<int, std::string>, TableEntry> map;
    idx = 0;
    
    subLv = 0; //depth into subroutines, 0 for main and 1 for subroutine

    //need a way to mark subroutines - David 
    //(look at parser example)
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
    map.insert(std::pair<std::pair<int, std::string>, TableEntry>(std::pair<int, std::string>(subLv, str), te));
}

//returns table entry at last key match
TableEntry SymbolTable::getEntry(std::string key) {
    std::map<std::pair<int, std::string>, TableEntry>::iterator it;
    for (int i = subLv; i >= 0; i--) {
        it = map.find(std::pair<int, std::string>(i, key));
        if (it != map.end()) {
            return it->second;
        }
    }
    return TableEntry(-99, -99);
}

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
}


//return the current subroutine level
int SymbolTable::getSubLv() { 
    return subLv;
}

//set the current subroutine level
void SymbolTable::setSubLv(int lv) {
    subLv = lv;
}