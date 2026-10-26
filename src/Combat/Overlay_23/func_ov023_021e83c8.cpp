#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { Enum_ov023_021e83c8_1550 = 0x604, Enum_ov023_021e83c8_56 = 0x14 };
#else
enum { Enum_ov023_021e83c8_1550 = 0x60e, Enum_ov023_021e83c8_56 = 0x38 };
#endif
namespace {
struct Struct_ov023_021e83c8 {
    unsigned char unknown0[0x4c];
    Container020e0310 messages;
    unsigned char unknown54[0x5d8 - 0x54];
    char* text;
    unsigned char unknown_5dc_[Enum_ov023_021e83c8_1550 - 0x5dc];
    unsigned short unknown_60e_;
    unsigned char unknown_610_;
};
struct Struct_ov023_021fd75c_2 {
    unsigned char unknown0[Enum_ov023_021e83c8_56];
    int first;
    int second;
};
}

extern "C" int MessageSystem_GetInstance(void);

struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

#if defined(jpn)
extern "C" void func_020474a8(void* messages, unsigned char font, const char* format, char* output);
#else
extern "C" ARM void MessageSystem_FormatText(void* a, int b, void* c, void* d, int e, int f, int g);
#endif

struct Struct0200fb08;
extern "C" ARM unsigned char GameState_GetLanguage(Struct0200fb08* obj);

#if defined(jpn)
#define data_ov023_021fd75c data_ov023_021fd760
#endif
extern Struct_ov023_021fd75c_2 data_ov023_021fd75c;
extern char data_ov023_021fddb0;
extern char data_ov023_021fddb4;

struct Struct_01ff8b48_15 { char pad[0x38]; int a; int b; };

// USA: func_ov023_021e83c8
// JPN: func_ov023_021e8404
extern "C" ARM void func_ov023_021e83c8(void* obj) {
    Struct_ov023_021e83c8* state = static_cast<Struct_ov023_021e83c8*>(obj);
    int field = MessageSystem_GetInstance();

    int* var2;
    int i;
    int arr2[2];
    int arr1[2];
    arr2[0] = state->unknown_60e_;
    arr2[1] = state->unknown_610_;
    arr1[0] = data_ov023_021fd75c.first;
    arr1[1] = data_ov023_021fd75c.second;

    var2 = arr1;
    i = 0;
    for (; i < 2; i++) {
        func_020465c0((struct StoreStruct*)field, i, arr2[i]);
        func_020465d8((unsigned char*)field, i, 1);
        func_020465f0((unsigned char*)field, i, var2[i] & 0xff);
    }

    int key = KeyTable_Get(&state->messages, 0);
#if defined(jpn)
    func_020474a8(((void*)(field)), 0xa, ((const char*)(key)), state->text);
#else
    MessageSystem_FormatText(((void*)(field)), 0xa, ((void*)(key)), state->text, 0x100, 0, 0);

    int a, b;
    char* p1 = strstr(state->text, &data_ov023_021fddb0);
    char* p2 = strstr(p1 + 1, &data_ov023_021fddb0);
    a = 0x82; b = 0xb4;
    int norm = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    switch (norm) {
    case 2:
    case 5:
        a = 0xa5; b = 0xc1;
        break;
    case 3:
        a = 0x92; b = 0xb6;
        break;
    }

    char buf1[4];
    char buf2[4];
    sprintf(buf1, &data_ov023_021fddb4, a);
    sprintf(buf2, &data_ov023_021fddb4, b);
    memcpy(p1 + 3, buf1, 3);
    memcpy(p2 + 3, buf2, 3);
#endif
}

#if defined(jpn)
#undef data_ov023_021fd75c
#endif
