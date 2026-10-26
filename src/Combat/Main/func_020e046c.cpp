#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "std_library_functions.h"

extern "C" int func_020dfbdc(void* a, struct Node020dfbdc* node);

extern "C" void* KeyTable_LoadInPlaceWithCallback(void* a, void* b, void* out, void* fn);

struct Container020e0310 {
    unsigned int w[3];
};
extern "C" int KeyTable_Lookup(struct Container020e0310* c, int key);

// USA: func_020e046c
extern "C" ARM char* func_020e046c(char* buf, void* b, void* c, int idx) {
    struct Container020e0310 local;
    int out;
    char* str;
    if (buf == NULL || b == NULL || c == NULL || idx < 0) return NULL;
    memset(&local, 0, sizeof(local));
    KeyTable_LoadInPlaceWithCallback(&local, b, &out, (void*)func_020dfbdc);
    str = (char*)KeyTable_Lookup(&local, idx);
    if (str == NULL) {
        buf[0] = 0;
        return NULL;
    }
    strcpy(buf, str);
    return buf;
}
