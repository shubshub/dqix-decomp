#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_020999f0;
struct Struct_020995f8_2;

struct Struct_020995f8 {
    unsigned short id;
    unsigned short unknown_2_0_ : 15;
    unsigned short : 1;
    unsigned char flag4 : 1;
    unsigned char : 7;
    unsigned char text[7];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 1;
    unsigned char unknown_c_5_ : 2;
    unsigned char unknown_c_7_ : 1;
    unsigned char unknown_d_0_ : 7;
    unsigned char unknown_d_7_ : 1;
    unsigned char unknown_e_0_ : 2;
    unsigned char unknown_e_2_ : 4;
    unsigned char unknown_e_6_ : 1;
    unsigned char unknown_e_7_ : 1;
};

extern "C" void func_020999f0(struct Struct_020999f0* list, struct Struct_020995f8_2* src);
extern struct Struct_020999f0* data_02109924;

// USA: func_020995f8
extern "C" ARM int func_020995f8(Script::Parameter* params, int numParams) {
    struct Struct_020995f8 e;
    const char* text;

    e.id = 0;
    e.unknown_2_0_ = 0;
    e.text[0] = 0;
    e.unknown_c_0_ = 0;
    e.unknown_c_4_ = 0;
    e.unknown_c_5_ = 0;
    e.unknown_c_7_ = 0;
    e.unknown_d_7_ = 0;
    e.unknown_e_0_ = 0;
    e.unknown_e_2_ = 8;
    e.unknown_e_7_ = 0;
    e.flag4 = 0;

    e.id = (params++)->ToInt();
    e.unknown_2_0_ = (params++)->ToInt();
    (params++)->ToString();
    e.unknown_c_0_ = (params++)->ToInt();
    text = (params++)->ToString();
    (params++)->ToString();
    e.unknown_d_0_ = (params++)->ToInt();
    (params++)->ToInt();
    (params++)->ToInt();
    e.unknown_c_4_ = (params++)->ToInt();
    e.unknown_c_5_ = (params++)->ToInt();
    (params++)->ToString();
    e.unknown_c_7_ = (params++)->ToInt();
    params += 3;
    e.unknown_d_7_ = (params++)->ToInt();
    e.unknown_e_0_ = (params++)->ToInt();
    e.unknown_e_2_ = (params++)->ToInt();
    e.unknown_e_6_ = (params++)->ToInt();
    e.unknown_e_7_ = (params++)->ToInt();
    e.flag4 = (params++)->ToInt();

    if (text == 0) {
        return 0;
    }
    memcpy(e.text, text, 7);
    e.text[6] = 0;
    func_020999f0(data_02109924, (struct Struct_020995f8_2*)&e);
    return 1;
}
