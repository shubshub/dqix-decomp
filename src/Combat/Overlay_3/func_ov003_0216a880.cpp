#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" int WindowPane_IsReady(unsigned char* obj);

struct Struct0200fb08;
extern "C" int GameState_GetLanguage(struct Struct0200fb08*);

extern "C" void SpriteContext_DrawSprite(void* dst, void* src);

extern unsigned char data_ov003_0217f530;
extern unsigned char data_ov003_0217f532;
extern unsigned char data_ov003_0217f533;
extern unsigned char data_ov003_0217f531;

// USA: func_ov003_0216a880
extern "C" ARM void func_ov003_0216a880(unsigned char* obj) {
#if defined(jpn)
    enum { entriesOffset = 0xe0, baseOffset = 0x4d0, listOffset = 0x47c };
#else
    enum { entriesOffset = 0xe4, baseOffset = 0x4d4, listOffset = 0x480 };
#endif
    struct Elem_0205d81c* e = func_0205d81c((struct Struct_0205d81c*)(obj + entriesOffset), 2);
    if (e == 0) return;
    if (!WindowPane_IsReady((unsigned char*)e)) return;

#if !defined(jpn)
    int key = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
#endif

    unsigned int lo = 0x90000;
#if defined(jpn)
    unsigned int hi = 0xc9000;
#else
    unsigned int hi = 0xc6000;
#endif
    unsigned int idx = 6;
#if !defined(jpn)
    int i;
    for (i = 0; i < 5; i++) {
        if (key == (&data_ov003_0217f530)[i * 4]) {
            lo = (&data_ov003_0217f532)[i * 4] << 0xc;
            idx = (&data_ov003_0217f531)[i * 4];
            hi = (&data_ov003_0217f533)[i * 4] << 0xc;
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
