#include <globaldefs.h>

struct DispatchObj020a0dec {
    int selector;
};

typedef void (DispatchObj020a0dec::*DispatchFn020a0dec)();

struct DispatchTable020a0dec {
    DispatchFn020a0dec fns[3];
};

extern const DispatchTable020a0dec data_020e8f08;

// Main, originally DispatchMemberFn020a0dec (USA 0x020a0dec, EUR 0x020a0dfc, JPN 0x020a2b64)
ARM void Vec3Ease_Step(DispatchObj020a0dec* obj) {
    DispatchTable020a0dec table = data_020e8f08;
    (obj->*table.fns[obj->selector])();
}
