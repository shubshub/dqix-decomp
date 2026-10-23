#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov024_021f6f10(void* arg0);
struct Struct_02000c9c_8;
extern "C" unsigned char func_0200fb08(struct Struct_02000c9c_8* arg0);
extern "C" void* func_ov023_021f79e4(void* arg0);

struct Struct_0204b988;
extern "C" void func_0204b988(struct Struct_0204b988*, unsigned int, int, int, unsigned short);

struct Obj0204b8d0;
void Background_DrawScreen(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
void Background_UploadMap(struct List0204b0e8*, void*);

struct Struct_ov004_0215de9c;
extern "C" void func_ov023_021fb25c(Struct_ov004_0215de9c*, unsigned int, unsigned int, unsigned int, int);

// USA: func_ov004_02165c04
extern "C" ARM int func_ov004_02165c04(void* arg0) {
    unsigned char var0 = func_0200fb08((struct Struct_02000c9c_8*)GameState::GetInstance());
    unsigned short var1 = 0x4a;
    unsigned int var2 = 0;
    switch (var0) {
    case 2: var2 = 1; var1 = 0x5a; break;
    case 4: var2 = 2; var1 = 0x80; break;
    case 3: var2 = 3; break;
    case 5: var2 = 4; var1 = 0x78; break;
    }

    void* var3 = func_ov023_021f6880(func_ov011_021849c8(arg0), 3);
    if (!var3) return 0;
    if (func_ov024_021f6f10(var3) != 2) return 0;

    *(unsigned char*)((char*)node + 0xc) |= 1;
    void* list = GetFieldPtrAt_021f79e4_021f79e4(node);
    DispatchIndexedEntry0204b988((struct Obj0204b988*)list, 0, 0, 0, 0xffff);
    if (kind != 0) {
        Background_DrawScreen((struct Obj0204b8d0*)list, kind, 0, 0, 0x16, 2, 9, 3, 0xffff);
    }
    Background_UploadMap((struct List0204b0e8*)list, 0);

    void* var5 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x1f8);
    if (var5 && func_ov024_021f6f10(var5) == 1) {
        if (!var5) return 0;
        func_ov023_021fb25c((struct Struct_ov004_0215de9c*)var5, 0, 0, var1, 0x11);
    }
    return 0;
}
