#ifndef TABLEENTRY_H_
#define TABLEENTRY_H_

#include <string>

class TableEntry {

public:
    TableEntry();                   //DONE
    TableEntry(int loc, int len);   //DONE
    int getLocation();              //DONE
    int getLength();                //DONE
    std::pair<int, int> getData();  //DONE
    void setLocation(int loc);      //DONE
    void setLength(int len);        //DONE
private:
    std::pair<int, int> data;
    
};

#endif /* TABLEENTRY_H_ */



