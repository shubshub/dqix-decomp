#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_020a1180 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 9;
    unsigned int unknown_2_2_ : 9;
    unsigned int unknown_3_3_ : 3;
    unsigned int unknown_3_6_ : 2;
    int unknown_4_;
    int unknown_8_;
};
extern "C" void func_020a1380(struct Struct_020a1180* arg0);

int STD_GetStringLength(const char* s);

struct Struct_020a1180_2;
struct Struct_020a1568;
extern "C" void func_020a1568(struct Struct_020a1568* arg0, struct Struct_020a1180_2* arg1);

unsigned char data_02109d94;
unsigned short data_02109d96;
struct Struct_020a1568* data_02109d98;
SafeAllocator* data_02109d9c;
short* data_02109da0;

extern const char data_020f1914[];

// USA: func_020a1180
extern "C" ARM int func_020a1180(Script::Parameter* arg0, int arg1) {
    struct Struct_020a1180 var0;
    func_020a1380(&var0);
    func_020a1380(&var0);

    var0.unknown_0_0_ = arg0[0].ToInt();

    if (data_02109da0 != 0 && data_02109d96 != 0) {
        bool var1 = false;
        for (int var2 = 0; var2 < data_02109d96; var2++) {
            if (var0.unknown_0_0_ == data_02109da0[var2]) {
                var1 = true;
                break;
            }
        }
        if (!var1) {
            return 1;
        }
    }

    var0.unknown_1_1_ = arg0[1].ToInt();
    var0.unknown_2_2_ = arg0[2].ToInt();
    var0.unknown_3_3_ = arg0[3].ToInt();

    if (!(data_02109d94 & 1)) {
        if (var0.unknown_3_3_ == 0 || var0.unknown_3_3_ == 1) return 1;
    }
    if (!(data_02109d94 & 2)) {
        if (var0.unknown_3_3_ == 2) return 1;
    }
    if (!(data_02109d94 & 4)) {
        if (var0.unknown_3_3_ == 7) return 1;
    }
    if (!(data_02109d94 & 8)) {
        if (var0.unknown_3_3_ == 3 || var0.unknown_3_3_ == 4 || var0.unknown_3_3_ == 5 || var0.unknown_3_3_ == 6) return 1;
    }

    var0.unknown_3_6_ = arg0[4].ToInt();

    const char* src = params[5].ToString();
    int len = STD_GetStringLength(src);
    rec.next = (int)data_02109d9c->Allocate(len + 1);
    sprintf((char*)rec.next, data_020f1914, src);
    ((char*)rec.next)[len] = 0;
    AppendElement020a1568(data_02109d98, (struct Elem020a1568*)&rec);

    return 1;
}
