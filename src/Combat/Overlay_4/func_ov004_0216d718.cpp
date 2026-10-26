#include <globaldefs.h>
#if defined(jpn)
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021fa598(void*);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_02012028(void*, unsigned char);
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" int func_020c7170(char* destination, unsigned long capacity, const char* format, ...);
extern const char data_ov004_02170fac[];
struct Struct_ov004_0216d718 { char pad[0x20]; char* text; };
struct Struct_ov004_0216d718_2 { char pad[0x48]; unsigned long long number; };
static inline char* inline_ov004_0216d718(GameState* state) { return (char*)state + 0x120; }
static inline Struct_ov004_0216d718_2* inline_ov004_0216d718_2(char* arg0) { return (Struct_ov004_0216d718_2*)(arg0 + 0x6000); }
extern "C" ARM int func_ov004_0216d718(void* self)
{
    void* entry = func_ov023_021f6880(func_ov011_021849c8(self), 0x192);
    if (entry != 0 && func_ov023_021f6f10(entry) == 4)
        func_ov023_021fa598(entry);
    MessageSystem_GetInstance();
    GameState* state = GameState::GetInstance();
    func_02012028(state, 0);
    SafeAllocator* allocator = (SafeAllocator*)((char*)func_ov011_021845f8(self, 5) + 4);
    char* buffer = (char*)allocator->Allocate(0x400);
    memset(buffer, 0, 0x400);
    Struct_ov004_0216d718* record = (Struct_ov004_0216d718*)func_ov023_021f6880(func_ov011_021849c8(self), 0x4f);
    if (record == 0 || func_ov023_021f6f10(record) != 8)
        record = 0;
    if (record != 0) {
        char number[13];
        func_020c7170(number, 13, data_ov004_02170fac, inline_ov004_0216d718_2(inline_ov004_0216d718(state))->number);
        char* in = number;
        char* out = buffer;
        for (int i = 0; i < 3; i++) {
            memcpy(out, in, 4);
            out += 4;
            in += 4;
            if (i != 2)
                *out++ = '-';
        }
        record->text = buffer;
    }
    return 0;
}
#else

// USA: func_ov004_0216d718
extern "C" ARM int func_ov004_0216d718(void) {
    return 0;
}

#endif
