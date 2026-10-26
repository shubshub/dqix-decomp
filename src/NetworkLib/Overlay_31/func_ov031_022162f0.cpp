#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" ARM void* func_ov031_02211b54(void* a, void* b);
extern "C" ARM int func_ov031_02215fcc(void);

struct Struct_ov031_022162f0 { char pad[0x790]; void* fieldB; };
struct Struct_ov031_0224e5dc { void* field0; void* field4; int field8; };
extern Struct_ov031_0224e5dc data_ov031_0224e5dc;

// USA: func_ov031_022162f0
extern "C" ARM int func_ov031_022162f0(void* a, void* b) {
    data_ov031_0224e5dc.field4 = func_ov031_02211b54((void*)1, (void*)func_ov031_02215fcc());
    data_ov031_0224e5dc.field0 = func_ov031_02211b54((void*)1, (void*)0x794);
    VectorizedMemset(data_ov031_0224e5dc.field0, 0, 0x794);
    *(void**)data_ov031_0224e5dc.field0 = a;
    ((Struct_ov031_022162f0*)data_ov031_0224e5dc.field0)->fieldB = b;
    data_ov031_0224e5dc.field8 = 0;
    return 1;
}
