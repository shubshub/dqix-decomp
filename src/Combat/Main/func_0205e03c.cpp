#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
enum { Enum_0205e03c_42 = 0x4a };
#else
enum { Enum_0205e03c_42 = 0x2a };
#endif

struct Variant02030b0c;

extern void* data_02108740[];

// USA: func_0205e03c
extern "C" ARM int func_0205e03c(Script::Parameter* p) {
    const Script::Parameter* parameters = p;
    *(short*)((char*)data_02108740[1] + Enum_0205e03c_42) = parameters[0].ToInt();
    return 1;
}
