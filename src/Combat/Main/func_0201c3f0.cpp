#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201c414;

extern "C" void func_0201c414(struct Struct_0201c414*, int);

struct Struct_020fdc14_4 {
    int pad0;
    int pad4;
    struct Struct_0201c414* array;
};
extern struct Struct_020fdc14_4 data_020fdc14;

// USA: func_0201c3f0
extern "C" ARM int func_0201c3f0(struct Variant02030b0c* v) {
    int n = ((Script::Parameter*)v)->ToInt();
    func_0201c414(data_020fdc14.array, n);
    return 1;
}
