#include <globaldefs.h>

extern "C" int func_ov023_021f6f18(void* obj);
extern "C" unsigned int func_ov023_021f6f10(void* obj);

struct BackgroundGraphics;
extern "C" void Background_Destroy(struct BackgroundGraphics* obj);

struct Struct_ov023_021f7984 {
    char pad0[4];
    void* owner;
};

// USA: func_ov023_021f7984
extern "C" ARM void func_ov023_021f7984(void* obj, void** arg1) {
#if defined(jpn)
 enum {regionalOffset0=0x24};
#else
 enum {regionalOffset0=0x28};
#endif
    void* node = *arg1;
    while (node != 0) {
        void* next = (void*)func_ov023_021f6f18(node);
        unsigned int type = func_ov023_021f6f10(node);
        if (type == 6) {
            Struct_ov023_021f7984* sub = (Struct_ov023_021f7984*)((char*)node + 0x20);
            if (sub != 0) {
                if ((void*)((char*)obj + regionalOffset0) == sub->owner) sub->owner = 0;
            }
        }
        node = next;
    }
    Background_Destroy((struct BackgroundGraphics*)((char*)obj + regionalOffset0));
}
