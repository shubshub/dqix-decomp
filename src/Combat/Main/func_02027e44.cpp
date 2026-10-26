#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c;

struct Struct_0201a300_11;
extern "C" Struct_0201a300_3* func_020283c0(struct Struct_0201a300_11* list, int id);

struct Struct_0201a300_12;
extern "C" void func_020281d8(struct Struct_0201a300_12* list, struct Struct_0201a300* src);

extern void* data_020fdd30;

// USA: func_02027e44
extern "C" ARM int func_02027e44(void* param0, int count) {
    struct Struct_0201a300 pair;
    pair.second = 0;
    pair.first = 0;
    void* var1 = param0;
    param0 = (char*)param0 + 8;
    int start = ((Script::Parameter*)((struct Variant02030b0c*)var1))->ToInt();
    count = count - 1;
    pair.first = func_020283c0((struct Struct_0201a300_11*)data_020fdd30, start);
    for (; count >= 0;) {
        int id = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
        param0 = (char*)param0 + 8;
        count = count - 1;
        Struct_0201a300_3* cur = func_020283c0((struct Struct_0201a300_11*)data_020fdd30, id);
        pair.second = cur;
        if (pair.first != 0 && cur != 0) {
            func_020281d8((struct Struct_0201a300_12*)data_020fdd30, &pair);
        }
        if (pair.second != 0) pair.first = pair.second;
    }
    return 1;
}
