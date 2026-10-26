#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_ov028_021d97d8 { short a; short b; int c; int d; };
struct Struct_ov028_021d97d8_2;
extern "C" void func_ov028_021d999c(Struct_ov028_021d97d8_2* obj, Struct_ov028_021d97d8* item);

extern "C" void func_ov028_021d987c(void*);
struct Variant02030b0c;
struct Struct02030b7c;
extern "C" int STD_GetStringLength(const char* s);

struct Struct_ov028_021d9bc4_2 {
    void* field0;
    SafeAllocator* field4;
};
extern Struct_ov028_021d9bc4_2 data_ov028_021d9bc4;

// USA: func_ov028_021d97d8
extern "C" ARM int func_ov028_021d97d8(void* obj) {
    Struct_ov028_021d97d8 local;
    func_ov028_021d987c(&local);
    local.a = (short)((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
    local.c = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    local.b = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    const char* text = (const char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)obj + 0x18)))->ToString();
    if (text != 0) {
        int len = STD_GetStringLength(text);
        char* buf = (char*)data_ov028_021d9bc4.field4->Allocate(len + 1);
        if (buf != 0) {
            memset(buf, 0, len);
            sprintf(buf, text);
            local.d = (int)buf;
        }
    }
    func_ov028_021d999c((Struct_ov028_021d97d8_2*)data_ov028_021d9bc4.field0, &local);
    return 1;
}
