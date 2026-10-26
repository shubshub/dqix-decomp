#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215b478_2400 = 0x800 };
enum { Enum_ov003_0215b478_2 = 4 };
#else
enum { Enum_ov003_0215b478_2400 = 0x960 };
enum { Enum_ov003_0215b478_2 = 2 };
#endif

#if defined(jpn)
extern "C" void func_02042428(void*, int);
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
extern "C" void func_02042158(void*, int);
extern char data_ov003_0217e68e[], data_ov003_0217e696[];
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

// USA: func_ov003_0215b478
extern "C" ARM void func_ov003_0215b478(unsigned char* self) {
    GameState* battle = GameState::GetInstance();
    int field = MessageSystem_GetInstance();

    func_0205de24((struct Struct0205de24*)(self + 0xf4), 0, 2);

    *(short*)(self + 0x100 + 0x94) = 0xb;
    *(short*)(self + 0x100 + 0x96) = 2;
    *(short*)(self + 0x100 + 0x98) = 0x14;
    *(short*)(self + 0x100 + 0x9a) = 0;
    *(short*)(self + 0x100 + 0x9c) = 0x10;
    *(short*)(self + 0x100 + 0x9e) = Enum_ov003_0215b478_2;
    *(short*)(self + 0x100 + 0xa0) = 0xa;
    *(short*)(self + 0x100 + 0xa2) = 0xe;
    self[0x1a5] = 0;
    self[0x1a9] = 1;

    memset(*(void**)(self + 0x7c), 0, Enum_ov003_0215b478_2400);

#if defined(jpn)
    func_02042428(*(void**)(self + 0x7c), 8);
    Text_Append(*(char**)(self + 0x7c), data_ov003_0217e68e);
    func_02042158(*(void**)(self + 0x7c), 2);
    Text_Append(*(char**)(self + 0x7c), data_ov003_0217e696);
#else
    int msg = StandardStrings_Get(0x3f1);
    Text_Append((char*)*(void**)(self + 0x7c), (const char*)msg);
#endif

    func_02046380((void*)field);

    void* ptr = GameState_GetParty(battle);
    int value = *(int*)((char*)ptr + 0xf6c);
    func_020465c0((struct StoreStruct*)field, 0, value);
    func_020465f0((unsigned char*)field, 0, 7);
    func_020465d8((unsigned char*)field, 0, 1);

#if defined(jpn)
    Window_OpenPane(self + 0xf4, *(void**)(self + 0x7c), 0, 0, 0, 1, 0);
#else
    Window_OpenPane(self + 0xf4, *(void**)(self + 0x7c), 0, 0, 0, 1, 0, 0);
#endif
}
