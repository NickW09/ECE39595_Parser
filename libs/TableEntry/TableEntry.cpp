#include "TableEntry.h"

//Constructor
TableEntry::TableEntry() {
    data = std::pair<int, int>();
    data.first = -99;
    data.second = -99;
}

TableEntry::TableEntry(int loc, int len){
    data = std::pair<int, int>();
    data.first = loc;
    data.second = len;
}

int TableEntry::getLocation() {
    return data.first;
}

int TableEntry::getLength() {
    return data.second;
}

std::pair<int, int> TableEntry::getData() {
    return data;
}

void TableEntry::setLocation(int loc) {
    data.first = loc;
}

void TableEntry::setLength(int len) {
    data.second = len;
}