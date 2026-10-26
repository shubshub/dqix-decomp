#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov004_02153e20;

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20* self, unsigned short val, unsigned int x, unsigned int y);

// USA: func_ov004_0216b2c8
extern "C" ARM void func_ov004_0216b2c8(void* ctx, int id, int id2, int val) {
    void* objects = func_ov011_021849c8(ctx);
    void* object = func_ov023_021f6880(objects, id);
    void* var2 = func_ov023_021f6880(objects, id2);
    if (object == NULL || var2 == NULL) {
        return;
    }
    if (func_ov023_021f6f10(object) != 7) {
        return;
    }
    if (!func_ov023_021f9b30((struct Struct_ov004_02153e20*)object, id2, (unsigned short)val, 0)) {
        return;
    }
}
