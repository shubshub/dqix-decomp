#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02160134_1187 = 0x2cb };
enum { Enum_ov003_02160134_804 = 0x20c };
enum { Enum_ov003_02160134_912 = 0x278 };
enum { Enum_ov003_02160134_820 = 0x21c };
enum { Enum_ov003_02160134_792 = 0x200 };
enum { Enum_ov003_02160134_1124 = 0x28c };
enum { Enum_ov003_02160134_908 = 0x274 };
enum { Enum_ov003_02160134_1120 = 0x288 };
#else
enum { Enum_ov003_02160134_1187 = 0x4a3 };
enum { Enum_ov003_02160134_804 = 0x324 };
enum { Enum_ov003_02160134_912 = 0x390 };
enum { Enum_ov003_02160134_820 = 0x334 };
enum { Enum_ov003_02160134_792 = 0x318 };
enum { Enum_ov003_02160134_1124 = 0x464 };
enum { Enum_ov003_02160134_908 = 0x38c };
enum { Enum_ov003_02160134_1120 = 0x460 };
#endif

struct Obj0207fcb8;
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
struct Obj0207fd00;
void CallFunc0204c8f0OverEntries0207fd00(struct Obj0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Cont0207fd44;
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
extern "C" void func_ov003_02166fc4(void* obj);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Struct020e2794;
void UpdateEntryIfActive020e2794(struct Struct020e2794* self, void* b);
extern "C" void func_ov003_0216039c(void* obj);
struct Obj02167548;
void ProcessBuffersIfActive_02167548(struct Obj02167548* obj);
struct Container0205a3d0;
struct Elem0205a3d0;
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov003_02160134
extern "C" ARM void func_ov003_02160134(char* arg0) {
    if (*(unsigned char*)(arg0 + Enum_ov003_02160134_1187) == 0) return;

    void* var0 = *(void**)(arg0 + Enum_ov003_02160134_804);
    if (var0 != 0) {
        func_0207fcb8((struct Struct_0207fcb8*)var0);
        func_0207fd00((struct Struct_0207fd00*)var0);
        func_0207fe80(var0, 1, 2, 1);
        func_0207fd44((struct Struct_0207fd44_2*)var0);
    }
    func_ov003_02166fc4(arg0);

    if (*(void**)(arg0 + Enum_ov003_02160134_912) != 0 && func_020e28dc((struct Struct_020e28dc*)*(void**)(arg0 + Enum_ov003_02160134_912)) != 0) {
        func_020e2794((struct Struct_020e2794_2*)*(void**)(arg0 + Enum_ov003_02160134_912), arg0 + Enum_ov003_02160134_820);
    }
    func_ov003_0216039c(arg0);

    if (*(struct Struct_ov003_02160134**)(arg0 + Enum_ov003_02160134_792) != 0) {
        func_ov003_02167548(*(struct Struct_ov003_02160134**)(arg0 + Enum_ov003_02160134_792));
    }

    if (!(*(unsigned int*)(arg0 + Enum_ov003_02160134_1124) & 0x2000000)) return;

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + kRegionValue38C_274);
    SpriteEntryList_PlayAnimation(cont, 1);

    cont = *(struct Container0205a3d0**)(obj + kRegionValue38C_274);
    struct Elem0205a3d0* e = SpriteEntryList_Find(cont, 0);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }

    cont = *(struct Container0205a3d0**)(obj + kRegionValue38C_274);
    e = SpriteEntryList_Find(cont, 1);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) |= 8;
    }

    cont = *(struct Container0205a3d0**)(obj + kRegionValue38C_274);
    int arg = *(int*)(obj + kRegionValue460_288);
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, arg);

    cont = *(struct Container0205a3d0**)(obj + kRegionValue38C_274);
    SpriteEntryList_SetPosition(cont, 1, 0xd7, 0x96);

    SpriteContext_DrawEntries(obj + kRegionValue334_21C);
}
