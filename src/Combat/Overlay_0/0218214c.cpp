#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"

struct Struct0200fb08;
int GameState_GetLanguage(Struct0200fb08*);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void SprSprite_Parse(Foo02048004* sprite, const void* file, SafeAllocator* allocator);

extern const char data_ov000_02184184[];
extern const char data_ov000_02184186[];
extern const char data_ov000_02184188[];
extern const char data_ov000_0218418a[];
extern const char data_ov000_02184190[];
extern const char data_ov000_02184193[];
extern const char data_ov000_02184197[];
extern const char data_ov000_0218419b[];
extern const char data_ov000_021841a0[];
extern const char data_ov000_021841a5[];
extern const char data_ov000_021841a8[];
extern const char data_ov000_021841ae[];
extern const char data_ov000_021841b3[];
extern const char data_ov000_021841b8[];
extern const char data_ov000_021841c1[];
extern const char data_ov000_021841c6[];
extern const char data_ov000_021841cb[];
extern const char data_ov000_021841d4[];
extern const char data_ov000_021841d9[];
extern const char data_ov000_021841de[];
extern const char data_ov000_021841e7[];
extern const char data_ov000_021841ec[];
extern const char data_ov000_021841f1[];
extern const char data_ov000_021841fa[];
extern const char data_ov000_021841ff[];
extern const char data_ov000_02184204[];
extern const char data_ov000_02184209[];
extern const char data_ov000_0218420e[];

struct Struct_ov000_0218214c {
    const char* unknown_0_;
    Struct_02012fa4* unknown_4_;
};

#if defined(jpn)
extern const char data_ov000_021852d2[];
extern const char data_ov000_021852d0[];
extern const char data_ov000_021852d4[];
extern const char data_ov000_021852e5[];
extern const char data_ov000_021852d9[];
extern const char data_ov000_021852d6[];
extern const char data_ov000_021852df[];
extern const char data_ov000_021852f0[];
extern const char data_ov000_021852f6[];
extern const char data_ov000_021852dc[];
extern const char data_ov000_021852e8[];
extern const char data_ov000_021852ec[];
extern const char data_ov000_021852e2[];
extern const char data_ov000_021852fc[];
#endif

// USA: func_ov000_0218214c

extern "C" ARM void func_ov000_0218214c(Struct_02012fa4* arg0, SafeAllocator* arg1, const void* arg2) {
#if defined(jpn)
    char var0[0x28];
    Struct_ov000_0218214c var1[13] = {
        {data_ov000_021852d2, &arg0[0]},
        {data_ov000_021852d0, &arg0[1]},
        {data_ov000_021852d4, &arg0[2]},
        {data_ov000_021852e5, &arg0[3]},
        {data_ov000_021852d9, &arg0[4]},
        {data_ov000_021852d6, &arg0[5]},
        {data_ov000_021852df, &arg0[6]},
        {data_ov000_021852f0, &arg0[7]},
        {data_ov000_021852f6, &arg0[8]},
        {data_ov000_021852dc, &arg0[9]},
        {data_ov000_021852e8, &arg0[10]},
        {data_ov000_021852ec, &arg0[11]},
        {data_ov000_021852e2, &arg0[12]}
    };
    for (int j = 0; j < 13; ++j) {
        sprintf(buf, data_ov000_021852fc, bindings[j].suffix);
        unsigned int fileSize = 0;
        const void* fileData = 0;
        GetFileInNarc(narc, buf, &fileData, &fileSize, 0);
        SprSprite_Parse(bindings[j].sprite, fileData, allocator);
    }
    var1[0].unknown_4_->unknown_0_ = 0x3e;
    var1[1].unknown_4_->unknown_0_ = 0x3e;
    var1[2].unknown_4_->unknown_0_ = 0x3e;
#else
    char buf[0x28];
    ComboSpriteBinding bindings[13];
    int i;
    int j;
    int skip;
    int mode = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
    int count;

    var9 = 2;
    var6[0].unknown_0_ = data_ov000_02184184;
    var6[1].unknown_0_ = data_ov000_02184186;
    var6[2].unknown_0_ = data_ov000_02184188;
    var6[3].unknown_0_ = data_ov000_0218418a;
    var6[4].unknown_0_ = data_ov000_02184190;
    if (var10 == 1) {
        var6[5].unknown_0_ = data_ov000_02184193;
        var6[6].unknown_0_ = data_ov000_02184197;
    } else {
        var6[5].unknown_0_ = data_ov000_0218419b;
        var6[6].unknown_0_ = data_ov000_021841a0;
    }
    var6[7].unknown_0_ = data_ov000_021841a5;

    if (var10 == 1) {
        var6[8].unknown_0_ = data_ov000_021841a8;
        var6[9].unknown_0_ = data_ov000_021841ae;
        var6[10].unknown_0_ = data_ov000_021841b3;
    } else if (var10 == 2) {
        var6[8].unknown_0_ = data_ov000_021841b8;
        var6[9].unknown_0_ = data_ov000_021841c1;
        var6[10].unknown_0_ = data_ov000_021841c6;
    } else if (var10 == 3) {
        var6[8].unknown_0_ = data_ov000_021841cb;
        var6[9].unknown_0_ = data_ov000_021841d4;
        var6[10].unknown_0_ = data_ov000_021841d9;
    } else if (var10 == 4) {
        var6[8].unknown_0_ = data_ov000_021841de;
        var6[9].unknown_0_ = data_ov000_021841e7;
        var6[10].unknown_0_ = data_ov000_021841ec;
    } else if (var10 == 5) {
        var6[8].unknown_0_ = data_ov000_021841f1;
        var6[9].unknown_0_ = data_ov000_021841fa;
        var6[10].unknown_0_ = data_ov000_021841ff;
        var6[11].unknown_0_ = data_ov000_02184204;
        var6[12].unknown_0_ = data_ov000_02184209;
        var9 = 0;
    }
    var11 = 13 - var9;

    for (var7 = 0; var7 < var11; var7++) {
        var6[var7].unknown_4_ = &arg0[var7];
    }

    for (j = 0; j < count; j++) {
        sprintf(buf, data_ov000_0218420e, bindings[j].suffix);
        unsigned int fileSize = 0;
        const void* fileData = 0;
        GetFileInNarc(narc, buf, &fileData, &fileSize, 0);
        SprSprite_Parse(bindings[j].sprite, fileData, allocator);
    }

    var6[0].unknown_4_->unknown_0_ = 0x3e;
    var6[1].unknown_4_->unknown_0_ = 0x3e;
    var6[2].unknown_4_->unknown_0_ = 0x3e;
#endif
}
