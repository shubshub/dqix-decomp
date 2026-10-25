#include <globaldefs.h>

int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);
void SetElementStateOrCreate0215b918(unsigned char* obj, int key, int b, int c);

// USA: func_ov002_0215ece4
extern "C" ARM void func_ov002_0215ece4(void* arg0, char* arg1, int arg2, int arg3, int arg4) {
    char* var0 = (char*)arg0;
    char* var1;
    int var2;
    int var3 = 0;
    int var4 = (arg2 >= 0) && (arg2 <= 3);

    if (inRange) {
        int i;
        last = clampedSum - 1;
        buf = obj + 0x1000;
        for (i = productB; i < clampedSum; i++) {
            void* entry = *(void**)(obj + (i << 2) + 0x2000 + 0x4a0);
            if (entry != 0) {
                const char* name = *(const char**)entry;
                Text_AppendNTag(dst, tag, name);
                if (i != last) {
                    Text_Append(dst, *(char**)(buf + 0xbdc));
                }
                var3++;
            }
        }
    }

    unsigned char var8 = *(unsigned char*)(var0 + 0x2000 + 0x520);
    if (var8 == 0) {
        func_ov002_0215b918((unsigned char*)var0, 0x11, 0, 0);
        return;
    }
    func_ov002_0215b918((unsigned char*)var0, 0x11, arg3 / 8, (var8 + 7) / 8);
}
