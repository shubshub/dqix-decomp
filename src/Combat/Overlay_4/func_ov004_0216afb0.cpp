#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
struct Struct_ov004_0216afb0;
extern "C" void func_ov023_021f89f4(struct Struct_ov004_0216afb0* obj, void* a1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int flag);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov023_021fe708;

struct Struct_ov004_0216afb0_2 { void* magic; char pad[0x50 - 4]; };

// USA: func_ov004_0216afb0
extern "C" ARM void func_ov004_0216afb0(void* a1, int p2, int p3, int p4,
    int p5, int p6, int p7, int p8, unsigned char p9) {
    void* buf = func_ov011_021845f8(a1, p3);
    void* block = ((SafeAllocator*)((char*)buf + 4))->Allocate(0x50);
    if (!block) return;

    struct Struct_ov004_0216afb0_2 local;
    local.magic = &data_ov023_021fe708;
    memcpy(block, &local, sizeof(Struct_ov004_0216afb0_2));

    int flag = 0xf;
    if (p9 == 0) flag = 3;
    func_ov023_021f89f4((struct Struct_ov004_0216afb0*)block, a1, p2, p3, p4, 0x192, p5, p6, p7, p8, flag);

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(a1), (struct Struct_ov004_0215c30c_2*)block);
}
