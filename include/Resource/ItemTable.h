#pragma once

// One 32-byte item record. The tag stays because BinarySearchByComparator020de650's C++ symbol is mangled with it.
struct Element020de650;

// An item table: `count` item records at `entries`. ItemTable_Find looks an item id up in it, by binary search when
// useBinarySearch is set (ItemTable_LoadIds sets it when the table holds more than one record); ItemTable_CopyIds
// fills one with the records of a list of ids from another.
struct ItemTable {
    unsigned short count;
    unsigned short copiedNames : 15;  // ItemTable_CopyIds's names for +2 to +7
    unsigned short owned : 1;
    unsigned short capacity;
    unsigned short nameCapacity;
    int unknown8;
    struct Element020de650* entries;
    unsigned char unknown10[4];
    unsigned char useBinarySearch;
};
