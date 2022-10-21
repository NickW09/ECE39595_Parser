#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "../TableEntry/TableEntry.h"
#include <string>
#include <map>



class SymbolTable {

public:

    ~SymbolTable(); 
    static SymbolTable* getInstance(); //DONE
    int getData(std::string key);
    TableEntry getEntry(std::string key);
    void push(std::string str, TableEntry te);
    int getSubLv();
    void setSubLv(int lv);
private:
    SymbolTable();
    static SymbolTable* symTab; 
    std::map<std::pair<int, std::string>, TableEntry> map;
    int idx;
    int subLv;
};

#endif /* SYMBOLTABLE_H_ */



