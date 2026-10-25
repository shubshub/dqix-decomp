#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct_0201c3a4 {
    int unknown_0_;
    void* unknown_4_;
};
int STD_GetStringLength(const char* s);

struct Struct_02089ac0 {
    char unknown_0_[0x14];
    char** unknown_14_;
    short unknown_18_;
};

struct Struct_02108efc_2 {
    struct Struct_02089ac0* unknown_0_;
    int unknown_4_;
    int unknown_8_;
    SafeAllocator* unknown_c_;
};
extern struct Struct_02108efc_2 data_02108efc;

// USA: func_02089ac0
extern "C" ARM int func_02089ac0(struct Struct02030b7c* items) {
    char** strings;
    short count = data_02108efc.pool->count;
    strings = (char**)data_02108efc.alloc->Allocate(count * 4);
    for (short i = 0; i < count; i++) {
        char* text = (char*)(void*)((Script::Parameter*)items)->ToString();
        items = (struct Struct02030b7c*)((char*)items + 8);
        int len = STD_GetStringLength(text);
        strings[i] = (char*)data_02108efc.alloc->Allocate(len + 1);
        memset(strings[i], 0, len + 1);
        memcpy(strings[i], text, len);
    }
    data_02108efc.unknown_0_->unknown_14_ = var0;
    return 1;
}
