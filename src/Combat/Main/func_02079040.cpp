#include <globaldefs.h>
#include "World/Object3D.h"
#if defined(jpn)
enum { kListOffset = 0x14 };
#else
enum { kListOffset = 0x18 };
#endif

struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);

struct U16Field0x6_020375f8;

extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

extern "C" int func_02028638(void* a, void* b);

struct List_020283fc;
extern "C" int NodeGraph_FindNodeIndexById(struct List_020283fc* list, int id);

struct Struct_02076df4 {
    char pad0[0x44];
    char unknown_44_[0xb8 - 0x44];
    unsigned short field0xb8;
};

// USA: func_02079040
extern "C" ARM unsigned short func_02079040(struct Struct_02076df4* obj, unsigned char* outFlag) {
    struct Entry_02028bd0* base;
    struct Entry_02028bd0* entry;
    unsigned short key;
    int id;
    int idx;
    *outFlag = 0;
    base = ZoneRecords_GetInstance();
    key = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
    entry = ZoneRecords_Find(base, key);
    if (entry == NULL) {
        return 0;
    }
    id = func_02028638((char*)entry + kListOffset, (char*)obj + 0x44);
    idx = NodeGraph_FindNodeIndexById((struct List_020283fc*)((char*)entry + kListOffset), id);
    if (idx != -1) {
        obj->field0xb8 = idx;
    }
    return (unsigned short)id;
}
