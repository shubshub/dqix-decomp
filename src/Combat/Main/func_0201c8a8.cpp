#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "Resource/Script.h"

class SafeAllocator;
struct Variant02030b0c;
struct Struct_0201e288;

struct Struct_020fdc20_3 {
    int pad0;
    SafeAllocator* alloc;
    struct Struct_0201e288* array;
};
extern struct Struct_020fdc20_3 data_020fdc20;

// USA: func_0201c8a8
extern "C" ARM int func_0201c8a8(Script::Parameter* arg0, int) {
    struct Variant02030b0c* v = (struct Variant02030b0c*)arg0;
    int n = ((Script::Parameter*)v)->ToInt();
    ((ZoneFeatures*)data_020fdc20.array)->func_0201e288(n, data_020fdc20.alloc);
    return 1;
}
