#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216982c_2400 = 0x800 };
enum { Enum_ov003_0216982c_2 = 4 };
enum { kRegione4 = 0xe0 };
enum { Enum_ov003_0216982c_132 = 0x80 };
enum { Enum_ov003_0216982c_134 = 0x82 };
enum { Enum_ov003_0216982c_136 = 0x84 };
enum { Enum_ov003_0216982c_138 = 0x86 };
enum { Enum_ov003_0216982c_140 = 0x88 };
enum { Enum_ov003_0216982c_142 = 0x8a };
enum { kRegion90 = 0x8c };
enum { Enum_ov003_0216982c_146 = 0x8e };
enum { Enum_ov003_0216982c_405 = 0x191 };
enum { Enum_ov003_0216982c_409 = 0x195 };
#else
enum { Enum_ov003_0216982c_2400 = 0x960 };
enum { Enum_ov003_0216982c_2 = 2 };
enum { kRegione4 = 0xe4 };
enum { Enum_ov003_0216982c_132 = 0x84 };
enum { Enum_ov003_0216982c_134 = 0x86 };
enum { Enum_ov003_0216982c_136 = 0x88 };
enum { Enum_ov003_0216982c_138 = 0x8a };
enum { Enum_ov003_0216982c_140 = 0x8c };
enum { Enum_ov003_0216982c_142 = 0x8e };
enum { kRegion90 = 0x90 };
enum { Enum_ov003_0216982c_146 = 0x92 };
enum { Enum_ov003_0216982c_405 = 0x195 };
enum { Enum_ov003_0216982c_409 = 0x199 };
#endif

#if defined(jpn)
extern "C" void func_02042428(void*, int);
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
struct Container020e0310;
extern "C" int KeyTable_Get(Container020e0310*, int);
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

extern "C" int MessageSystem_GetInstance();
extern "C" void func_02046380(void* obj);
extern "C" int StandardStrings_Get(int value);
extern "C" int Text_Append(char* dst, const char* src);

struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);

#if !defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov003_0216982c
extern "C" ARM void func_ov003_0216982c(unsigned char* self) {
    GameState* battle = GameState::GetInstance();
    int field = MessageSystem_GetInstance();
    void* ptr = GameState_GetParty(battle);

    func_0205de24((struct Struct0205de24*)(self + kRegione4), 0, 2);

    *(short*)(self + 0x100 + Enum_ov003_0216982c_132) = 0xb;
    *(short*)(self + 0x100 + Enum_ov003_0216982c_134) = 2;
    *(short*)(self + 0x100 + Enum_ov003_0216982c_136) = 0x14;
    *(short*)(self + 0x100 + Enum_ov003_0216982c_138) = 0;
    *(short*)(self + 0x100 + Enum_ov003_0216982c_140) = 0x10;
    *(short*)(self + 0x100 + Enum_ov003_0216982c_142) = Enum_ov003_0216982c_2;
    *(short*)(self + 0x100 + kRegion90) = 0xa;
    *(short*)(self + 0x100 + Enum_ov003_0216982c_146) = 0xe;
    self[Enum_ov003_0216982c_405] = 0;
    self[Enum_ov003_0216982c_409] = 1;

    memset(*(void**)(self + 0x7c), 0, Enum_ov003_0216982c_2400);

#if defined(jpn)
    func_02042428(*(void**)(self + 0x7c), 8);
    int msg = KeyTable_Get((Container020e0310*)(self + 0x64), 0x65);
    Text_Append((char*)*(void**)(self + 0x7c), (const char*)msg);
#else
    int msg = StandardStrings_Get(0x3f1);
    Text_Append((char*)*(void**)(self + 0x7c), (const char*)msg);
#endif

    func_02046380((void*)field);

    int value = *(int*)((char*)ptr + 0xf6c);
    func_020465c0((struct StoreStruct*)field, 0, value);
    func_020465f0((unsigned char*)field, 0, 7);
    func_020465d8((unsigned char*)field, 0, 1);

#if defined(jpn)
    Window_OpenPane(self + kRegione4, *(void**)(self + 0x7c), 0, 0, 0, 1, 0);
#else
    Window_OpenPane(self + kRegione4, *(void**)(self + 0x7c), 0, 0, 0, 1, 0, 0);
#endif
}
