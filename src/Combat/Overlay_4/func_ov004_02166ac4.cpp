#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov004_02166ac4_2402 = 0x790 };
#else
enum { Enum_ov004_02166ac4_2402 = 0x962 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"


#if defined(jpn)
extern char* data_ov004_0217101c[2];
#define CurrentBase0217101c data_ov004_0217101c[1]
#else
extern char* data_ov004_0217101c;
#define CurrentBase0217101c data_ov004_0217101c
#endif
extern "C" void* Scenario_GetInstance(void);
extern "C" int* func_02094d6c(void);
extern "C" int MessageSystem_GetInstance(void);

struct Struct_ov004_02166ac4 {
    unsigned char unknown_0_[0x1c];
    SafeAllocator allocators[2];
    int taskId;
    unsigned char unknown48[8];
    unsigned char flags;
    unsigned char unknown_51_[0x66];
    int unknown_b8_;
};

// USA: func_ov004_02166ac4
extern "C" ARM int func_ov004_02166ac4() {
    Struct_ov004_02166ac4* state = (Struct_ov004_02166ac4*)CurrentBase0217101c;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int taskId = state->taskId;
    loader->RemoveTask(taskId);
    state->taskId = -1;
    state->allocators[1].Destroy();
    state->allocators[0].Destroy();
    char* c = (char*)Scenario_GetInstance();
    memcpy(c + 0x2cc, ((Struct_ov004_02166ac4*)CurrentBase0217101c)->unknown_51_, 0x66);
    int* g = func_02094d6c();
    *(int*)((char*)g + 0xa0) = ((Struct_ov004_02166ac4*)CurrentBase0217101c)->unknown_b8_;
    char* f = (char*)MessageSystem_GetInstance();
    *(unsigned char*)(f + 0x1000 + Enum_ov004_02166ac4_2402) = 0;
    return 0;
}
