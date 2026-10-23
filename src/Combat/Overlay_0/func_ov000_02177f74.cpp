#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1f00
#define REGION_OFFSET_1 0xa6
#else
#define REGION_OFFSET_0 0x1d00
#define REGION_OFFSET_1 0x6e
#endif

struct Struct_0205c508;
struct Struct_0201099c_3;

void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);
int KeyTable_Get(struct Container020e0310* c, int key);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int GetNthSetBit0218158c(void* obj, int n);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov000_02177f74
extern "C" ARM void func_ov000_02177f74(void* base, char* dst) {
    int first;
    int last;
    ComputeProductSums0205c508((struct UnkStruct0205c508*)((char*)base + 0x1dc), &first, &last);
    signed char start = first;
    signed char end = last;
    struct Container020e0310* c = (struct Container020e0310*)((char*)base + 0xb8);
    int sep = KeyTable_Get(c, 0);
    signed char cursor = *(signed char*)((char*)base + REGION_OFFSET_0 + REGION_OFFSET_1);
    int n = 0;

    if (func_ov000_0217542c(arg0)) {
        func_02041c08(arg1, var6 - var2, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var6 - var2);

    for (signed char i = start; i < end; i++) {
        short bit = GetNthSetBit0218158c(base, i);
        short key = bit + 7;
        int name = KeyTable_Get(c, key);
        AppendNameTag_02041b70(dst, n, (const char*)name);
        if (i != end - 1) {
            AppendString02042058(dst, (const char*)sep);
        }
        var7++;
    }
}
