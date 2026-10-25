#include <globaldefs.h>

extern "C" int Font_GetTextWidth(void* p, int flag);
int AppendXYTag_02041a90(char* dst, int x, int y);
int Text_Append(char* dst, const char* src);
int Text_AppendSdrcTag(char* dst, int a, int b, int c, int d, int e);

#if defined(jpn)
extern "C" void __clear(void*, int);
extern "C" void func_02041f50(const char*, char*);
int STD_GetStringLength(const char*);
#endif

// USA: func_ov023_021ed254
extern "C" ARM void func_ov023_021ed254(char* arg0, char* arg1) {
    if (arg1 == 0) return;

    unsigned char var0 = *(unsigned char*)(arg0 + 0x28);
    char* var1 = *(char**)(arg0 + 0x20);
#if defined(jpn)
    char* entry = base + idx * 0x15c;
    char converted[0x80];
    __clear(converted, 0x80);
    func_02041f50(entry + 0xc, converted);
    int len = STD_GetStringLength(converted);
    int half = (0x80 - (len / 2) * 12) / 2;
    int y = 6;
    if (len != STD_GetStringLength(entry + 0xc)) y = 8;
    AppendXYTag_02041a90(buf, half, y);
    Text_Append(buf, entry + 0xc);
#else
    char* entry = base + idx * 0x244 + 0xc;
    int val = Font_GetTextWidth(entry, 1);
    int diff = 0xa0 - val;
    int half = diff / 2;
    if (half < 0) half = 0;
    AppendXYTag_02041a90(buf, half, 6);

    if (entry != 0) {
        Text_Append(buf, entry);
    }

    #endif

    if (!(*(unsigned short*)(arg0 + 0x438) & 0x2)) {
        short var11 = *(short*)(arg0 + 0x448);
#if defined(jpn)
        short var12 = var11 - 0x1c;
        short var13 = 0x80 - var12;
#else
        short var12 = var11 - 0xc;
        short var13 = 0xa0 - var12;
#endif
        if (a > 0 && b > 0) {
            Text_AppendSdrcTag(buf, 1, a, 1, b, 0x16);
        } else if (a <= 0) {
#if defined(jpn)
            Text_AppendSdrcTag(buf, 1, 1, 1, 0x7e, 0x16);
#else
            Text_AppendSdrcTag(buf, 1, 1, 1, 0x9e, 0x16);
#endif
        }
    }
    *(unsigned short*)(arg0 + 0x438) &= ~0x2;
}
