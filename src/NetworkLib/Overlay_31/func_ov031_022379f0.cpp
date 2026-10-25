#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" int memcmp(const void* a, const void* b, unsigned int len);
extern "C" void func_ov031_0223e2c0(int, void*);

typedef void (*Type_02001aec_2)(int);

struct Struct_02001aec_2 {
    char unknown_0_[6];
    unsigned char unknown_6_;
};

struct Struct_ov031_022379f0 {
    unsigned char unknown_0_[0x1300];
    Struct_02001aec_2 unknown_1300_[16];
    Type_02001aec_2 unknown_1370_;
    unsigned char unknown_1374_[0x814];
    unsigned long long unknown_1b88_;
    void* unknown_1b90_;
    unsigned char unknown_1b94_[2];
    unsigned char unknown_1b96_;
};

extern Struct_ov031_022379f0* data_ov031_02290d0c;
extern char data_ov031_02249280[];

// USA: func_ov031_022379f0
extern "C" ARM void func_ov031_022379f0(void* arg0) {
    unsigned long long var0 = GetCurrentTimestamp();
    Struct_ov031_022379f0* var1 = data_ov031_02290d0c;
    int var2;
    int var3;
    int var4;
    char* var5;
    char* var6;

    if (var0 < var1->unknown_1b88_ + 0x17f898) {
        return;
    }
    var4 = 0;
    var3 = 0;
    var2 = 0;
    var6 = (char*)var1;
    var5 = (char*)var1 + 0x1300;
    do {
        if (memcmp(name, data_ov031_02249280, 6) != 0) {
            if (*(unsigned char*)(entry + 0x1306) != 0) {
                used = 1;
            } else {
                var4 = 1;
            }
        }
        var2++;
        var5 += 7;
        var6 += 7;
    } while (var2 < 16);
    if (var3 && var4) {
        if (var1->unknown_1370_ != 0) {
            var1->unknown_1370_(2);
        }
    } else if (var3) {
        if (var1->unknown_1370_ != 0) {
            var1->unknown_1370_(1);
        }
    } else if (!var4) {
        if (var1->unknown_1370_ != 0) {
            var1->unknown_1370_(0);
        }
    }
    data_ov031_02290d0c->unknown_1b90_ = 0;
    data_ov031_02290d0c->unknown_1b96_ = 1;
    func_ov031_0223e2c0(0, arg0);
}
