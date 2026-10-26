#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Holder0209a97c;
struct Pair0209a97c;
extern "C" void func_0209a97c(struct Holder0209a97c* h, int slot, struct Pair0209a97c* src);

extern struct Holder0209a97c* SpellTable_scriptContext;

struct Struct_0209a7bc_2 {
    unsigned short a;
    unsigned short b;
};

// USA: func_0209a7bc
extern "C" ARM int func_0209a7bc(void* arg) {
    int slot = ((Script::Parameter*)((struct Variant02030b0c*)arg))->ToInt();
    struct Struct_0209a7bc_2 pair;
    pair.a = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 8)))->ToInt();
    pair.b = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 0x10)))->ToInt();
    func_0209a97c(SpellTable_scriptContext, slot, (struct Pair0209a97c*)&pair);
    return 1;
}
