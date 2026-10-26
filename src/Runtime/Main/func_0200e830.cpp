#include <globaldefs.h>

struct Struct_0200e830 {
    void* location;
    void* unknown_4_;
    void* dtor;
    void* unknown_c_;
    long unknown_10_;
    void* unknown_14_;
};

struct Struct_0200d958_13 {
    unsigned long unknown_0_[16];
    char* unknown_40_;
    unsigned long unknown_44_;
    unsigned long unknown_48_;
    unsigned short unknown_4c_;
    bool unknown_4e_;
    bool unknown_4f_;
    bool unknown_50_;
};

struct Struct_0200e830_2 {
    unsigned char* unknown_0_;
    void* location;
    void* dtor;
    Struct_0200e830* unknown_c_;
    char* unknown_10_;
    char* unknown_14_;
    char* fp;
    Struct_0200d958_13 target;
};

struct Struct_0200e830_3 {
    char* unknown_0_;
    char* unknown_4_;
    char* unknown_8_;
    void* unknown_c_;
    void* unknown_10_;
    int target;
};

struct Struct_0200e830_4 {
    Struct_0200e830_3 info;
    Struct_0200e830_2 context;
};

extern "C" unsigned char func_0200dbdc(const Struct_0200e830_4* arg0);
extern "C" unsigned char func_0200dbf8(Struct_0200e830_4* arg0);
extern "C" char* func_0200d958(char* p, long* value);

// USA: func_0200e830
extern "C" ARM Struct_0200e830* func_0200e830(Struct_0200e830_2* context, Struct_0200e830_3* info) {
    Struct_0200e830_4 var0;
    unsigned char action;
    Struct_0200e830* var2;
    long var3;

    var0.info = *info;
    var0.context = *context;
    for (action = func_0200dbdc(&var0);; action = func_0200dbf8(&var0)) {
        switch (action) {
            case 13:
                break;

            case 0:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 15:
            case 16:
            case 17:
            case 18:
                continue;

            case 14:
            default:
                return 0;
        }
        break;
    }

    func_0200d958(var0.info.unknown_8_ + 1, &var3);
    var2 = (Struct_0200e830*)(var0.context.fp + var3);
    context->unknown_0_ = (unsigned char*)var2->unknown_4_;
    context->location = var2->location;
    context->dtor = 0;
    context->unknown_c_ = var2;

    return var2;
}
