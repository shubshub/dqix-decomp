#include <globaldefs.h>

// USA: func_ov025_021ed444
#pragma optimize_for_size off
#pragma opt_common_subs off
extern "C" ARM int func_ov025_021ed444(char* obj, int id, int val2, int type, int val3, short arg5, unsigned short arg6) {
    if (type >= 6) return -1;
    int ret = -1;
    if (id != 0) {
        unsigned char count = *(unsigned char*)(obj + 0x150);
        if (count < 0x10) {
            short pos = *(short*)(obj + 0x15c);
            int i;
            for (i = count - 1; i >= pos; i--) {
                int j = i + 1;
                *(unsigned short*)(obj + j * 2) = *(unsigned short*)(obj + i * 2);
                *(short*)(obj + j * 2 + 0x20) = *(short*)(obj + i * 2 + 0x20);
                *(unsigned char*)(obj + j + 0xa0) = *(unsigned char*)(obj + i + 0xa0);
                *(int*)(obj + j * 4 + 0xb0) = *(int*)(obj + i * 4 + 0xb0);
                *(short*)(obj + j * 2 + 0x60) = *(short*)(obj + i * 2 + 0x60);
                *(short*)(obj + j * 2 + 0x40) = *(short*)(obj + i * 2 + 0x40);
                *(unsigned short*)(obj + j * 2 + 0x80) = *(unsigned short*)(obj + i * 2 + 0x80);
            }
            *(unsigned short*)(obj + pos * 2) = id;
            *(short*)(obj + pos * 2 + 0x20) = val2;
            *(unsigned char*)(obj + pos + 0xa0) = type;
            *(int*)(obj + pos * 4 + 0xb0) = val3;
            if (*(short*)(obj + 0x152) == 0x7fff) {
                *(short*)(obj + 0x152) = 0;
            }
            *(short*)(obj + 0x152) = *(short*)(obj + 0x152) + 1;
            short var5 = *(short*)(obj + 0x152);
            *(short*)(obj + pos * 2 + 0x60) = var5;
            *(short*)(obj + pos * 2 + 0x40) = arg5;
            *(unsigned short*)(obj + pos * 2 + 0x80) = arg6;
            count = *(unsigned char*)(obj + 0x150);
            *(unsigned char*)(obj + 0x150) = count + 1;
            ret = var5;
        }
    }
    return ret;
}
