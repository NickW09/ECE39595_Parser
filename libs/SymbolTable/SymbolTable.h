#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "../TableEntry/TableEntry.h"
#include <string>
#include <map>



class SymbolTable {

public:

    ~SymbolTable(); 
    static SymbolTable* getInstance();          //DONE
    int getData(std::string key);               //DONE
    TableEntry getEntry(std::string key);       //DONE
    void push(std::string str, TableEntry te);  //DONE
    void exitSubroutine();                      //DONE
    int getSubLv();                             //DONE
    void setSubLv(int lv);                      //DONE
private:
    SymbolTable();                              //DONE
    static SymbolTable* symTab; 
    std::map<std::pair<int, std::string>, TableEntry> map;
    int idx;
    int subLv;
};

#endif /* SYMBOLTABLE_H_ */



