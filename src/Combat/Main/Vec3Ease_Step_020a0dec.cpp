#include <globaldefs.h>

struct DispatchObj020a0dec {
    int selector;
};

typedef void (DispatchObj020a0dec::*Type_0202ef14)();

struct Struct_020e8f08 {
    Type_0202ef14 unknown_0_[3];
};

extern const Struct_020e8f08 data_020e8f08;

// Main, originally DispatchMemberFn020a0dec (USA 0x020a0dec, EUR 0x020a0dfc, JPN 0x020a2b64)
extern "C" ARM void Vec3Ease_Step(DispatchObj020a0dec* obj) {
    Struct_020e8f08 table = data_020e8f08;
    (obj->*table.unknown_0_[obj->selector])();
}
