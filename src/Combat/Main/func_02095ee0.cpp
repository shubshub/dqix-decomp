#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct Struct_020534ac;

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_02109404_8 {
    char pad0;
    unsigned char f1;
    unsigned char f2;
    char pad3[3];
    unsigned short unknown_6_;
};
extern struct Struct_02109404_8 data_02109404;
extern char data_020f13fc[];

struct Struct_02095ee0 {
    char pad0[0xa8];
    int unknown_a8_;
    char unknown_ac_[0x4c4 - 0xac];
    int unknown_4c4_;
};

// USA: func_02095ee0
extern "C" ARM int func_02095ee0(struct Struct_02095ee0* ctx) {
    char local[0x430];
    int id = (int)BackgroundLoader::GetInstance();
    int out1, out2;
    int i;

    if (ctx->unknown_4c4_ < 0) {
        return -1;
    }

    if (((BackgroundLoader*)(id))->GetTaskStatus((int)(ctx->unknown_4c4_)) != 0) {
        ((BackgroundLoader*)((struct Struct_020534ac*)id))->GetLoadedFileByID((int)(ctx->unknown_4c4_), (void**)(&out1), (unsigned int*)(&out2));

        data_02109404.unknown_6_ = 0;
        data_02109404.f1 = 0;

        if (ctx->unknown_a8_ == 0) {
            ((BackgroundLoader*)(id))->RemoveTask((int)(ctx->unknown_4c4_));
            ctx->unknown_4c4_ = -1;
            return 2;
        }

        ((Script*)((struct ResetStruct*)local))->Initialize();
        ((Script*)local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f13fc);
        ((Script*)((struct StreamState*)local))->Load((struct StreamHeader*)out1, out2);
        ((Script*)((struct Struct_0201f040_3*)local))->Execute();
        ((BackgroundLoader*)(id))->RemoveTask((int)(ctx->unknown_4c4_));
        ctx->unknown_4c4_ = -1;

        for (i = 0; i < data_02109404.unknown_6_; i++) {}
        return 1;
    }

    return (((BackgroundLoader*)(id))->GetTaskStatus((int)(ctx->unknown_4c4_)) == -1) ? 2 : 0;
}
