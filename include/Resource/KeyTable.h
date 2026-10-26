#pragma once

// A key table (a .nat file such as str_cm_<LG>.nat or res.nat) and the state of loading it from a file.

// func_020dfd40's steps (Struct020dfc40::loadStep): queue the file with the BackgroundLoader, wait for the task, then
// load the table from the loaded file. KeyTable_EndLoad sets it back to 0.
enum KeyTableLoadStep
{
    KeyTableLoadStep_None = 0,
    KeyTableLoadStep_Queue = 1,
    KeyTableLoadStep_Wait = 2,
    KeyTableLoadStep_Load = 3,
};

// The table (KeyTable_Load: the count/textSize/relocated header, the {key, text} entries, the texts), then its load
// state. The tag stays because KeyTable_Reset's, KeyTable_EndLoad's and KeyTable_Destroy's C++ symbols are
// mangled with it.
struct Struct020dfc40 {
    unsigned int count : 12;
    unsigned int textSize : 19;
    unsigned int relocated : 1;
    void* entries;
    void* texts;
    short singleKey;  // >= 0: only this key's entry is loaded (func_020e0028), else the whole table (KeyTable_Load)
    short loadStep;   // KeyTableLoadStep
    int loadTask;     // the BackgroundLoader task, -1 when none
    void* allocator;  // what func_020dfd40 loads the table into (KeyTable_Load's allocator)
};

// One key table entry: {key, text offset}, the offset relocated to a pointer (func_020dfbdc). The tag stays
// because func_020dfbdc's C++ symbol is mangled with it.
struct Node020dfbdc {
    int key;
    int text;
};
