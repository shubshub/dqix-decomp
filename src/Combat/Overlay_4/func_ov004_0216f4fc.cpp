#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov004_0216f4fc_9088 = 0x120, Enum_ov004_0216f4fc_16384 = 0x6000 };
#else
enum { Enum_ov004_0216f4fc_9088 = 0x2380, Enum_ov004_0216f4fc_16384 = 0x4000 };
#endif

extern "C" void func_ov004_0216ea38(void* ctx, int mode);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* node);
extern "C" void func_ov023_021f809c(void* node, void* ctx);
extern "C" int func_020c7170(char* destination, unsigned long capacity, const char* format, ...);

extern const char data_ov004_021707b0[];
struct Struct_ov004_02171048_5 { char pad[4]; char* ptr; };
extern Struct_ov004_02171048_5 data_ov004_02171048;

// USA: func_ov004_0216f4fc
extern "C" ARM int func_ov004_0216f4fc(void* ctx) {
    char buf[0x10];
    GameState* battle = GameState::GetInstance();
    char* dst;
    char* src;
    int k;
    void* code;
    void* entry;

    func_ov004_0216ea38(ctx, 4);
    MessageSystem_GetInstance();

    code = func_ov023_021f6880(func_ov011_021849c8(ctx), 0x65);
    if (code == NULL || func_ov023_021f6f10(code) != 8) code = NULL;
    if (code != NULL) {
        char* p = (char*)battle + Enum_ov004_0216f4fc_9088;
        p += Enum_ov004_0216f4fc_16384;
        func_020c7170(buf, 0xd, data_ov004_021707b0, *(long long*)(p + 0x48));

        dst = data_ov004_02171048.ptr + 0xe;
        src = buf;
        for (k = 0; k < 3; k++) {
            memcpy(dst, src, 4);
            dst += 4;
            src += 4;
            if (k != 2) *dst++ = '-';
        }
        *(char**)((char*)code + 0x20) = data_ov004_02171048.ptr + 0xe;
    }

    entry = func_ov023_021f6880(func_ov011_021849c8(ctx), 0x14);
    if (entry == NULL || func_ov023_021f6f10(entry) != 6) entry = NULL;
    if (entry != NULL) func_ov023_021f809c(entry, ctx);
    return 0;
}
