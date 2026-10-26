#include <globaldefs.h>


extern "C" int func_020ca4b4(void*, void*, int);

struct Struct_ov016_0219d1c0_6 {
    unsigned char pad0[0xc];
    unsigned int remaining;
    void* cur;
    unsigned char pad1[0x0c];
    void* unknown_20_;
};

extern struct Struct_ov016_0219d1c0_6 data_ov016_0219d1c0;
extern unsigned char data_ov016_0219ca60[1];

// USA: func_ov016_0218fe30
extern "C" ARM void* func_ov016_0218fe30(void) {
    if (data_ov016_0219d1c0.unknown_20_ != NULL)
        goto done;
    if (data_ov016_0219d1c0.remaining < 0x180)
        goto fallback;
    data_ov016_0219d1c0.unknown_20_ = data_ov016_0219d1c0.cur;
    func_020ca4b4(data_ov016_0219ca60, data_ov016_0219d1c0.cur, 0x180);
    data_ov016_0219d1c0.cur = (unsigned char*)data_ov016_0219d1c0.cur + 0x180;
    data_ov016_0219d1c0.remaining -= 0x180;
    goto done;
fallback:
    return data_ov016_0219ca60;
done:
    return data_ov016_0219d1c0.unknown_20_;
}
