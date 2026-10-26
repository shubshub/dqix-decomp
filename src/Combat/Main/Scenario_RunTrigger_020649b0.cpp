#include <globaldefs.h>

struct Node02064530;
struct Obj020649b0 { char pad0[0xc]; void* nodeHead; };

extern "C" struct Obj020649b0* Scenario_FindTrigger(void*, int, void*);
extern "C" int Scenario_RunCommands(void* a, struct Node02064530* node, void* c);

// Main, originally LookupAndForEachNode020649b0 (USA 0x020649b0, EUR 0x020649c0, JPN 0x02065c9c)
extern "C" ARM int Scenario_RunTrigger(void* a, int mode, void* c) {
    struct Obj020649b0* r = Scenario_FindTrigger(a, mode, c);
    if (r == NULL) return 0;
    *(int*)((char*)c + 0x30) = 0;
    return Scenario_RunCommands(a, (struct Node02064530*)r->nodeHead, c) != 0;
}
