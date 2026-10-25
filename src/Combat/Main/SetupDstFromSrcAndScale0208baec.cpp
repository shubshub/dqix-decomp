#include <globaldefs.h>

void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);
extern "C" int SpriteContext_DrawSprite(int a, void* dst);

struct SrcStruct0208baec {
    int x0;
    int x1;
    unsigned char pad8[0xc - 0x8];
    unsigned short f0xc;
};

struct DstStruct0208baec {
    unsigned char pad0[0xc];
    int fc;
    int f10;
    int f14;
    int f18;
    unsigned short f1c;
    unsigned short pad1e;
    unsigned short f20;
    unsigned char f22;
};

// USA: func_0208baec
ARM int SetupDstFromSrcAndScale0208baec(int a, DstStruct0208baec* dst, SrcStruct0208baec* src, int byteArg,
                                         float scaleArg, int pivot, unsigned char cArg) {
    dst->f22 = (unsigned char)byteArg;
    SetBitfieldStoreBytes0205af38(a, (char*)dst, 1, 1);
    dst->f20 = cArg;
    int x0 = src->x0, x1 = src->x1;
    int dx = x0 - pivot;
    int dy = x1 - pivot;
    dst->f14 = dx << 12;
    dst->f18 = dy << 12;
    dst->fc = (int)(scaleArg * 4096.0f);
    dst->f10 = (int)(scaleArg * 4096.0f);
    dst->f1c = src->f0xc;
    return SpriteContext_DrawSprite(a, dst);
}
