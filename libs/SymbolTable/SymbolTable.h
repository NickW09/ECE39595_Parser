#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "../TableEntry/TableEntry.h"
#include <string>
#include <map>



class SymbolTable {

public:
    ~SymbolTable();                             //DONE
    static SymbolTable* getInstance();          //DONE
    TableEntry getData(std::string key);        //DONE
    TableEntry getDataFromSub(std::string key); //DONE
    int checkFor(std::string key);
    void push(std::string str, TableEntry te);  //DONE
    void enterSubroutine();                     //DONE
    void exitSubroutine();                      //DONE
    int getSubLv();                             //DONE
    void setSubLv(int lv);                      //DONE
    int getNumEntries();                        //DONE
    int getSubLength();                         //DONE
    int getCurrLoc();                           //DONE
    std::pair<std::string, TableEntry> getEntryAtIndex(int i); //DONE
    int getTotalLength();                       //DONE
private:
    SymbolTable();                              //DONE
    static SymbolTable* symTab; 
    std::map<std::string, TableEntry> map;
    std::map<std::string, TableEntry> mapSub;
    //int idx;
    int subLv;
};

#endif /* SYMBOLTABLE_H_ */



