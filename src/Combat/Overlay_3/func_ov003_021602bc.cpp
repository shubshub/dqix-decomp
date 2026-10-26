#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021602bc_48 = 0xc };
enum { Enum_ov003_021602bc_916 = 0x27c };
enum { Enum_ov003_021602bc_552 = 0x110 };
enum { Enum_ov003_021602bc_17244 = 0x413c };
#else
enum { Enum_ov003_021602bc_48 = 0x30 };
enum { Enum_ov003_021602bc_916 = 0x394 };
enum { Enum_ov003_021602bc_552 = 0x228 };
enum { Enum_ov003_021602bc_17244 = 0x435c };
#endif

#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_ov003_021602bc { char rows[4][Enum_ov003_021602bc_48]; };

// USA: func_ov003_021602bc
extern "C" ARM void func_ov003_021602bc(char* obj) {
    char* var0 = (char*)GetGameResources();

    for (int i = 0; i < 4; i++) {
        (*(void***)(obj + Enum_ov003_021602bc_916))[i] = 0;
        void* buf = ((SafeAllocator*)(obj + Enum_ov003_021602bc_552))->Allocate(Enum_ov003_021602bc_48);
        (*(void***)(obj + Enum_ov003_021602bc_916))[i] = buf;
        void* p = (*(void***)(obj + Enum_ov003_021602bc_916))[i];
        memset(p, 0, Enum_ov003_021602bc_48);

        Struct_ov003_021602bc* table = (Struct_ov003_021602bc*)(var0 + Enum_ov003_021602bc_17244);
        char* fmt = table->rows[i];
        if (fmt != 0) {
            void* dst = (*(void***)(obj + Enum_ov003_021602bc_916))[i];
#if defined(jpn)
            memcpy(dst, fmt, 0xc);
#else
            sprintf((char*)dst, fmt);
#endif
        }
    }
}
