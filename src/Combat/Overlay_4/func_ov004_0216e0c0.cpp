#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov004_0216e0c0_84 = 0x50, Enum_ov004_0216e0c0_32625 = 0x7c9d };
#else
enum { Enum_ov004_0216e0c0_84 = 0x54, Enum_ov004_0216e0c0_32625 = 0x7f71 };
#endif

#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
#if defined(jpn)
extern "C" void func_ov023_021f745c(void* buf, void* obj, int msgId, int layer, void* file, int palette, int format, int mode);
#else
extern "C" void func_ov023_021f745c(void* buf, void* obj, int msgId, int p3, void* p4, void* fmt, int p6, int p7, int p8);
#endif

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov004_02170752;
extern char data_ov004_02170761;
extern char data_ov004_02170770;
extern char data_ov004_02170780;
extern char data_ov004_02170790;
extern char data_ov004_021707a0;
extern char data_ov023_021fe4f0;

struct Struct_ov004_0216e0c0 { void* magic; char pad[Enum_ov004_0216e0c0_84 - 4]; };

// USA: func_ov004_0216e0c0
extern "C" ARM int func_ov004_0216e0c0(void* obj) {
    void* fmt = 0;
#if !defined(jpn)
    void* p4 = 0;
#endif
    unsigned char state = *((unsigned char*)GameState::GetInstance() + Enum_ov004_0216e0c0_32625);
    switch (state) {
#if defined(jpn)
        case 0: fmt = &data_ov004_02170761; break;
#else
        case 0: p4 = &data_ov004_02170752; fmt = &data_ov004_02170761; break;
#endif
#if defined(jpn)
        case 1: fmt = &data_ov004_02170780; break;
#else
        case 1: p4 = &data_ov004_02170770; fmt = &data_ov004_02170780; break;
#endif
#if defined(jpn)
        case 2: fmt = &data_ov004_021707a0; break;
#else
        case 2: p4 = &data_ov004_02170790; fmt = &data_ov004_021707a0; break;
#endif
    }

    void* buf = func_ov011_021845f8(obj, 3);
    if (!buf) {
        return 0;
    }
    ((SafeAllocator*)((char*)buf + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)buf + 4))->Allocate(Enum_ov004_0216e0c0_84);
    if (!block) {
        return 0;
    }

    struct Struct_ov004_0216e0c0 local;
    local.magic = &data_ov023_021fe4f0;
    memcpy(block, &local, sizeof(Struct_ov004_0216e0c0));

#if defined(jpn)
    func_ov023_021f745c(block, obj, 0x69, 3, fmt, 1, 2, 0);
#else
    func_ov023_021f745c(block, obj, 0x69, 3, p4, fmt, 1, 2, 0);
#endif

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(obj), (struct Struct_ov004_0215c30c_2*)block);
    return 0;
}
