#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215de6c_955 = 0x3d3 };
enum { Enum_ov003_0215de6c_972 = 0x3e4 };
#else
enum { Enum_ov003_0215de6c_955 = 0x3bb };
enum { Enum_ov003_0215de6c_972 = 0x3cc };
#endif

#if defined(jpn)
struct Container020e0310;
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" void func_020474a8(int, int, void*, void*);
#endif
#include "GameState/GameState.h"

struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_02046380(void* global);
extern "C" int StandardStrings_Get(int value);
extern "C" void MessageSystem_FormatText(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);

// USA: func_ov003_0215de6c
extern "C" ARM void func_ov003_0215de6c(char* base, void* buf) {
    GameState* battleStruct = GameState::GetInstance();
    int field = MessageSystem_GetInstance();
    void* ptr = GameState_GetParty(battleStruct);

    unsigned char flag = *(unsigned char*)(base + Enum_ov003_0215de6c_955);
    int value = *(int*)((char*)ptr + 0xf6c);
    if (flag == 2) {
        value -= *(int*)(base + Enum_ov003_0215de6c_972);
    }

    func_02046380((void*)field);

    func_020465c0((struct StoreStruct*)field, 0, value);
    func_020465f0((unsigned char*)field, 0, 7);
    func_020465d8((unsigned char*)field, 0, 1);

#if defined(jpn)
    int fmt = KeyTable_Get((Container020e0310*)(base + 0x7c), 0xa);
    func_020474a8(field, 8, (void*)fmt, buf);
#else
    int fmt = StandardStrings_Get(0x3f1);
    MessageSystem_FormatText(field, 8, (void*)fmt, buf, 0x100, 0, 0);
#endif
}
