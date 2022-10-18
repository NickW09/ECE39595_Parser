#include "SymbolTable.h"

SymbolTable* SymbolTable::symTab = nullptr;

//Constructor
SymbolTable::SymbolTable(){
    map = std::map<std::string, int>();
    idx = 0;
}

//possibly creates then returns singleton
SymbolTable* SymbolTable::getInstance(){
    if(symTab == nullptr) {
        symTab = new SymbolTable();
    }
    return symTab;
}

int SymbolTable::getData(std::string key) {
    for(auto const& e : map) {
        if(e.first == key) {
            return e.second;
        }
    }

    return 0; //TEMP
}

/*
//pushes string onto string buffer
void SymbolTable::push(std::string str) {
    vec.push_back(str);
}

//returns string when given an index into symTab
std::string SymbolTable::get(int i) {
    // std::vector<std::string>::iterator p;
    // p = (*vec).begin();
    // return *p;
    return map[i];
}

*/