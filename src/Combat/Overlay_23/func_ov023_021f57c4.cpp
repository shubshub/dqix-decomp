#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_ov023_021f57c4_2 {
    unsigned int low : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int hi : 5;
    unsigned int rest : 11;
};

struct Struct_ov023_021f57c4 {
    char pad[0x100];
    struct Struct_ov023_021f57c4_2 bits;
};

struct Struct_ov023_021fff08_5 {
    char pad2[0xc];
    struct Struct_ov023_021f57c4* ptr;
};

extern struct Struct_ov023_021fff08_5 data_ov023_021fff08;

// USA: func_ov023_021f57c4
extern "C" ARM int func_ov023_021f57c4(void* objRaw) {
    struct Variant02030b0c* obj = (struct Variant02030b0c*)objRaw;
    data_ov023_021fff08.ptr->bits.low = ((Script::Parameter*)obj)->ToInt();
    data_ov023_021fff08.ptr->bits.unknown_1_4_ = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    data_ov023_021fff08.ptr->bits.hi = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    return 1;
}
