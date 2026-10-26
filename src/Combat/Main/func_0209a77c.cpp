#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct PairEntry0209a93c;
struct PairHolder0209a93c;
extern "C" void func_0209a93c(struct PairHolder0209a93c* holder, struct PairEntry0209a93c* src);

extern struct PairHolder0209a93c* SpellTable_scriptContext;

struct Struct_0209a77c {
    unsigned short a;
    unsigned short b;
};

// USA: func_0209a77c
extern "C" ARM int func_0209a77c(void* arg) {
    struct Struct_0209a77c pair;
    pair.a = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)arg))->ToInt();
    pair.b = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 8)))->ToInt();
    func_0209a93c(SpellTable_scriptContext, (struct PairEntry0209a93c*)&pair);
    return 1;
}
