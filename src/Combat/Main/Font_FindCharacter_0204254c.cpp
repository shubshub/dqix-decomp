#include <globaldefs.h>

extern int data_0210782c[];
extern "C" int func_02001aec(int val, int key, int field5);

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

// USA: func_0204254c
ARM struct Entry0204254c* FindEntryByKey0204254c(int key, int tableIdx) {
    char* header;
    unsigned int i;
    if (key == 0) {
        return NULL;
    }
    header = (char*)data_0210782c[tableIdx];
    for (i = 0; i < *(unsigned int*)(header + 4); i++) {
        struct Entry0204254c* e = *(struct Entry0204254c**)(header + 0x10) + i;
        if (func_02001aec(e->val, key, e->field5) == 0) {
            return e;
        }
    }
    return NULL;
}
