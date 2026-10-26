#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
enum { Enum_0205e05c_48 = 0x50 };
#else
enum { Enum_0205e05c_48 = 0x30 };
#endif

struct Variant02030b0c;

extern void* data_02108740[];

// USA: func_0205e05c
extern "C" ARM int func_0205e05c(Script::Parameter* p, int) {
    const Script::Parameter* parameters = p;
    *(int*)((char*)data_02108740[1] + Enum_0205e05c_48) = parameters[0].ToInt();
    return 1;
}
