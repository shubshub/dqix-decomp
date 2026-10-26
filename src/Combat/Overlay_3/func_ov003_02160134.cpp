#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02160134_1187 = 0x2cb };
enum { Enum_ov003_02160134_804 = 0x20c };
enum { Enum_ov003_02160134_912 = 0x278 };
enum { kRegionValue334_21C = 0x21c };
enum { Enum_ov003_02160134_792 = 0x200 };
enum { Enum_ov003_02160134_1124 = 0x28c };
enum { Enum_ov003_02160134_908 = 0x274 };
enum { Enum_ov003_02160134_1120 = 0x288 };
#else
enum { Enum_ov003_02160134_1187 = 0x4a3 };
enum { Enum_ov003_02160134_804 = 0x324 };
enum { Enum_ov003_02160134_912 = 0x390 };
enum { kRegionValue334_21C = 0x334 };
enum { Enum_ov003_02160134_792 = 0x318 };
enum { Enum_ov003_02160134_1124 = 0x464 };
enum { Enum_ov003_02160134_908 = 0x38c };
enum { Enum_ov003_02160134_1120 = 0x460 };
#endif

struct Struct_0207fcb8;
extern "C" void func_0207fcb8(struct Struct_0207fcb8* obj);
struct Struct_0207fd00;
extern "C" void func_0207fd00(struct Struct_0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Struct_0207fd44_2;
extern "C" void func_0207fd44(struct Struct_0207fd44_2* obj);
extern "C" void func_ov003_02166fc4(void* obj);
struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
struct Struct_020e2794_2;
extern "C" void func_020e2794(struct Struct_020e2794_2* self, void* b);
extern "C" void func_ov003_0216039c(void* obj);
struct Struct_ov003_02160134;
extern "C" void func_ov003_02167548(struct Struct_ov003_02160134* obj);
struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
extern "C" void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov003_02160134
extern "C" ARM void func_ov003_02160134(char* obj) {
    if (*(unsigned char*)(obj + Enum_ov003_02160134_1187) == 0) return;

    void* sub = *(void**)(obj + Enum_ov003_02160134_804);
    if (sub != 0) {
        func_0207fcb8((struct Struct_0207fcb8*)sub);
        func_0207fd00((struct Struct_0207fd00*)sub);
        func_0207fe80(sub, 1, 2, 1);
        func_0207fd44((struct Struct_0207fd44_2*)sub);
    }
    func_ov003_02166fc4(obj);

    if (*(void**)(obj + Enum_ov003_02160134_912) != 0 && func_020e28dc((struct Struct_020e28dc*)*(void**)(obj + Enum_ov003_02160134_912)) != 0) {
        func_020e2794((struct Struct_020e2794_2*)*(void**)(obj + Enum_ov003_02160134_912), obj + kRegionValue334_21C);
    }
    func_ov003_0216039c(obj);

    if (*(struct Struct_ov003_02160134**)(obj + Enum_ov003_02160134_792) != 0) {
        func_ov003_02167548(*(struct Struct_ov003_02160134**)(obj + Enum_ov003_02160134_792));
    }

    if (!(*(unsigned int*)(obj + Enum_ov003_02160134_1124) & 0x2000000)) return;

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + Enum_ov003_02160134_908);
    SpriteEntryList_PlayAnimation(cont, 1);

    cont = *(struct Container0205a3d0**)(obj + Enum_ov003_02160134_908);
    struct Elem0205a3d0* e = SpriteEntryList_Find(cont, 0);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }

    cont = *(struct Container0205a3d0**)(obj + Enum_ov003_02160134_908);
    e = SpriteEntryList_Find(cont, 1);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) |= 8;
    }

    cont = *(struct Container0205a3d0**)(obj + Enum_ov003_02160134_908);
    int arg = *(int*)(obj + Enum_ov003_02160134_1120);
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, arg);

    cont = *(struct Container0205a3d0**)(obj + Enum_ov003_02160134_908);
    SpriteEntryList_SetPosition(cont, 1, 0xd7, 0x96);

    SpriteContext_DrawEntries(obj + kRegionValue334_21C);
}
