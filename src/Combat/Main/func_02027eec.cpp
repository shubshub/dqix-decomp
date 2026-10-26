#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c;

struct Struct_0201a300_11;
extern "C" Struct_0201a300_3* func_020283c0(struct Struct_0201a300_11* list, int id);

struct Struct_0201a300_12;
extern "C" void func_020281d8(struct Struct_0201a300_12* list, Struct_0201a300* src);

extern void* data_020fdd30;

// USA: func_02027eec
extern "C" ARM int func_02027eec(void* param0) {
    Struct_0201a300 pair;
    int start, end, id;
    start = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    end = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    pair.first = 0;
    pair.second = 0;
    id = start + 1;
    pair.first = func_020283c0((struct Struct_0201a300_11*)data_020fdd30, start);
    for (; id <= end;) {
        Struct_0201a300_3* cur = func_020283c0((struct Struct_0201a300_11*)data_020fdd30, id);
        pair.second = cur;
        id++;
        if (pair.first != 0 && cur != 0) {
            func_020281d8((struct Struct_0201a300_12*)data_020fdd30, &pair);
        }
        if (pair.second != 0) pair.first = pair.second;
    }
    return 1;
}
