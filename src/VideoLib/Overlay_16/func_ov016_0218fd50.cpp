#include <globaldefs.h>


extern "C" int func_020ca4b4(void*, void*, int);

struct Struct_ov016_0219d1c0_4 {
    unsigned char pad0[0x4];
    void* unknown_4_;
    unsigned char pad1[0x4];
    unsigned int remaining;
    void* cur;
};

extern struct Struct_ov016_0219d1c0_4 data_ov016_0219d1c0;
extern unsigned char data_ov016_02193e78[1];

// USA: func_ov016_0218fd50
extern "C" ARM void* func_ov016_0218fd50(void) {
    if (data_ov016_0219d1c0.unknown_4_ != NULL)
        goto done;
    if (data_ov016_0219d1c0.remaining < 0x2100)
        goto fallback;
    data_ov016_0219d1c0.unknown_4_ = data_ov016_0219d1c0.cur;
    func_020ca4b4(data_ov016_02193e78, data_ov016_0219d1c0.cur, 0x2100);
    data_ov016_0219d1c0.cur = (unsigned char*)data_ov016_0219d1c0.cur + 0x2100;
    data_ov016_0219d1c0.remaining -= 0x2100;
    goto done;
fallback:
    return data_ov016_02193e78;
done:
    return data_ov016_0219d1c0.unknown_4_;
}
