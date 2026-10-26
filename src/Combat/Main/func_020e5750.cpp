#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct02030b7c;

struct Struct_020e5750 {
    int field0;
    int field4;
    int lo;
    int hi;
    int field10;
};
struct Struct_020e5750_2;

extern "C" int STD_GetStringLength(const char* s);
extern "C" void func_020e587c(struct Struct_020e5750_2* list, struct Struct_020e5750* entry);

extern void* data_021536c4[2];

// USA: func_020e5750
extern "C" ARM int func_020e5750(void* param0) {
    struct Struct_020e5750 entry;
    char* fmt;
    memset(&entry, 0, sizeof(entry));
    entry.lo = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    entry.hi = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x8)))->ToInt();
    entry.field4 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x10)))->ToInt();
    fmt = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)param0 + 0x18)))->ToString();
    if (fmt) {
        int len = STD_GetStringLength(fmt);
        char* buf = (char*)((SafeAllocator*)data_021536c4[0])->Allocate(len + 1);
        entry.field10 = (int)buf;
        sprintf(buf, fmt);
    }
    func_020e587c((struct Struct_020e5750_2*)data_021536c4[1], &entry);
    return 1;
}
