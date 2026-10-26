#include <globaldefs.h>

struct Cont0205d1e0;
extern "C" void Window_ClearLayers(struct Cont0205d1e0* obj);
struct Cont0205d228;
extern "C" void Window_DrawPanes(struct Cont0205d228* obj);
extern "C" void func_0205da88(void* obj, int a, int b, int c);
struct Cont0205d274;
extern "C" void Window_FlushLayers(struct Cont0205d274* obj);
extern "C" void func_ov003_0217033c(char* base);
#if defined(jpn)
#define func_ov003_021704e8 func_ov003_0216fd3c
extern "C" void func_ov003_0216fb7c(void* self);
#define func_ov003_021702e4 func_ov003_0216fb7c
#else
struct Struct_ov003_0217019c;
extern "C" void func_ov003_021702e4(struct Struct_ov003_0217019c* self);
#endif
extern "C" void func_ov003_021704e8(char* obj);
struct Struct_ov003_0217019c;
extern "C" void* Zone3D_GetInstance(void);
struct Struct_ov003_0216dee4;
extern "C" void func_ov003_0216dee4(struct Struct_ov003_0216dee4* obj, int idx, int v14, int v18, int arg4, int arg5, int arg6);

struct Struct_ov003_0217019c_2 {
    char pad0[1];
    signed char field1;
    char pad2[0x3a];
    void* field3c;
    char pad3[0x3b0 - 0x40];
    int unknown_3b0_[8];
};

// USA: func_ov003_0217019c
extern "C" ARM void func_ov003_0217019c(struct Struct_ov003_0217019c_2* self) {
    if (self->field3c == 0) return;
    signed char f1 = self->field1;
    if (f1 == 0 || f1 == 1 || f1 == 7) return;

    Window_ClearLayers((struct Cont0205d1e0*)self->field3c);
    Window_DrawPanes((struct Cont0205d228*)self->field3c);
    func_0205da88(self->field3c, 2, 1, 1);
    Window_FlushLayers((struct Cont0205d274*)self->field3c);

    func_ov003_0217033c((char*)self);
    func_ov003_021704e8((char*)self);
    func_ov003_021702e4((struct Struct_ov003_0217019c*)self);

#if !defined(jpn)
    signed char var1 = self->field1;
    switch (var1) {
        case 0:
        case 1:
            return;
    }
    Zone3D_GetInstance();

    int v14 = 0x51;
    int v18 = 0x2e;
    int var4 = 0x40;
    for (int i = 0; i < 8; i++) {
        int val = self->unknown_3b0_[i];
        if (val < 0) return;
        func_ov003_0216dee4((struct Struct_ov003_0216dee4*)((char*)self + 0x68), val + 9, v14, v18, var4, 2, 3);
        var4 += 1;
        v18 += 0x10;
    }
#endif
}
