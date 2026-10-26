#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_020a1180 {
    unsigned int f0 : 9;
    unsigned int f1 : 9;
    unsigned int f2 : 9;
    unsigned int f3 : 3;
    unsigned int f4 : 2;
    int next;
    int prev;
};
extern "C" void func_020a1380(struct Struct_020a1180* rec);

extern "C" int STD_GetStringLength(const char* s);

struct Struct_020a1180_2;
struct Struct_020a1568;
extern "C" void func_020a1568(struct Struct_020a1568* arr, struct Struct_020a1180_2* src);

unsigned char data_02109d94;
unsigned short data_02109d96;
struct Struct_020a1568* data_02109d98;
SafeAllocator* data_02109d9c;
short* data_02109da0;

extern const char data_020f1914[];

// USA: func_020a1180
extern "C" ARM int func_020a1180(Script::Parameter* params, int numParams) {
    struct Struct_020a1180 rec;
    func_020a1380(&rec);
    func_020a1380(&rec);

    rec.f0 = params[0].ToInt();

    if (data_02109da0 != 0 && data_02109d96 != 0) {
        bool found = false;
        for (int i = 0; i < data_02109d96; i++) {
            if (rec.f0 == data_02109da0[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return 1;
        }
    }

    rec.f1 = params[1].ToInt();
    rec.f2 = params[2].ToInt();
    rec.f3 = params[3].ToInt();

    if (!(data_02109d94 & 1)) {
        if (rec.f3 == 0 || rec.f3 == 1) return 1;
    }
    if (!(data_02109d94 & 2)) {
        if (rec.f3 == 2) return 1;
    }
    if (!(data_02109d94 & 4)) {
        if (rec.f3 == 7) return 1;
    }
    if (!(data_02109d94 & 8)) {
        if (rec.f3 == 3 || rec.f3 == 4 || rec.f3 == 5 || rec.f3 == 6) return 1;
    }

    rec.f4 = params[4].ToInt();

    const char* src = params[5].ToString();
    int len = STD_GetStringLength(src);
    rec.next = (int)data_02109d9c->Allocate(len + 1);
    sprintf((char*)rec.next, data_020f1914, src);
    ((char*)rec.next)[len] = 0;
    func_020a1568(data_02109d98, (struct Struct_020a1180_2*)&rec);

    return 1;
}
