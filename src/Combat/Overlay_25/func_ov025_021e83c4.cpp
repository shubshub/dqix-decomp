#if defined(jpn)
enum { Enum_ov025_021e83c4_336 = 0x144, Enum_ov025_021e83c4_12 = 0x4 };
#else
enum { Enum_ov025_021e83c4_336 = 0x150, Enum_ov025_021e83c4_12 = 0xc };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" int func_ov025_021e24d0(char* s, char* out2, char* out1);

struct Struct_ov025_021e4aac;
struct Struct_ov001_0215e1cc;
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_ov025_021e267c(int combatantId, int arg1, int arg2, int flag);
struct Struct_ov025_021e27c8;
extern "C" void func_ov025_021eb084(struct Struct_ov025_021e27c8* obj, int val);

struct Struct_ov025_021ef988_37 { char pad[Enum_ov025_021e83c4_12]; void* target; };
extern struct Struct_ov025_021ef988_37 data_ov025_021ef988;
extern char data_ov025_021ef87f;

struct Struct_ov025_021e83c4_2 {
    char pad[8];
    unsigned char field8;
};

struct Struct_ov025_021e83c4_3 { char pad[0x10]; void* unknown_10_; };

struct Struct_ov025_021e83c4 { char pad[0x49c]; unsigned char flag : 1; };

// USA: func_ov025_021e83c4
extern "C" ARM int func_ov025_021e83c4(struct Struct_ov025_021e83c4_2* p, struct Struct_ov025_021e83c4_3* ctx, int arg2, void* arg3) {
    GameState* bs = GameState::GetInstance();
    int handle = (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54((char*)data_ov025_021ef988.target);

    int cid = *(unsigned short*)((char*)ctx->unknown_10_ + 0x20);
    GameObject* c = func_0200ff1c(bs, cid);
    struct Struct_ov025_021e83c4* c2 = *(struct Struct_ov025_021e83c4**)((char*)c + Enum_ov025_021e83c4_336);
    char ch = 'm';
    if (c2->flag == 1) {
        ch = 'w';
    }

    char buf[0x50];
    sprintf(buf, &data_ov025_021ef87f, ch);

    char name1[0x50];
    char name2[0x50];
    int out1 = 0;
    int out2;
    int id;
    if (func_ov025_021e24d0(buf, name1, name2)) {
        id = ((BackgroundLoader*)((struct Struct_ov025_021e4aac*)handle))->GetLoadedFileInArchive((const char*)(name1), (const char*)(name2), (void**)(&out1), (unsigned int*)(&out2));
    } else {
        id = ((BackgroundLoader*)((struct Struct_ov001_0215e1cc*)handle))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    }

    if (out1 != 0) {
        int ids[8];
        int count = func_ov000_021820bc(arg3, (int)ctx, p->field8, (int)&ids[0]);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                func_ov025_021e267c(ids[i], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    func_ov025_021eb084((struct Struct_ov025_021e27c8*)data_ov025_021ef988.target, id);
    return 1;
}
