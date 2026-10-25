#include <globaldefs.h>

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);
int AppendFormatted02041fac(char* buf, int a, int b);
int StandardStrings_Get(int value);

// USA: func_ov002_0216186c  (semantic: AppendCursorAndNameTags_0216186c)
#if defined(jpn)
extern "C" int func_02042638(char* buf, int a, int b);
extern const char data_ov002_0216da9a[];
extern const char data_ov002_0216daa3[];
extern const char data_ov002_0216daa8[];

extern "C" ARM void func_ov002_0216186c(char* base, char* dst, int flag) {
    if (dst == NULL) {
        return;
    }

    int cursor = *(short*)(base + 0x1adc);
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    func_02042638(dst, (int)data_ov002_0216da9a, 0x10);

    Text_AppendNTag(dst, 0, data_ov002_0216daa3);

    void* ptr = *(void**)(base + 0x1aa4);
    Text_Append(dst, (const char*)ptr);

    Text_AppendNTag(dst, 1, data_ov002_0216daa8);
}
#else
extern "C" ARM void func_ov002_0216186c(char* base, char* dst, int flag) {
    if (dst == NULL) {
        return;
    }

    int cursor = *(short*)(base + 0x1c00 + 0x14);
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    int field = KeyTable_Get((struct Container020e0310*)(base + 0x20), 0x23f0);
    AppendFormatted02041fac(dst, field, 0x10);

    Text_AppendNTag(dst, 0, (const char*)StandardStrings_Get(0x1b));

    void* ptr = *(void**)(base + 0x1000 + 0xbdc);
    Text_Append(dst, (const char*)ptr);

    Text_AppendNTag(dst, 1, (const char*)StandardStrings_Get(0x1c));
}
#endif
