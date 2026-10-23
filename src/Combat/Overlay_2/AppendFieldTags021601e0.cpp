#include <globaldefs.h>

struct Container020e0310;

int AppendXTag_02041a28(char* dst, int x);
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendDotLeaderLabel02042084(char* buffer, char* label, int width, int extra);
#if defined(jpn)
#define AppendLineTag02041cc0 func_0204234c
extern "C" int func_0204234c(char* dst, int a1);
int AppendString02042058(char* dst, const char* src);
#else
int AppendLineTag02041cc0(char* dst, int a1);
#endif
int AppendXYTag_02041a90(char* dst, int x, int y);

// USA: func_ov002_021601e0
#if defined(jpn)
ARM void AppendFieldTags021601e0(char* obj, char* dst, int) {
    struct Container020e0310* c;
    int field;

    if (dst == NULL) return;

    c = (struct Container020e0310*)(obj + 0x8);
    field = KeyTable_Get(c, 0x1130);
    AppendString02042058(dst, (const char*)field);

    AppendLineTag02041cc0(dst, 0x10);
    AppendXYTag_02041a90(dst, 0, 0x3a);

    field = KeyTable_Get(c, (short)(*(short*)(obj + 0x1a00 + 0xce) + 0x31 + 0x1100));
    AppendDotLeaderLabel02042084(dst, (char*)field, 0x48, 0xa);
}
#else
ARM void AppendFieldTags021601e0(char* obj, char* dst, int) {
    struct Container020e0310* c;
    int field;

    if (dst == NULL) return;

    AppendXTag_02041a28(dst, 0);

    c = (struct Container020e0310*)(obj + 0x20);
    field = KeyTable_Get(c, 0x1130);
    AppendDotLeaderLabel02042084(dst, (char*)field, 0x48, 0);

    AppendLineTag02041cc0(dst, 0x10);
    AppendXYTag_02041a90(dst, 0, 0x3a);

    field = KeyTable_Get(c, (short)(*(short*)(obj + 0x1c00 + 0x6) + 0x31 + 0x1100));
    AppendDotLeaderLabel02042084(dst, (char*)field, 0x48, 0);
}
#endif
