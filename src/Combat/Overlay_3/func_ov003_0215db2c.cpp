#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215db2c_2400 = 0x800 };
enum { Enum_ov003_0215db2c_954 = 0x3d2 };
enum { Enum_ov003_0215db2c_955 = 0x3d3 };
enum { kRegion7c = 0x94 };
enum { Enum_ov003_0215db2c_328 = 0x160 };
enum { kRegion98 = 0xb0 };
#else
enum { Enum_ov003_0215db2c_2400 = 0x960 };
enum { Enum_ov003_0215db2c_954 = 0x3ba };
enum { Enum_ov003_0215db2c_955 = 0x3bb };
enum { kRegion7c = 0x7c };
enum { Enum_ov003_0215db2c_328 = 0x148 };
enum { kRegion98 = 0x98 };
#endif

#include "std_library_functions.h"
#include "Input/Input.h"

struct StructA0205d5d0;
#if !defined(jpn)
#endif
extern "C" void func_ov003_0215e13c(char* base, char* dst, int flag);
extern "C" void func_ov003_0215de6c(char* base, void* buf);

struct Struct_ov003_0215db2c {
    char unk_0[0x30];
    int index;
};

struct Struct_ov003_0215db2c_2 {
    int unk_0;
    struct Struct_ov003_0215db2c unknown_4_[1];
};

static inline struct Struct_ov003_0215db2c* inline_ov003_0215db2c(struct Struct_ov003_0215db2c_2* list) { SDK_NULL_ASSERT(list); return list->unknown_4_; }

// USA: func_ov003_0215db2c
extern "C" ARM void func_ov003_0215db2c(char* self) {
    unsigned char mode = *(unsigned char*)(self + Enum_ov003_0215db2c_954);
    if (mode != 0) {
        int flag = 0;
        if (mode == 2 && g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
            if (inline_ov003_0215db2c((struct Struct_ov003_0215db2c_2*)(self + kRegion98))->index < 0) {
                return;
            }
            flag = 1;
        }
        memset(*(void**)(self + kRegion7c), 0, Enum_ov003_0215db2c_2400);
        unsigned char page = *(unsigned char*)(self + Enum_ov003_0215db2c_328);
        if (page == 1) {
            func_ov003_0215e13c(self, *(char**)(self + kRegion7c), flag);
        }
        if (page != 0) {
#if defined(jpn)
            Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), page, *(int*)(self + kRegion7c), 1);
#else
            Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), page, *(int*)(self + kRegion7c), 1, 0);
#endif
        }
    }
    if (*(unsigned char*)(self + Enum_ov003_0215db2c_955) != 0) {
        memset(*(void**)(self + kRegion7c), 0, Enum_ov003_0215db2c_2400);
        func_ov003_0215de6c(self, *(void**)(self + kRegion7c));
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), 0, *(int*)(self + kRegion7c), 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)(self + kRegion98), 0, *(int*)(self + kRegion7c), 1, 0);
#endif
        *(unsigned char*)(self + Enum_ov003_0215db2c_955) = 0;
    }
}
