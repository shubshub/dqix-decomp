#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_02184384 func_ov012_021853f8
#define func_ov012_0218930c func_ov012_02189be8
enum {
    Enum_ov012_021884f4_4976 = 0x1340,
    Enum_ov012_021884f4_4977 = 0x1341,
    Enum_ov012_021884f4_5024 = 0x1368,
    kWindowOffset = 0x90,
    Enum_ov012_021884f4_5096 = 0x1440,
    Enum_ov012_021884f4_5060 = 0x141c,
    Enum_ov012_021884f4_5064 = 0x1420
};
#else
enum {
    Enum_ov012_021884f4_4976 = 0x1370,
    Enum_ov012_021884f4_4977 = 0x1371,
    Enum_ov012_021884f4_5024 = 0x13a0,
    kWindowOffset = 0xac,
    Enum_ov012_021884f4_5096 = 0x13e8,
    Enum_ov012_021884f4_5060 = 0x13c4,
    Enum_ov012_021884f4_5064 = 0x13c8
};
#endif

#include <globaldefs.h>

struct Struct_ov012_021884f4 {
    unsigned short available : 5;
    unsigned short other : 11;
};

extern "C" int func_ov012_02184384(unsigned short* entries, int count);
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021e6e60(void* obj);
extern "C" void func_ov012_0218a438(char* self);
struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" int func_ov023_021e6de4(char* obj);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
struct Struct_ov012_02186a7c;
extern "C" int func_ov023_021e6e20(struct Struct_ov012_02186a7c* obj);
extern "C" void func_ov012_0218930c(void* obj, int a);
extern int g_sePlayer;

// USA: func_ov012_021884f4
extern "C" ARM void func_ov012_021884f4(char* base) {
    unsigned char state = *(unsigned char*)(base + Enum_ov012_021884f4_4976);
    if (state == 0) {
        *(unsigned char*)(base + Enum_ov012_021884f4_5024) = 0;
        *(int*)(base + Enum_ov012_021884f4_5096) = 1;

        unsigned int count = ((Struct_ov012_021884f4*)(base + Enum_ov012_021884f4_5060))->other;
        int ret = func_ov012_02184384(*(unsigned short**)(base + Enum_ov012_021884f4_5064), count);
        if (ret < 0) {
            *(int*)(base + Enum_ov012_021884f4_5096) = 0;
        }

        func_0205de24((struct Struct0205de24*)(base + kWindowOffset), 0, 3);
        func_ov023_021e6e60(base);
        func_ov012_0218a438(base);

        (*(unsigned char*)(base + Enum_ov012_021884f4_4976))++;
        return;
    }
    if (state != 1) return;

    *(unsigned char*)(base + Enum_ov012_021884f4_5024) = 1;
    int sum = Window_GetSelectedIndex((struct Struct_0205c570*)(base + kWindowOffset));
    *(int*)(base + Enum_ov012_021884f4_5096) = sum;

    if (func_ov023_021e6de4(base) != 0) {
        int v = *(int*)(base + Enum_ov012_021884f4_5096);
        int cont = 1;
        switch (v) {
        case 0:
            *(unsigned char*)(base + Enum_ov012_021884f4_4977) = 0xb;
            *(unsigned char*)(base + Enum_ov012_021884f4_4976) = 0;
            break;
        case 1: {
            if (((Struct_ov012_021884f4*)(base + Enum_ov012_021884f4_5060))->other != 0) {
                *(unsigned char*)(base + Enum_ov012_021884f4_4977) = 0xc;
                *(unsigned char*)(base + Enum_ov012_021884f4_4976) = 0;
            } else {
                cont = 0;
            }
            break;
        }
        }

        if (cont != 0) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        }
    } else {
        if (func_ov023_021e6e20((struct Struct_ov012_02186a7c*)base) != 0) {
            func_ov012_0218930c(base, 1);
        }
    }
}
