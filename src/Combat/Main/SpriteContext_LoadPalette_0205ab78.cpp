#include <globaldefs.h>

struct Struct_020b033c {
    char pad[8];
    int arr[3];
};
extern "C" void func_020b033c(struct Struct_020b033c* obj);

struct Hdr02b0288 {
    unsigned char pad[0xc];
    unsigned short unknown_c_;
    unsigned short count;
};
extern "C" int func_020b022c(struct Hdr02b0288* h, void** out);
extern "C" int func_020b01f0(struct Hdr02b0288* h, void** out);

extern "C" void func_020b08b8(void* arg0, void* arg1, int zero, int mode, void* arg4);
extern "C" void func_020b07c0(void* arg0, int zero, int mode, void* arg3);

struct Obj0205ab78 {
    char pad0[0x24];
    struct Struct_020b033c unknown_24_;
    char pad1[0x50 - 0x38];
    unsigned char unknown_50_;
};

// Main, originally func_0205ab78 (USA 0x0205ab78, EUR 0x0205ab88, JPN 0x0205bf14)
extern "C" ARM int SpriteContext_LoadPalette(struct Obj0205ab78* obj, struct Hdr02b0288* h, void* other) {
    int var0;
    int mode;

    func_020b033c(&obj->unknown_24_);
    void* var2 = 0;
    void* var3 = 0;
    int var4 = func_020b022c(h, &var3);

    if (h == 0) {
        var0 = 1;
    } else if (other == 0) {
        var0 = 1;
    } else {
        if (func_020b01f0(h, &var2)) {
            var0 = 0;
        } else {
            var0 = 1;
        }
    }
    if (var0) {
        return 1;
    }

    mode = (obj->unknown_50_ == 0) ? 1 : 2;
    if (var4) {
        func_020b08b8(var2, var3, 0, mode, &obj->unknown_24_);
    } else {
        func_020b07c0(var2, 0, mode, &obj->unknown_24_);
    }
    return 0;
}
