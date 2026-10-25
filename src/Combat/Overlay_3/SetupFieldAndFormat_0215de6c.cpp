#include <globaldefs.h>
#if defined(jpn)
enum { kRegion3bb = 0x3d3 };
enum { kRegion3cc = 0x3e4 };
#else
enum { kRegion3bb = 0x3bb };
enum { kRegion3cc = 0x3cc };
#endif

#if defined(jpn)
struct Container020e0310;
int KeyTable_Get(Container020e0310*, int);
extern "C" void func_020474a8(int, int, void*, void*);
#endif
#include "GameState/GameState.h"

struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
int MessageSystem_GetInstance();
extern "C" void func_02046380(void* global);
int StandardStrings_Get(int value);
extern "C" void MessageSystem_FormatText(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);

// USA: func_ov003_0215de6c
ARM void SetupFieldAndFormat_0215de6c(char* base, void* buf) {
    GameState* battleStruct = GameState::GetInstance();
    int field = MessageSystem_GetInstance();
    void* ptr = GameState_GetParty(battleStruct);

    unsigned char flag = *(unsigned char*)(base + kRegion3bb);
    int value = *(int*)((char*)ptr + 0xf6c);
    if (flag == 2) {
        value -= *(int*)(base + kRegion3cc);
    }

    func_02046380((void*)field);

    StoreInArray0x8b0_020465c0((struct StoreStruct*)field, 0, value);
    SetByteInRange_020465f0((unsigned char*)field, 0, 7);
    SetByteAtIndex_020465d8((unsigned char*)field, 0, 1);

#if defined(jpn)
    int fmt = KeyTable_Get((Container020e0310*)(base + 0x7c), 0xa);
    func_020474a8(field, 8, (void*)fmt, buf);
#else
    int fmt = StandardStrings_Get(0x3f1);
    MessageSystem_FormatText(field, 8, (void*)fmt, buf, 0x100, 0, 0);
#endif
}
