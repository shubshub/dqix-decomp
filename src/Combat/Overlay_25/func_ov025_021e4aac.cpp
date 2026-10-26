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

extern int data_ov025_021ef988;
extern char data_ov025_021eefa0[];

struct Struct_ov025_021e4aac_2 {
    char pad[8];
    unsigned char field8;
    char pad2[3];
    char* unknown_c_;
};

#if defined(jpn)
enum { Enum_ov025_021e4aac_12 = 0x4 };
#else
enum { Enum_ov025_021e4aac_12 = 0xc };
#endif

// USA: func_ov025_021e4aac
extern "C" ARM int func_ov025_021e4aac(struct Struct_ov025_021e4aac_2* p, int unused, int arg2, void* arg3) {
    GameState::GetInstance();
    int handle = (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54(*(char**)((char*)&data_ov025_021ef988 + Enum_ov025_021e4aac_12));

    char buf[0x50];
    int n = 0x50;
    unsigned char* d = (unsigned char*)buf;
    unsigned char* s = (unsigned char*)data_ov025_021eefa0;
    do {
        *d = *s;
        d++;
        s++;
    } while (--n);
    strcat(buf, p->unknown_c_);

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
        int count = func_ov000_021820bc(arg3, unused, p->field8, (int)&ids[0]);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                func_ov025_021e267c(ids[i], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    func_ov025_021eb084((struct Struct_ov025_021e27c8*)(*(char**)((char*)&data_ov025_021ef988 + Enum_ov025_021e4aac_12)), id);
    return 1;
}
