#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e4fc8_12 = 0x4 };
#else
enum { Enum_ov025_021e4fc8_12 = 0xc };
#endif

#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" void* func_02058658(void* obj, int id);
extern "C" void* func_ov025_021e8cf0(char* base, int idx);
extern "C" void func_0200fd48(GameState* battleStruct, int id);
extern "C" void func_02059cc8(unsigned char* obj);
extern int data_ov025_021ef988;

struct Struct_ov025_021e4fc8 { char pad[8]; unsigned char field8; };

// USA: func_ov025_021e4fc8
extern "C" ARM int func_ov025_021e4fc8(struct Struct_ov025_021e4fc8* p) {
    void* slot = func_ov025_021e8cf0(*(char**)((char*)&data_ov025_021ef988 + Enum_ov025_021e4fc8_12), p->field8);
    if (slot) {
        GameState* bs = GameState::GetInstance();
        func_0200fd48(bs, *(int*)slot);
        void* obj = func_02057924();
        void* record = func_02058658(obj, *(int*)slot);
        if (record) {
            func_02059cc8((unsigned char*)record);
        }
    }
    return 1;
}
