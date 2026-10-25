#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern int WindowPane_IsReady(unsigned char* obj);

struct Struct0200fb08;
extern int GameState_GetLanguage(struct Struct0200fb08*);

extern "C" void SpriteContext_DrawSprite(void* dst, void* src);

extern unsigned char data_ov003_0217f530;
extern unsigned char data_ov003_0217f532;
extern unsigned char data_ov003_0217f533;
extern unsigned char data_ov003_0217f531;

// USA: func_ov003_0216a880
extern "C" ARM void func_ov003_0216a880(unsigned char* arg0) {
#if defined(jpn)
    enum { Enum_ov003_0216a880_228 = 0xe0, Enum_ov003_0216a880_1236 = 0x4d0, Enum_ov003_0216a880_1152 = 0x47c };
#else
    enum { Enum_ov003_0216a880_228 = 0xe4, Enum_ov003_0216a880_1236 = 0x4d4, Enum_ov003_0216a880_1152 = 0x480 };
#endif
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + entriesOffset), 2);
    if (e == 0) return;
    if (!WindowPane_IsReady((unsigned char*)e)) return;

#if !defined(jpn)
    int key = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
#endif

    unsigned int var2 = 0x90000;
#if defined(jpn)
    unsigned int var3 = 0xc9000;
#else
    unsigned int var3 = 0xc6000;
#endif
    unsigned int var4 = 6;
#if !defined(jpn)
    int var5;
    for (var5 = 0; var5 < 5; var5++) {
        if (var1 == (&data_ov003_0217f530)[var5 * 4]) {
            var2 = (&data_ov003_0217f532)[var5 * 4] << 0xc;
            var4 = (&data_ov003_0217f531)[var5 * 4];
            var3 = (&data_ov003_0217f533)[var5 * 4] << 0xc;
            break;
        }
    }
#endif

    unsigned int off0 = idx * 0x28;
    unsigned char* p0 = *(unsigned char**)(obj + baseOffset) + off0;
    *(unsigned int*)(p0 + 0x14) = lo;
    *(unsigned int*)(p0 + 0x18) = 0x61000;
    SpriteContext_DrawSprite(obj + listOffset, *(unsigned char**)(obj + baseOffset) + off0);

    unsigned int off1 = (idx + 1) * 0x28;
    unsigned char* p1 = *(unsigned char**)(obj + baseOffset) + off1;
    *(unsigned int*)(p1 + 0x14) = hi;
    *(unsigned int*)(p1 + 0x18) = 0x61000;
    SpriteContext_DrawSprite(obj + listOffset, *(unsigned char**)(obj + baseOffset) + off1);
}
