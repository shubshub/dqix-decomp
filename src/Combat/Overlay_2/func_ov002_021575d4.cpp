#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

extern "C" void* Scenario_GetInstance(void*);
extern "C" int func_02064a40(void* param0, void* param1);
extern "C" void EventQuery_RunQueuedCommands(void* p);

// USA: func_ov002_021575d4
extern "C" ARM int func_ov002_021575d4(char* p) {
    int result = 0;
    void* obj = Scenario_GetInstance(p);
    short val = *(short*)(p + RG(0x1c00, 0x1a00) + RG(0x22, 0xea));
    char buf[0x34];
    *(int*)(buf + 0x10) = val;
    if (func_02064a40(obj, buf) != 0) {
        result = 1;
        EventQuery_RunQueuedCommands(buf);
        *(short*)(p + RG(0x1c00, 0x1a00) + RG(0x28, 0xf0)) = 0x232a;
        *(short*)(p + RG(0x1c00, 0x1a00) + RG(0x2a, 0xf2)) = -1;
    }
    return result;
}
