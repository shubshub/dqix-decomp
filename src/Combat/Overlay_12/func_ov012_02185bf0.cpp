#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185bf0 func_ov012_02186248
enum { kElemOffset = 0x90, kDestOffset = 0x344, Enum_ov012_02185bf0_2400 = 0x800 };
#else
enum { kElemOffset = 0xac, kDestOffset = 0x374, Enum_ov012_02185bf0_2400 = 0x960 };
#endif
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
struct Struct_ov012_02185bf0;
typedef void (Struct_ov012_02185bf0::*Type_ov012_02185bf0)(void* dest, int alt);
extern Type_ov012_02185bf0 __ptmf_null;

struct Struct_ov012_0218b088 { Type_ov012_02185bf0 e[16]; };
extern struct Struct_ov012_0218b088 data_ov012_0218b088;

// USA: func_ov012_02185bf0
extern "C" ARM void func_ov012_02185bf0(char* obj, int id, int flag) {
    struct Elem_0205d81c* e = func_0205d81c((struct Struct_0205d81c*)(obj + kElemOffset), id);
    if (e == 0) return;

    unsigned char* var1 = (unsigned char*)e + 0xc5;
    if (flag) *var1 |= 0x40;
    else *var1 &= ~0x40;
    flag = 0;

    if (*var1 & 2) flag = 1;
    void* dest = *(void**)(obj + 0x1000 + kDestOffset);
    memset(dest, 0, Enum_ov012_02185bf0_2400);

    struct Struct_ov012_0218b088 table = data_ov012_0218b088;
    Type_ov012_02185bf0 none = __ptmf_null;
    table.e[0] = none;
    table.e[15] = none;

    if (table.e[id] != 0)
        (((Struct_ov012_02185bf0*)obj)->*table.e[id])(*(void**)(obj + 0x1000 + kDestOffset), flag);

#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)(obj + kElemOffset), id, *(int*)(obj + 0x1000 + kDestOffset), 0);
#else
    Window_SetPaneText((struct StructA0205d5d0*)(obj + kElemOffset), id, *(int*)(obj + 0x1000 + kDestOffset), 0, 0);
#endif
}
