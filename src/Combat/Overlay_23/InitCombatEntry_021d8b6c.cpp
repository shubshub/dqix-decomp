#include <globaldefs.h>

struct Struct_0205d67c;
int GetFlagB4_0205d67c(Struct_0205d67c*);

struct Entry_0205d6a0;
void Window_ClosePane(Entry_0205d6a0*, int);

struct Cont0205d1e0;
void Window_ClearLayers(Cont0205d1e0*);

struct Cont0205d228;
void Window_DrawPanes(Cont0205d228*);

struct Cont0205d274;
void Window_FlushLayers(Cont0205d274*);

struct Obj0205d2bc;
void Window_TransferLayers(Obj0205d2bc*);

// USA: func_ov023_021d8b6c
ARM void InitCombatEntry_021d8b6c(void* obj) {
    void* sub = (char*)obj + 0x20;
    if (GetFlagB4_0205d67c((Struct_0205d67c*)sub)) {
        Window_ClosePane((Entry_0205d6a0*)sub, 1);
    }
    Window_ClearLayers((Cont0205d1e0*)sub);
    Window_DrawPanes((Cont0205d228*)sub);
    Window_FlushLayers((Cont0205d274*)sub);
    Window_TransferLayers((Obj0205d2bc*)sub);
}
