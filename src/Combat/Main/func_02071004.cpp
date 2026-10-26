#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_02108d70 {
    unsigned char unknown_0_;
    unsigned char pad1[0xf];
    int matchCount;
    unsigned char pad2[8];
    int unknown_1c_;
};

extern struct Struct_02108d70 data_02108d70;

// USA: func_02071004
extern "C" ARM int func_02071004(struct Variant02030b0c* p) {
    int value = ((Script::Parameter*)p)->ToInt();
    if (data_02108d70.unknown_1c_ == value || data_02108d70.unknown_0_ != 0) {
        data_02108d70.matchCount++;
    }
    return 1;
}
