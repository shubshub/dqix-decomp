#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov005_02159c24_3684 = 0xe60, kEntryCount = 3 };
#else
enum { Enum_ov005_02159c24_3684 = 0xe64, kEntryCount = 4 };
#endif

struct Struct_020e2490;
extern "C" void func_020e2490(Struct_020e2490*, int, int, void*, SafeAllocator*, int, unsigned char);

struct Struct_ov005_02159c24 {
    char unknown0[0x280];
    SafeAllocator unknown_280_;
    char unknown_294_[Enum_ov005_02159c24_3684 - 0x294];
    Struct_020e2490* unknown_e64_;
    void* unknown_e68_;
};

// USA: func_ov005_02159c24
extern "C" ARM void func_ov005_02159c24(Struct_ov005_02159c24* menu, void* arg1, void* arg2) {
    menu->unknown_280_.Reset();
    menu->unknown_e64_ = (Struct_020e2490*)menu->unknown_280_.Allocate(0x24);
    func_020e2490(menu->unknown_e64_, 0, 1, (void*)arg1, &menu->unknown_280_, kEntryCount, 0x40);
    menu->unknown_e68_ = (void*)arg2;
}
