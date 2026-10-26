#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);

extern short data_ov000_021834bc[];

// USA: func_ov000_021775a4
extern "C" ARM void func_ov000_021775a4(void* base, char* dst) {
    if (dst == NULL) return;

#if defined(jpn)
    signed char cursor = *(signed char*)((char*)base + 0x1f00 + 0xa2);
#else
    signed char cursor = *(signed char*)((char*)base + 0x1d00 + 0x6a);
#endif
    int n = 0;

    if (func_ov000_0217542c(base)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    void* p = LinkSession_GetInstance();
    int count = 3;
    if (LinkSession_IsActive((int*)p)) {
        if (GameState_GetProtagonistIndex(GameState::GetInstance()) == 0) count = 4;
    }

    struct Container020e0310* c = (struct Container020e0310*)((char*)base + 0xb8);
    for (int i = 0; i < count; i++) {
        int name = KeyTable_Get(c, data_ov000_021834bc[i]);
        Text_AppendNTag(dst, n, (const char*)name);
        if (i != count - 1) {
            int sep = KeyTable_Get(c, 0);
            Text_Append(dst, (const char*)sep);
        }
        n++;
    }
}
