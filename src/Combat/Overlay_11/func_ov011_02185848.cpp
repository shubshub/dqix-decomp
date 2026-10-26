#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov023_021f6880(void* list, int id);
extern "C" ARM int func_ov023_021f6f10(void* obj);

struct Struct_ov004_02153e20;
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20* self, unsigned short val, unsigned int x, unsigned int y);

// USA: func_ov011_02185848
extern "C" ARM int func_ov011_02185848(struct TaggedNumber02184c30* params, int count) {
    int id = func_ov011_02184c30(&params[0]);
    int id2 = func_ov011_02184c30(&params[1]);
    int unk2 = func_ov011_02184c30(&params[2]);
    int var3 = func_ov011_02184c30(&params[3]);
    void* objects = func_ov011_021849c8(func_ov017_021b2164());
    void* object = func_ov023_021f6880(objects, id);
    void* var6 = func_ov023_021f6880(objects, id2);
    if (object == 0 || var6 == 0)
        return 0;
    if (func_ov023_021f6f10(object) != 7)
        return 0;

    return func_ov023_021f9b30((struct Struct_ov004_02153e20*)object, id2,(unsigned short)var3, (unsigned short)unk2) ? 1 : 0;
}
