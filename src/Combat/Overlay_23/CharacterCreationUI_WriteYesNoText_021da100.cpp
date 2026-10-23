#if defined(jpn)
enum {Enum_ov023_021da100_3460=0xd48, Enum_ov023_021da100_48=0x38, Enum_ov023_021da100_224=0xc0};
#else
enum {Enum_ov023_021da100_3460=0xd84, Enum_ov023_021da100_48=0x30, Enum_ov023_021da100_224=0xe0};
#endif
#include <globaldefs.h>

struct Container020e0310;
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendSourceRectTag_02041bac(char* dst, int a, int b, int c, int d, int e);
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);

// Overlay 23, originally func_ov023_021da100 (USA/EUR 0x021da100, JPN 0x021da8cc)
extern "C" ARM void CharacterCreationUI_WriteYesNoText(char* obj, char* dst, int flag) {
    if (dst == NULL) return;

    signed char var0 = *(signed char*)(arg0 + Enum_ov023_021da100_3460);
    if (arg2) {
        func_02041c08(arg1, var0, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var0);

    func_02041bac(arg1, 0, 0, 0, Enum_ov023_021da100_48, 0x28);

    struct Container020e0310* c = (struct Container020e0310*)(obj + regionalOffset2);
    for (int i = 0; i < 2; i++) {
        int name = KeyTable_Get(c, (short)(i + 0x465a));
        AppendNameTag_02041b70(dst, i, (const char*)name);
        if (i != 1) {
            int sep = KeyTable_Get(c, 0x4273);
            AppendString02042058(dst, (const char*)sep);
        }
    }
}
