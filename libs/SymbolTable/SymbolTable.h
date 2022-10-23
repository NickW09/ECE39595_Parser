#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "../TableEntry/TableEntry.h"
#include <string>
#include <map>



class SymbolTable {

public:

    static SymbolTable* getInstance();          //DONE
    TableEntry getData(std::string key);        //DONE
    void push(std::string str, TableEntry te);  //DONE
    void exitSubroutine();                      //DONE
    int getSubLv();                             //DONE
    void setSubLv(int lv);                      //DONE
    int getNumEntries();                        //DONE
    int getSubLength();                         //DONE
    int getCurrLoc();                           //DONE
    std::pair<std::pair<int, std::string>, TableEntry> getEntryAtIndex(int i); //DONE
private:
    SymbolTable();                              //DONE
    static SymbolTable* symTab; 
    std::map<std::pair<int, std::string>, TableEntry> map;
    //int idx;
    int subLv;
    int subLength;
};

#endif /* SYMBOLTABLE_H_ */



