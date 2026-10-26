#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c { int tag; int u; };

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Struct_02027d94;
extern "C" void func_02027d94(struct Struct_02027d94* obj);

struct Struct_0201a300_10;
extern "C" void func_02028170(struct Struct_0201a300_10* c, struct Struct_0201a300_3* src);

struct Struct_02027ce4 {
    struct Variant02030b0c a;
    struct Variant02030b0c b;
    struct Struct_0201d530 x;
    struct Struct_0201d530 y;
    struct Struct_0201d530 z;
};

extern struct Struct_0201a300_10* data_020fdd30;

// USA: func_02027ce4
extern "C" ARM int func_02027ce4(struct Struct_02027ce4* arg) {
    struct Struct_0201a300_3 local;
    func_02027d94((struct Struct_02027d94*)&local);
    local.id = (unsigned char)((Script::Parameter*)&arg->a)->ToInt();
    local.unknown_1_ = (unsigned char)((Script::Parameter*)&arg->b)->ToInt();
    local.x = (short)((int)(4096.0f * ((Script::Parameter*)&arg->x)->ToFloat()) >> 12);
    local.unknown_6_ = (short)((int)(4096.0f * ((Script::Parameter*)&arg->y)->ToFloat()) >> 12);
    local.z = (short)((int)(4096.0f * ((Script::Parameter*)&arg->z)->ToFloat()) >> 12);
    func_02028170(data_020fdd30, &local);
    return 1;
}
