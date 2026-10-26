#include <globaldefs.h>

extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" void func_ov002_0215b918(unsigned char* obj, int key, int b, int c);

// USA: func_ov002_0215ece4
extern "C" ARM void func_ov002_0215ece4(void* base, char* dst, int c, int arg3, int arg4) {
    char* obj = (char*)base;
    char* buf;
    int last;
    int tag = 0;
    int inRange = (c >= 0) && (c <= 3);

    if (inRange) {
        int i;
        last = arg4 - 1;
        buf = obj + 0x1000;
        for (i = arg3; i < arg4; i++) {
            void* entry = *(void**)(obj + (i << 2) + 0x2000 + 0x4a0);
            if (entry != 0) {
                const char* name = *(const char**)entry;
                Text_AppendNTag(dst, tag, name);
                if (i != last) {
                    Text_Append(dst, *(char**)(buf + 0xbdc));
                }
                tag++;
            }
        }
    }

    unsigned char var8 = *(unsigned char*)(obj + 0x2000 + 0x520);
    if (var8 == 0) {
        func_ov002_0215b918((unsigned char*)obj, 0x11, 0, 0);
        return;
    }
    func_ov002_0215b918((unsigned char*)obj, 0x11, arg3 / 8, (var8 + 7) / 8);
}
