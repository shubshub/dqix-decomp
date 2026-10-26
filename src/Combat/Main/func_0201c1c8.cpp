#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201c444;

extern "C" void func_0201c444(struct Struct_0201c444*, int);

struct Struct_020fdc14 {
    int count;
    int pad4;
    struct Struct_0201c444* array;
};
extern struct Struct_020fdc14 data_020fdc14;

// USA: func_0201c1c8
extern "C" ARM int func_0201c1c8(struct Variant02030b0c* v) {
    int n = ((Script::Parameter*)v)->ToInt();
    func_0201c444(data_020fdc14.array, n);
    data_020fdc14.count = 0;
    return 1;
}
