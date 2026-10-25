#include <globaldefs.h>

void* CopyStaticData02174da4(int unused, void* dest);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int Text_Append(char* dst, const char* src);
int Text_AppendNTag(char* dst, int n, const char* name);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int StandardStrings_Get(int value);

extern short data_ov000_021834c4[4];

#if defined(jpn)
struct Struct_ov000_021845c6 { char unknown_0_[4][9]; };
extern const Struct_ov000_021845c6 data_ov000_021845c6;
#endif

// USA: func_ov000_0217737c
extern "C" ARM void func_ov000_0217737c(void* arg0, char* arg1) {
    char* var0 = (char*)arg0;
    if (arg1 == 0) {
        return;
    }
    int var1[4];
    func_ov000_02174da4((int)var0, var1);
#if defined(jpn)
    int var4 = 0;
    Struct_ov000_021845c6 var2(data_ov000_021845c6);
    signed char var3 = *(signed char*)(var0 + 0x1fa1);
#else
    signed char var3 = *(signed char*)(var0 + 0x1d69);
#endif
#if !defined(jpn)
    int var4 = 0;
#endif
    if (IsField0x118Equal2_ov000_0217542c(obj)) {
        Text_AppendFrameTag(dst, cursorId, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursorId);
    int keyArg = 0;
    for (int i = 0; i < 4; i++) {
        int v = localArr[i];
        if (v < 0) {
            continue;
        }
        if (nameIdx != 0) {
            int f = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), keyArg);
            Text_Append(dst, (const char*)f);
        }
#if defined(jpn)
        char* var9 = var2.unknown_0_[var7];
#else
        int r = StandardStrings_Get(data_ov000_021834c4[v]);
#endif
        Text_AppendNTag(dst, nameIdx, (const char*)r);
        nameIdx++;
    }
}
