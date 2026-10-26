#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

extern "C" void* func_ov000_02160130(void);
extern "C" unsigned char func_ov025_021dcc64(void* obj);
extern "C" void func_0202edb4(char* obj, int a, int b, int c, int d);

struct Struct_ov025_021e7248 {
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
};

// USA: func_ov025_021e7248
extern "C" ARM int func_ov025_021e7248(struct Struct_ov025_021e7248* p) {
#if defined(jpn)
 enum {regionalOffset0=0x7000, regionalOffset1=0x1c5};
#else
 enum {regionalOffset0=0x6000, regionalOffset1=0xfd5};
#endif
    void* w = func_ov000_02160130();
    if (w != 0) {
        *(unsigned char*)((char*)w + regionalOffset0 + regionalOffset1) = 1;
        if (func_ov025_021dcc64(w) != 0) {
            return 1;
        }
    }
    GameState* bs = GameState::GetInstance();
    char* field = (char*)bs->GetCamera();
    func_0202edb4(field, (int)((char*)p + 8), p->f14, p->f18, p->f1c);
    return 1;
}
