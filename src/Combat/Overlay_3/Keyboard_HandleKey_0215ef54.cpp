#include <globaldefs.h>

typedef void* (*DispatchFunc_0215ef54)(void*);

struct DispatchTable_0215ef54 {
    DispatchFunc_0215ef54 f[9];
};

extern struct DispatchTable_0215ef54 data_ov003_0217f3c8;

// Overlay 3, originally func_ov003_0215ef54 (USA/EUR 0x0215ef54; JPN not identified)
extern "C" ARM void* Keyboard_HandleKey(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned char* field0 = *(unsigned char**)o;
    struct DispatchTable_0215ef54 table;
    if (field0 != 0) {
        table = data_ov003_0217f3c8;
        return table.f[field0[0xd]](obj);
    }
    return 0;
}
