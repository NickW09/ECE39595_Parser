#include "SymbolTable.h"

SymbolTable* SymbolTable::symTab = nullptr;

//Constructor
SymbolTable::SymbolTable(){
    std::map<std::string, TableEntry> map;
    idx = 0;
    //NEED A WAY TO MARK SUBROUTINES? - David 
    //(look at parser example)
}

//possibly creates then returns singleton
SymbolTable* SymbolTable::getInstance(){
    if(symTab == nullptr) {
        symTab = new SymbolTable();
    }
    return symTab;
}

void SymbolTable::push(std::string str, TableEntry te) {
    map.insert(std::pair<std::string, TableEntry>(str, te));
}

//returns table entry at last key match
TableEntry SymbolTable::getEntry(std::string key) {
    TableEntry ret;
    for(auto const& e : map) {
        if(e.first == key) {
            ret = e.second;
        }
    }

    return ret; 
}
