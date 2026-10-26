#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"

struct Struct0200fb08;
extern "C" int GameState_GetLanguage(Struct0200fb08*);
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
    const char* suffix;
    Foo02048004* sprite;
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

extern "C" ARM void func_ov000_0218214c(Foo02048004* arg0, SafeAllocator* allocator, const void* narc) {
#if defined(jpn)
    char buf[0x28];
    Struct_ov000_0218214c bindings[13] = {
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
    bindings[0].sprite->word0 = 0x3e;
    bindings[1].sprite->word0 = 0x3e;
    bindings[2].sprite->word0 = 0x3e;
#else
    char buf[0x28];
    Struct_ov000_0218214c bindings[13];
    int i;
    int j;
    int var9;
    int mode = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
    int count;

    var9 = 2;
    bindings[0].suffix = data_ov000_02184184;
    bindings[1].suffix = data_ov000_02184186;
    bindings[2].suffix = data_ov000_02184188;
    bindings[3].suffix = data_ov000_0218418a;
    bindings[4].suffix = data_ov000_02184190;
    if (mode == 1) {
        bindings[5].suffix = data_ov000_02184193;
        bindings[6].suffix = data_ov000_02184197;
    } else {
        bindings[5].suffix = data_ov000_0218419b;
        bindings[6].suffix = data_ov000_021841a0;
    }
    bindings[7].suffix = data_ov000_021841a5;

    if (mode == 1) {
        bindings[8].suffix = data_ov000_021841a8;
        bindings[9].suffix = data_ov000_021841ae;
        bindings[10].suffix = data_ov000_021841b3;
    } else if (mode == 2) {
        bindings[8].suffix = data_ov000_021841b8;
        bindings[9].suffix = data_ov000_021841c1;
        bindings[10].suffix = data_ov000_021841c6;
    } else if (mode == 3) {
        bindings[8].suffix = data_ov000_021841cb;
        bindings[9].suffix = data_ov000_021841d4;
        bindings[10].suffix = data_ov000_021841d9;
    } else if (mode == 4) {
        bindings[8].suffix = data_ov000_021841de;
        bindings[9].suffix = data_ov000_021841e7;
        bindings[10].suffix = data_ov000_021841ec;
    } else if (mode == 5) {
        bindings[8].suffix = data_ov000_021841f1;
        bindings[9].suffix = data_ov000_021841fa;
        bindings[10].suffix = data_ov000_021841ff;
        bindings[11].suffix = data_ov000_02184204;
        bindings[12].suffix = data_ov000_02184209;
        var9 = 0;
    }
    count = 13 - var9;

    for (i = 0; i < count; i++) {
        bindings[i].sprite = &arg0[i];
    }

    for (j = 0; j < count; j++) {
        sprintf(buf, data_ov000_0218420e, bindings[j].suffix);
        unsigned int fileSize = 0;
        const void* fileData = 0;
        GetFileInNarc(narc, buf, &fileData, &fileSize, 0);
        SprSprite_Parse(bindings[j].sprite, fileData, allocator);
    }

    bindings[0].sprite->word0 = 0x3e;
    bindings[1].sprite->word0 = 0x3e;
    bindings[2].sprite->word0 = 0x3e;
#endif
}
