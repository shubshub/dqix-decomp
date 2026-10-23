#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_020474a8(void*, int, int, char*);
#endif
#include "GameState/GameState.h"

void* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* global);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* name);
struct Container020e0310;
int KeyTable_Get(struct Container020e0310* container, int key);
extern "C" void func_02046608(void* global, int mode, int fmt, char* dst, int size, int a5, int a6);
int AppendString02042058(char* dst, const char* src);

struct Struct_ov003_0216abd8 {
    char unknown_0_[0xf68];
    int unknown_f68_;
};

struct Struct_ov003_0216abd8_2 {
    char unknown_0_[0x600];
    char unknown_600_[0x100];
};

struct Struct_ov003_0216abd8_3 {
    char unknown_0_[0x64];
    char unknown_64_[0x18];
    struct Struct_ov003_0216abd8_2* unknown_7c_;
};

// USA: func_ov003_0216abd8
extern "C" ARM void func_ov003_0216abd8(struct Struct_ov003_0216abd8_3* arg0, char* arg1) {
#if defined(jpn)
    const volatile struct Struct_ov003_0216abd8_3* var0 = arg0;
#else
    struct Struct_ov003_0216abd8_3* var0 = arg0;
#endif
    if (arg1 == NULL) {
        return;
    }
    GameState* gameState = GameState::GetInstance();
    void* global = GetGlobalField0x1c020421a0();
    struct PartyData0216abd8* party = (struct PartyData0216abd8*)GetPtrField0x2a04_02010828(gameState);
    struct TextBuf0216abd8* buf = self_v->buf;
    func_02046380(global);
    if (party->amount != 0) {
        StoreInArray0x8b0_020465c0((struct StoreStruct*)global, 0, party->amount);
        SetByteInRange_020465f0((unsigned char*)global, 0, 0);
        int fmt = KeyTable_Get((struct Container020e0310*)self_v->messages, 0x443);
#if defined(jpn)
        func_020474a8(var2, 0xc, var5, var4->unknown_600_);
#else
#if defined(jpn)
        func_020474a8(var2, 0xc, fmt, var4->text);
#else
        func_02046608(var2, 0xc, var5, var4->unknown_600_, 0xe3, 0, 1);
#endif
#endif
        func_02042058(arg1, var4->unknown_600_);
    } else {
        char* name = (char*)gameState->GetProtagonist()->baseStats_;
        SetIndexedName02046574((struct Obj02046574*)global, 0, name);
        int fmt = KeyTable_Get((struct Container020e0310*)self_v->messages, 0x442);
#if defined(jpn)
        func_020474a8(var2, 0xc, var7, var4->unknown_600_);
#else
#if defined(jpn)
        func_020474a8(var2, 0xc, fmt, var4->text);
#else
        func_02046608(var2, 0xc, var7, var4->unknown_600_, 0xe3, 0, 1);
#endif
#endif
        func_02042058(arg1, var4->unknown_600_);
    }
}
