#include <globaldefs.h>


extern "C" int func_020ca4b4(void*, void*, int);

struct Struct_ov016_0219d1c0_3 {
    unsigned char pad0[0x8];
    void* unknown_8_;
    unsigned char pad1[0x8];
    unsigned int remaining;
    void* cur;
};

extern struct Struct_ov016_0219d1c0_3 data_ov016_0219d1c0;
extern unsigned char data_ov016_02195f78[1];

// USA: func_ov016_0218fcd4
extern "C" ARM void* func_ov016_0218fcd4(void) {
    if (data_ov016_0219d1c0.unknown_8_ != NULL)
        goto done;
    if (data_ov016_0219d1c0.remaining < 0x659c)
        goto fallback;
    data_ov016_0219d1c0.unknown_8_ = data_ov016_0219d1c0.cur;
    func_020ca4b4(data_ov016_02195f78, data_ov016_0219d1c0.cur, 0x659c);
    data_ov016_0219d1c0.cur = (unsigned char*)data_ov016_0219d1c0.cur + 0x659c;
    data_ov016_0219d1c0.remaining -= 0x659c;
    goto done;
fallback:
    return data_ov016_02195f78;
done:
    return data_ov016_0219d1c0.unknown_8_;
}
