#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);

struct Struct_ov001_021658b8_8 { char pad0[0x8c]; unsigned char unknown_8c_; char pad1[0x9c - 0x8c - 1]; unsigned char unknown_9c_; };
extern Struct_ov001_021658b8_8 data_ov001_021658b8;

struct Struct_ov001_021658d8;
extern "C" void* func_ov001_02153884(struct Struct_ov001_021658d8* t, int key);
extern struct Struct_ov001_021658d8 data_ov001_021658d8;

struct Struct_ov001_02153884 { int key; int val; };

extern unsigned char data_ov001_02165944[0x11];

// USA: func_ov001_0215e444
extern "C" ARM int func_ov001_0215e444(void* self) {
    data_ov001_021658b8.unknown_8c_ = 0;
    int key = func_ov017_021d60f4(self);
    if (key < 0) return 1;
    struct Struct_ov001_02153884* entry = (struct Struct_ov001_02153884*)func_ov001_02153884(&data_ov001_021658d8, key);
    if (entry == NULL) return 0;
    if (entry->val == 0) return 0;
    memcpy(data_ov001_02165944, (void*)entry->val, 0x11);
    data_ov001_021658b8.unknown_9c_ = 0;
    return 1;
}
