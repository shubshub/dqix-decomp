#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue3C1_3D9 = 0x3d9 };
enum { kRegionValue64_7C = 0x7c };
enum { kRegionValue3C0_3D8 = 0x3d8 };
enum { kRegionValue3BD_3D5 = 0x3d5 };
#else
enum { kRegionValue3C1_3D9 = 0x3c1 };
enum { kRegionValue64_7C = 0x64 };
enum { kRegionValue3C0_3D8 = 0x3c0 };
enum { kRegionValue3BD_3D5 = 0x3bd };
#endif

struct Container020e0310;
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);

extern char data_ov003_0217ff3e;

// USA: func_ov003_0215e13c
ARM void AppendEntryNames_0215e13c(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + kRegionValue3C1_3D9);
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + kRegionValue64_7C);
    int i = 0;
    while (i < *(unsigned char*)(base + kRegionValue3C0_3D8)) {
        unsigned char key = *(unsigned char*)(base + i + kRegionValue3BD_3D5);
        int name = KeyTable_Get(c, key);
        Text_AppendNTag(dst, i, (const char*)name);
        if (i != *(unsigned char*)(base + kRegionValue3C0_3D8) - 1) {
            Text_Append(dst, &data_ov003_0217ff3e);
        }
        i++;
    }
}
