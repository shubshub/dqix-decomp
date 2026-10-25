#include <globaldefs.h>

struct Struct_0205d67c;
int GetFlagB4_0205d67c(struct Struct_0205d67c*);

struct Entry_0205d6a0;
void Window_ClosePane(struct Entry_0205d6a0*, int);

struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4*);

struct InitTarget0205cfd4;
void Window_Init(struct InitTarget0205cfd4*);

// USA: func_ov023_021d8af8  (semantic: ResetCombatEntry_021d8af8)
extern "C" ARM void func_ov023_021d8af8(void* obj) {
    void* sub = (char*)obj + 0x20;
    if (GetFlagB4_0205d67c((struct Struct_0205d67c*)sub)) {
        Window_ClosePane((struct Entry_0205d6a0*)sub, 1);
    }
    *(int*)obj = 0;
    int* reg = (int*)0x4001000;
    *reg = (*reg & ~0x1f00) | (*(int*)((char*)obj + 0x1c) << 8);
    ClearFlag0x11IfSet((struct Struct02074bf4*)((char*)obj + 8));
    Window_Init((struct InitTarget0205cfd4*)sub);
    *(unsigned char*)((char*)obj + 0x11a) = 0;
    *(unsigned char*)((char*)obj + 0x11b) = 0;
    *(unsigned char*)((char*)obj + 0x11c) = 0;
    *(int*)obj = 0;
    *(int*)((char*)obj + 4) = 0;
}
