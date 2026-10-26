#include <globaldefs.h>

struct PackedNibbleArray0206e120 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021d0924(unsigned char a, unsigned char b, unsigned short c, unsigned short d);

// USA: func_0206e164
extern "C" ARM void func_0206e164(struct PackedNibbleArray0206e120* obj, int index, int value) {
    if (index >= 0xCC || index < 0) {
        return;
    }
    int var0 = index / 2;
    if (index % 2) {
        unsigned char n = obj->bits[var0] >> 4;
        n = (n & 0xc) | value;
        obj->bits[var0] &= 0xf;
        obj->bits[var0] |= n << 4;
    } else {
        unsigned char n = obj->bits[var0] & 0xf;
        n = (n & 0xc) | value;
        obj->bits[var0] &= 0xf0;
        obj->bits[var0] |= n;
    }
    if (LinkSession_IsHostOrSolo(LinkSession_GetInstance()) == 0) {
        return;
    }
    if (index < 0xAE) {
        return;
    }
    func_ov017_021d0924(7, 0, index, value);
}
