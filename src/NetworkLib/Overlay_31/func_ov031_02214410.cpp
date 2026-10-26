#include <globaldefs.h>

// USA: func_ov031_02214410
extern "C" ARM int func_ov031_02214410(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    int adj = obj[0x22];
    if (adj == 0) adj = obj[0x15];
    unsigned int kind = obj[0x16];
    if (kind < 10) {
        int t = obj[0x14];
        if (t == 3) return (int)0xffff3864 - adj;
        switch (t) {
            default: return (int)0xffff379c - adj;
            case 4: return -0xc800 - adj;
        }
    }
    if (kind < 13) return (int)0xffff34e0 - adj;
    int v = *(int*)(obj + 0x10);
    if (v == 0) return (int)0xffff3cb0 - adj;
    if (v == -1) return (int)0xffff347c - adj;
    if (v == -2) return (int)0xffff3418 - adj;
    if (v == -3) return (int)0xffff33b4 - adj;
    if (v == -4) return (int)0xffff30f8 - adj;
    if (v == -5) return (int)0xffff3094 - adj;
    if (v == -6) return (int)0xffff3030 - adj;
    return v;
}
