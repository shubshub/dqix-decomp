#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct List0201f1f0;
struct Variant02030b0c;

void BmdjScriptState_AllocateElements(List0201f1f0*, int, SafeAllocator*);

// data_020fdc40, the BMDJ script's context while BmdjScriptState_RunScript runs it
struct Container0201edc0 {
    int currentResource;
    SafeAllocator* allocator;
    List0201f1f0* state;
};
extern Container0201edc0 data_020fdc40;

// Main, originally InitList0201edc0 (USA 0x0201edc0, EUR 0x0201edd0, JPN 0x0201eb4c)
ARM int BmdjScript_AllocateElements(Variant02030b0c* params) {
    BmdjScriptState_AllocateElements(data_020fdc40.state, ((Script::Parameter*)params)->ToInt(), data_020fdc40.allocator);
    return 1;
}
