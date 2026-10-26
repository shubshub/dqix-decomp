#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_020a8218;
extern "C" void func_020a8218(Struct_020a8218*, int, int);

struct Struct_02109fe0 {
    void* allocator;
    Struct_020a8218* out;
};
extern Struct_02109fe0 data_02109fe0;

// USA: func_020a7f5c
extern "C" ARM int func_020a7f5c(Variant02030b0c* variant) {
    func_020a8218(data_02109fe0.out, (int)data_02109fe0.allocator, (unsigned short)((Script::Parameter*)variant)->ToInt());
    return 1;
}
