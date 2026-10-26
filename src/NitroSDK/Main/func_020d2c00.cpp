#include <globaldefs.h>

struct Struct_020d2c00;

struct Struct_020d2c00_3 {
    Struct_020d2c00* unknown_0_;
    Struct_020d2c00_3* next;
};

struct Struct_020d2c00 {
    unsigned char header[0x18];
    Struct_020d2c00_3* unknown_18_;
    unsigned char rest[0x20];
};

struct Struct_020d2c00_2 {
    unsigned char header[0x18];
    Struct_020d2c00_3 unknown_18_[4];
};

void CleanCacheRange(const void* addr, unsigned int size);

extern "C" {
    void func_020d21f8();
    void func_020d220c();
}

// USA: func_020d2c00
extern "C" ARM void func_020d2c00(Struct_020d2c00_2* bank) {
    Struct_020d2c00_3* var0;
    int i;
    func_020d21f8();
    var0 = &bank->unknown_18_[0];
    i = 0;
    do {
        Struct_020d2c00* const var2 = bank->unknown_18_[i].unknown_0_;
        if (var2 != NULL) {
            if (var0 == var2->unknown_18_) {
                var2->unknown_18_ = bank->unknown_18_[i].next;
                CleanCacheRange(var2, sizeof(Struct_020d2c00));
            } else {
                Struct_020d2c00_3* link = var2->unknown_18_;
                if (link != NULL) {
                    do {
                        if (var0 == link->next)
                            break;
                        link = link->next;
                    } while (link != NULL);
                }
                link->next = bank->unknown_18_[i].next;
                CleanCacheRange(link, sizeof(Struct_020d2c00_3));
            }
        }
        i++;
        var0++;
    } while (i < 4);
    func_020d220c();
}
