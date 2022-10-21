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
    TableEntry ret = TableEntry(-99, -99);
    for (int i = 0; i <= subLv; i++) {
        for (auto const& e : map) {
            if (e.first == std::pair<int, std::string>(i, key)) {
                ret = e.second;
            }
        }
    }
    
    return ret; 
}

int SymbolTable::getSubLv() { 
    return subLv;
}

void SymbolTable::setSubLv(int lv) {
    subLv = lv;
}