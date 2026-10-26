#if defined(jpn)
enum { Enum_ov017_021ca81c_1816 = 0x508 };
#else
enum { Enum_ov017_021ca81c_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ca81c_2 {
    char pad0[2];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char unknown_a_4_ : 4;
    char pad1[0x18 - 0xb];
};

struct Struct_ov017_021ca81c_3 {
    unsigned char pad0;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    char pad1[2];
    struct Struct_ov017_021ca81c_2 entries[1];
};

struct Struct_ov017_021ca81c_4 {
    char pad0[0x28];
    short f28;
    short unknown_2a_;
    short unknown_2c_;
    short unknown_2e_;
};

struct Struct_ov017_021ca81c_5 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    short f8;
    short fa;
    short fc;
    short fe;
};

struct Struct_ov017_021ca81c {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021ca81c_5 fields;
};

// USA: func_ov017_021ca81c
extern "C" ARM void func_ov017_021ca81c(struct Struct_ov017_021ca81c_3* sl) {
    GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + Enum_ov017_021ca81c_1816);
    unsigned char* fp = (unsigned char*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    for (int i = 0; i < sl->unknown_1_4_; i++) {
        struct Struct_ov017_021ca81c_2* entry = &sl->entries[i];
        struct Struct_ov017_021ca81c msg;
        for (int j = 0; j < entry->count; j++) {
            unsigned char var7 = entry->ids[j];
            if (var7 >= 8) {
                continue;
            }
            struct Struct_ov017_021ca81c_4* elem = (struct Struct_ov017_021ca81c_4*)(fp + 0x158 + var7 * 0xa4);
            struct Struct_ov017_021ca81c_5* var9 = &msg.fields;
            msg.tag = 0x5e;
            var9->f0 = *(unsigned short*)(fp + 8);
            var9->f2 = (unsigned short)(entry->ids[j] + 0xc0);
            memcpy(&var9->f4, (char*)elem + 0x58, 4);
            var9->f8 = elem->f28;
            var9->fa = elem->unknown_2a_;
            var9->fc = elem->unknown_2c_;
            var9->fe = elem->unknown_2e_;
            func_0205e330(data, &msg, 0);
        }
    }
}
