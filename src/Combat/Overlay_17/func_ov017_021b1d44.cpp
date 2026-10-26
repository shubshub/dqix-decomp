#if defined(jpn)
enum { Enum_ov017_021b1d44_620 = 0xc };
#else
enum { Enum_ov017_021b1d44_620 = 0x26c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_ov017_021b1d44 { char pad[0xc]; unsigned short unknown_c_0_ : 13; unsigned short unknown_d_5_ : 3; };
struct Struct_ov017_021b1d44_2 { char pad[0x5d00]; struct Struct_ov017_021b1d44 area; };

struct Struct_ov017_021b1d44_3 { unsigned char pad0[0x3c]; int arr[8]; };

// USA: func_ov017_021b1d44
extern "C" ARM int func_ov017_021b1d44(unsigned char* self, int flags, int arg2) {
    func_0204693c((struct ByteHeader0204693c*)self);
    self[0] = 0x2c;
    *(int*)(self + 8) = 0;
    self[0x20] = 0;
    self[0x21] = (unsigned char)flags;
    *(int*)(self + 0x24) = 0;
    ((SafeAllocator*)(self + 0xc))->ResetAllocatorPointer();
    self[0x32] = 0;
    if (arg2 != 0) {
        self[0x28] = 0;
        self[0x29] = 0;
        VectorizedMemset(self + 0x2a, 0, 8);
    }
    *(int*)(self + 0x34) = 0;
    *(int*)(self + 0x38) = 0;
    if ((self[0x21] & 0x40) != 0) {
        struct Struct_ov017_021b1d44_3* obj = (struct Struct_ov017_021b1d44_3*)self;
        for (int i = 0; i < 8; i++) {
            obj->arr[i] = -1;
        }
        return 0;
    }
    struct Struct_ov017_021b1d44_2* outer =
        (struct Struct_ov017_021b1d44_2*)((char*)GameState::GetInstance() + Enum_ov017_021b1d44_620);
    if ((outer->area.unknown_c_0_ & 8) == 0) {
        unsigned char f = self[0x21];
        if ((f & 4) == 0 && (f & 2) == 0 && (f & 0x20) == 0) {
            self[0x21] = f | 0x10;
        }
    }
    return 1;
}
