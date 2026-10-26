#include <globaldefs.h>

extern "C" void* func_ov000_02174da4(int unused, void* dest);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int StandardStrings_Get(int value);

extern short data_ov000_021834c4[4];

#if defined(jpn)
struct Struct_ov000_021845c6 { char names[4][9]; };
extern const Struct_ov000_021845c6 data_ov000_021845c6;
#endif

// USA: func_ov000_0217737c
extern "C" ARM void func_ov000_0217737c(void* objRaw, char* dst) {
    char* obj = (char*)objRaw;
    if (dst == 0) {
        return;
    }
    int var1[4];
    func_ov000_02174da4((int)obj, var1);
#if defined(jpn)
    int nameIdx = 0;
    Struct_ov000_021845c6 labels(data_ov000_021845c6);
    signed char cursorId = *(signed char*)(obj + 0x1fa1);
#else
    signed char cursorId = *(signed char*)(obj + 0x1d69);
#endif
#if !defined(jpn)
    int nameIdx = 0;
#endif
    if (func_ov000_0217542c(obj)) {
        Text_AppendFrameTag(dst, cursorId, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursorId);
    int keyArg = 0;
    for (int i = 0; i < 4; i++) {
        int v = var1[i];
        if (v < 0) {
            continue;
        }
        if (nameIdx != 0) {
            int f = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), keyArg);
            Text_Append(dst, (const char*)f);
        }
#if defined(jpn)
        char* r = labels.names[v];
#else
        int r = StandardStrings_Get(data_ov000_021834c4[v]);
#endif
        Text_AppendNTag(dst, nameIdx, (const char*)r);
        nameIdx++;
    }
}
