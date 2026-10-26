#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/Cache.h"

struct CharacterColors {
    unsigned short unknown_0_[10][2];
    unsigned short unknown_28_[8][2];
    unsigned short unknown_48_[8][4];
    unsigned short unknown_88_[8][8];
    unsigned short unknown_108_[8][2];
    unsigned short edge_;
};

extern unsigned short data_02109928[10][2] __attribute__((aligned(4)));

// USA: func_02099d34
extern "C" ARM void func_02099d34(Model3D* m, int a, unsigned int b, int c) {
    NSBXXTex* tex;
    unsigned char* entry;
    int count;
    int len;
    CharacterColors* colors;
    unsigned char* p;
    int rem;

    if (b > 8) {
        return;
    }
    if (m == NULL) {
        return;
    }
    tex = m->GetTEX0();
    if (tex == NULL) {
        return;
    }

    entry = NULL;
    count = 0;
    colors = (CharacterColors*)data_02109928;

    switch (a) {
    case 1:
        entry = (unsigned char*)&colors->unknown_28_[b];
        count = 2;
        break;
    case 2:
        entry = (unsigned char*)&colors->unknown_48_[b];
        count = 4;
        break;
    case 4:
        entry = (unsigned char*)&colors->unknown_88_[b];
        count = 8;
        break;
    }
len = count * 2;
    p = (unsigned char*)tex + tex->block4Offset_;
    rem = tex->block4NumEightBytes_ << 3;
    if ((unsigned int)rem > 0x20) {
        int t = rem & 0x1f;
        p += t;
        rem -= t;
    }

    while (rem > 0) {
        memcpy(p + c, entry, len);
        rem -= 0x20;
    }

    unsigned int off = tex->block4Offset_;
    unsigned int size = tex->block4NumEightBytes_ << 3;
    CleanInvalidateCacheRange((const void*)((unsigned char*)tex + off), size);
    StageTexFilePaletteData(tex, true);
}