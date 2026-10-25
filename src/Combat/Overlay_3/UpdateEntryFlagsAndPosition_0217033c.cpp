#include <globaldefs.h>

struct Container0205a3d0;
struct Elem0205a3d0;
#if defined(jpn)
void SpriteEntryList_SetPosition(Container0205a3d0*, int, short, short);
#endif
extern "C" void func_ov003_021703f0(void*, short*, short*);
void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);
struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov003_0217033c  (semantic: UpdateEntryFlagsAndPosition_0217033c)
extern "C" ARM void func_ov003_0217033c(char* base) {
    Container0205a3d0* cont = *(Container0205a3d0**)(base + 0xa4);
    if (cont == NULL) return;

    short outA, outB;
    func_ov003_021703f0(base, &outA, &outB);

    Elem0205a3d0* e;
    if (outA != 0 && outB != 0) {
        SpriteEntryList_PlayAnimation(cont, 0);
        e = SpriteEntryList_Find(cont, 0);
        if (e != NULL) {
            *(unsigned char*)((char*)e + 0x15) |= 8;
        }
        SpriteEntryList_AdvanceAnimations((Container0205a330*)cont, 2);
#if defined(jpn)
        SpriteEntryList_SetPosition(cont, 0, outA, outB);
#else
        short a, b;
        b = outB;
        a = outA;
        e = SpriteEntryList_Find(cont, 0);
        if (e != NULL) {
            *(short*)((char*)e + 0x4) = a;
            *(short*)((char*)e + 0x6) = b;
        }
#endif
        SpriteContext_DrawEntries(base + 0x68);
        return;
    }
    e = SpriteEntryList_Find(cont, 0);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
