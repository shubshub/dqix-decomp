#include <globaldefs.h>
#if defined(jpn)
#define REGIONAL_PARAMETER
#else
#define REGIONAL_PARAMETER int p5,
#endif
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

struct Struct_ov023_021f6ed8;
extern "C" ARM void func_ov023_021f6ed8(struct Struct_ov023_021f6ed8* arg0);

void Background_Init(struct List0204af64* obj);
void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_SetPriority(void*, int);

struct Obj0204b5e8;
int Background_SetScroll(struct Obj0204b5e8*, int, int);

extern "C" void* func_ov011_021845f8(void* arg0, int arg1);

struct AllocTarget0204b12c;
void Background_AllocateMap(struct AllocTarget0204b12c* obj, SafeAllocator* alloc);

struct Struct_ov023_021f745c;
extern "C" ARM void func_ov023_021f7a08(struct Struct_ov023_021f745c* arg0, void* arg1);

// USA: func_ov023_021f745c
extern "C" ARM int func_ov023_021f745c(char* arg0, void* arg1, int arg2, int arg3, REGIONAL_PARAMETER int arg5, int arg6, int arg7, int arg8) {
#if defined(jpn)
 enum {Enum_ov023_021f745c_40=0x24, Enum_ov023_021f745c_72=0x44, Enum_ov023_021f745c_80=0x4c, Enum_ov023_021f745c_82=0x4e};
#else
 enum {Enum_ov023_021f745c_40=0x28, Enum_ov023_021f745c_72=0x48, Enum_ov023_021f745c_80=0x50, Enum_ov023_021f745c_82=0x52};
#endif
    func_ov023_021f6ed8((struct Struct_ov023_021f6ed8*)arg0);
    *(short*)(arg0 + 0x4) = 2;
    *(void**)(arg0 + 0x20) = arg1;
    *(short*)(arg0 + 0x6) = (short)arg2;
    *(short*)(arg0 + 0x8) = (short)arg3;
    *(short*)(arg0 + 0xa) = 0;
#if defined(jpn)

#else
    *(int*)(arg0 + 0x24) = p5;
#endif

    *(int*)(obj + 0x10) = p6;
    *(int*)(obj + regionalOffset1) = 0;
    Background_Init((struct List0204af64*)(obj + regionalOffset0));
    Background_SetMapSize((unsigned char*)(obj + regionalOffset0), 0);

    struct Struct_02020cb8* var0 = (struct Struct_02020cb8*)(arg0 + Enum_ov023_021f745c_40);
    var0->unknown_1c_0_ = (unsigned char)arg6;
    var0->unknown_1c_4_ = (unsigned char)arg7;

    Background_SetPriority(obj + regionalOffset0, p9);
    Background_SetScroll((struct Obj0204b5e8*)(obj + regionalOffset0), 0, 0);

    void* var1 = func_ov011_021845f8(arg1, *(unsigned short*)(arg0 + 0x8));
    if (var1 == 0) return 0;

    Background_AllocateMap((struct AllocTarget0204b12c*)(obj + regionalOffset0), (SafeAllocator*)((char*)result + 4));
    func_ov023_021f7a08((struct Obj021f7a08*)obj, arg1);
    *(short*)(obj + regionalOffset2) = 0;
    *(short*)(obj + regionalOffset3) = 0;
    return 1;
}
