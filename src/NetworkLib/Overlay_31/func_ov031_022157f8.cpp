#include <globaldefs.h>

struct Struct_ov031_02249ad4 {
    signed char* unknown_0_;
    int unused4;
    signed char* unknown_8_;
};

struct Struct_ov031_02246083 {
    unsigned char slot[0x18];
};

extern "C" void func_ov031_02215b64(void* obj, unsigned char* buf, int a, int b);

extern Struct_ov031_02246083 data_ov031_02246083;
extern Struct_ov031_02249ad4 data_ov031_02249ad4;

// USA: func_ov031_022157f8
extern "C" ARM void func_ov031_022157f8(void* obj, unsigned char* buf) {
    Struct_ov031_02246083 order = data_ov031_02246083;

    func_ov031_02215b64(obj, buf, 0x20, 0x18);

    for (int i = 0; i < 0x18; i++) {
        buf[i] ^= data_ov031_02249ad4.unknown_8_[i];
    }

    {
        unsigned char var2 = 0;
        unsigned char slot = 0;
        unsigned char v = 0;
        int i = 0;
        do {
            var2 = (unsigned char)i;
            slot = var2;
            v = buf[i];
            if (order.slot[var2] != 0xff) {
                do {
                    unsigned char next = order.slot[slot];
                    unsigned char t = buf[next];
                    buf[order.slot[var2]] = v;
                    order.slot[slot] = 0xff;
                    var2 = next;
                    slot = next;
                    v = t;
                } while (order.slot[slot] != 0xff);
            }
            i++;
        } while (i < 0x18);
    }

    for (int i = 0; i < 0x18; i++) {
        buf[i] ^= data_ov031_02249ad4.unknown_0_[i];
    }
}
