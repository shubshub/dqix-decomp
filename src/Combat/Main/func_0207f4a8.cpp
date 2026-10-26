#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

extern "C" void* func_0207f700(unsigned char* obj, short index);

struct Struct_02108ee0 { void* field0; void* field4; };
extern struct Struct_02108ee0 data_02108ee0;

struct Struct_0207f12c {
    void* entries;
    short count;
};

struct Struct_0207f4a8 {
    char pad[0x18];
    short f18;
    char unknown_1a_[2];
    short f1c;
    char unknown_1e_[2];
    short f20;
    char unknown_22_[2];
    short f24;
};

// USA: func_0207f4a8
extern "C" ARM int func_0207f4a8(struct Variant02030b0c* p) {
    struct Struct_0207f12c* list = (struct Struct_0207f12c*)data_02108ee0.field4;
    struct Struct_0207f4a8* e = (struct Struct_0207f4a8*)func_0207f700((unsigned char*)list, (short)(list->count - 1));
    if (e != NULL) {
        e->f18 = ((Script::Parameter*)p)->ToInt();
        e->f1c = ((Script::Parameter*)((struct Variant02030b0c*)((char*)p + 8)))->ToInt();
        e->f20 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)p + 0x10)))->ToInt();
        e->f24 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)p + 0x18)))->ToInt();
    }
    return 1;
}
