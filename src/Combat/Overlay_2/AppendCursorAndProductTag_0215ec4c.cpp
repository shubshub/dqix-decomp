#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_0215ece4 func_ov002_0215fe54
#endif

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);

extern "C" void func_ov002_0215ece4(void* base, char* dst, int c, int productB, int clampedSum);

// USA: func_ov002_0215ec4c  (semantic: AppendCursorAndProductTag_0215ec4c)
extern "C" ARM void func_ov002_0215ec4c(void* base, char* dst, int flag) {
    int productB;
    int clampedSum;
    if (dst == 0) {
        return;
    }
    int cursor = *(short*)((char*)base + RG(0x1bfa, 0x1ac2)) % 8;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    void* mid = (void*)((char*)base + RG(0x2c8 + 0xc00, 0xe20));
    ComputeProductSums0205c508((struct UnkStruct0205c508*)((unsigned char*)mid + 0x54), &productB, &clampedSum);
    int c = *(signed char*)((char*)base + RG(0x1c20, 0x1ae8));
    func_ov002_0215ece4(base, dst, c, productB, clampedSum);
}
