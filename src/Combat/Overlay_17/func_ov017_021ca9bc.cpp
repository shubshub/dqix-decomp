#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov017_021ca9bc_1816 = 0x508 };
#else
enum { Enum_ov017_021ca9bc_1816 = 0x718 };
#endif

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ca9bc_5 {
    char pad0[2];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char unknown_a_4_ : 4;
    char pad1[0x18 - 0xb];
};

struct Struct_ov017_021ca9bc_6 {
    unsigned char pad0;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    char pad1[2];
    struct Struct_ov017_021ca9bc_5 entries[1];
};

struct Struct_ov017_021ca9bc_7 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char nibble : 4;
};

struct Struct_ov017_021ca9bc_8 {
    bool bit0 : 1;
    bool unknown_0_1_ : 1;
    bool bit2 : 1;
    bool unknown_0_3_ : 1;
    bool unknown_0_4_ : 1;
    bool unknown_0_5_ : 1;
    bool unknown_0_6_ : 1;
};

struct Struct_ov017_021ca9bc {
    char pad0[0xc];
    unsigned short fc;
    char pad1[0x30 - 0xe];
    unsigned short unknown_30_;
    short unknown_32_;
    short f34;
    char pad2[0x38 - 0x36];
    unsigned char unknown_38_;
    char pad3;
    char pad4;
    struct Struct_ov017_021ca9bc_7 unknown_3b_;
    struct Struct_ov017_021ca9bc_8 unknown_3c_;
    unsigned char unknown_3d_;
    char pad5[0xa4 - 0x3e];
};

struct Struct_ov017_021ca9bc_2 {
    unsigned short f0;
    unsigned short f2;
    short f4;
    short unknown_6_;
    unsigned short f8;
    unsigned short fa;
    unsigned char fc;
    struct Struct_ov017_021ca9bc_7 bits;
    unsigned char fe;
    struct Struct_ov017_021ca9bc_8 unknown_f_;
};

struct Struct_ov017_021ca9bc_3 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021ca9bc_2 fields;
};

struct Struct_ov017_021ca9bc_4 {
    char pad0[8];
    unsigned short f8;
    char pad1[0x158 - 0xa];
    struct Struct_ov017_021ca9bc elems[8];
};

// USA: func_ov017_021ca9bc
extern "C" ARM void func_ov017_021ca9bc(struct Struct_ov017_021ca9bc_6* sl) {
    GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)GetGameResources() + 0x3000 + Enum_ov017_021ca9bc_1816);
    struct Struct_ov017_021ca9bc_4* obj = (struct Struct_ov017_021ca9bc_4*)func_ov017_021b8478(table);
    void* data = LinkMessageQueue_GetInstance();

    for (int i = 0; i < sl->unknown_1_4_; i++) {
        struct Struct_ov017_021ca9bc_5* entry = &sl->entries[i];
        struct Struct_ov017_021ca9bc_3 msg;
        for (int j = 0; j < entry->count; j++) {
            unsigned char var7 = entry->ids[j];
            if (var7 >= 8) {
                continue;
            }
            struct Struct_ov017_021ca9bc* elem = &obj->elems[var7];
            struct Struct_ov017_021ca9bc_2* var9 = &msg.fields;
            msg.tag = 0x5f;
            var9->f0 = obj->f8;
            var9->f2 = (unsigned short)(entry->ids[j] + 0xc0);
            var9->f4 = elem->unknown_32_;
            var9->unknown_6_ = elem->f34;
            var9->f8 = elem->fc;
            var9->fa = elem->unknown_30_;
            var9->fc = elem->unknown_38_;
            var9->bits.bit0 = elem->unknown_3b_.bit0 & 0xff;
            var9->bits.unknown_0_1_ = elem->unknown_3b_.unknown_0_1_ & 0xff;
            var9->bits.bit2 = elem->unknown_3b_.bit2 & 0xff;
            var9->bits.unknown_0_3_ = elem->unknown_3b_.unknown_0_3_ & 0xff;
            var9->bits.nibble = elem->unknown_3b_.nibble & 0xff;
            var9->unknown_f_.bit0 = elem->unknown_3c_.bit0 != 0;
            var9->unknown_f_.unknown_0_1_ = elem->unknown_3c_.unknown_0_1_ != 0;
            var9->unknown_f_.bit2 = elem->unknown_3c_.bit2 != 0;
            var9->unknown_f_.unknown_0_3_ = elem->unknown_3c_.unknown_0_3_ != 0;
            var9->unknown_f_.unknown_0_4_ = elem->unknown_3c_.unknown_0_4_ != 0;
            var9->unknown_f_.unknown_0_5_ = elem->unknown_3c_.unknown_0_5_ != 0;
            var9->unknown_f_.unknown_0_6_ = elem->unknown_3c_.unknown_0_6_ != 0;
            var9->fe = elem->unknown_3d_;
            func_0205e330(data, &msg, 0);
        }
    }
}
