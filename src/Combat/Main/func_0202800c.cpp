#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c;
struct Struct_0201a300_9;
extern "C" void func_02028378(struct Struct_0201a300_9* list, struct Struct_0201a300_2* src);

struct Struct_020fdd30_4 {
    struct Struct_0201a300_9* list;
};
extern struct Struct_020fdd30_4 data_020fdd30;

// USA: func_0202800c
extern "C" ARM int func_0202800c(Script::Parameter* v) {
    const Script::Parameter* parameters = v;
    struct Struct_0201a300_2 pair;
    int a = parameters[0].ToInt();
    int b = parameters[1].ToInt();
    pair.first = a;
    pair.second = b;
    func_02028378(data_020fdd30.list, &pair);
    return 1;
}
