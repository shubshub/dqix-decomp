#if defined(jpn)
#define REGION(j,u) (j)
#define data_ov020_0218d974 data_ov020_0218e1c4
#define data_ov020_0218d990 data_ov020_0218e1e0
#else
#define REGION(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int MessageSystem_GetInstance();
struct Struct_0205c77c;
extern "C" void func_0205c77c(struct Struct_0205c77c* p, int val);
extern "C" void func_0205cd28(unsigned char* obj);
extern "C" void func_0205c904(unsigned char* p, int a1);
struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
extern "C" int func_0205cde8(unsigned char* p);
extern "C" int func_0205cecc(void* s);
extern "C" int func_0205cb64(void* obj);
extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" void func_0200fb94(char* obj, unsigned char value);
extern "C" int func_020ab9c0(int flag);
extern "C" int func_0205c96c(unsigned char* p, int a1);
extern int data_ov020_0218d990[8];
extern int data_ov020_0218d974[7];

struct Struct_ov020_0218c840 {
    int f0;
    int f4;
    char pad[REGION(0x1cf, 0x23f) - 0x8];
    unsigned char unknown_23f_;
    unsigned char unknown_240_;
};

// USA: func_ov020_0218c840
extern "C" ARM void func_ov020_0218c840(struct Struct_ov020_0218c840* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();

    if (obj->f4 == 0) {
        obj->unknown_23f_ = 1;
        obj->unknown_240_ = 1;
        func_0205c77c((struct Struct_0205c77c*)((char*)obj + 0x10), 1);
        func_0205cd28((unsigned char*)obj + 0xc);
    }

    func_0205c904((unsigned char*)obj + 0xc, 1);

    struct Container0205a330* container = *(struct Container0205a330**)(g + REGION(0x230, 0x2e0));
    if (container != 0) {
        SpriteEntryList_AdvanceAnimations(container, 1);
    }

    if (func_0205cde8((unsigned char*)obj + 0xc) != 0) {
        if (obj->f4 > 5) {
            volatile unsigned int* ime = (volatile unsigned int*)0x4000000;
            *ime = (*ime & ~0x1f00) | 0x1300;
        }

        int var4 = g_keyManager.TestKeysPressed(0x401);
        int active = func_0205cecc((unsigned char*)obj + 0xc) >= 0;
        if ((var4 | active) != 0) {
            int idx = func_0205cb64((unsigned char*)obj + 0xc);
            if (func_0200fb9c((char*)battleStruct) == 6) return;

            if (func_020ab9c0(1) == 4) {
                func_0200fb94((char*)battleStruct, (unsigned char)data_ov020_0218d990[idx]);
                obj->f0 = -1;
                obj->f4 = -1;
                return;
            } else {
                func_0200fb94((char*)battleStruct, (unsigned char)data_ov020_0218d974[idx]);
                obj->f0 = -1;
                obj->f4 = -1;
                return;
            }
        }
    }

    func_0205c96c((unsigned char*)obj + 0xc, 0);
}
