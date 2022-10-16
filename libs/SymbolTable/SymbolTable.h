#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <string>
#include <map>



class SymbolTable {

public:

    ~SymbolTable(); 
    static SymbolTable* getInstance(); //DONE
    int getData(std::string key);
private:
    SymbolTable();
    static SymbolTable* symTab; 
    std::map<std::string, int> map;
    int idx = 0;
};

#endif /* SYMBOLTABLE_H_ */



