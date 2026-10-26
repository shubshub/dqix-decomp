#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c;

struct Struct_0201a300_11;
extern "C" Struct_0201a300_3* func_020283c0(struct Struct_0201a300_11* list, int id);

struct Struct_0201a300_12;
extern "C" void func_020281d8(struct Struct_0201a300_12* list, struct Struct_0201a300* src);

extern void* data_020fdd30;

// USA: func_02027db0
extern "C" ARM int func_02027db0(void* param0) {
    struct Struct_0201a300 entry;
    int a, b;
    entry.second = 0;
    entry.first = 0;
    a = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    b = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    if (a == b) return 0;
    entry.first = func_020283c0((struct Struct_0201a300_11*)data_020fdd30, a);
    entry.second = func_020283c0((struct Struct_0201a300_11*)data_020fdd30, b);
    if (entry.first == 0 || entry.second == 0) return 0;
    func_020281d8((struct Struct_0201a300_12*)data_020fdd30, &entry);
    return 1;
}
