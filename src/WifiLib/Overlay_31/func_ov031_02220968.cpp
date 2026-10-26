#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_0224f9f0_2 {
    int type;
    int unknown_4_;
};
struct Struct_ov031_0224f7f0 {
    char unknown_0_[0xc];
    int mode;
    int unknown_10_;
};
struct Struct_ov031_0224f884 {
    unsigned int words[16];
};
struct Struct_ov031_02220968 {
    unsigned char bytes[5];
};
struct Struct_ov031_02220968_2 {
    unsigned char bytes[13];
};
struct Struct_ov031_02220968_3 {
    unsigned char bytes[16];
};
union Struct_ov031_0224f804 {
    unsigned char bytes[0x20];
    Struct_ov031_02220968 unknown1_0_;
    Struct_ov031_02220968_2 unknown2_0_;
    Struct_ov031_02220968_3 unknown3_0_;
};
union Struct_ov031_02220968_4 {
    char text[0x21];
    Struct_ov031_02220968 unknown1_0_;
    Struct_ov031_02220968_2 unknown2_0_;
    Struct_ov031_02220968_3 unknown3_0_;
};

extern char data_ov031_0224f7dc[];
extern char data_ov031_0224f9c4[];
extern Struct_ov031_0224f9f0_2 data_ov031_0224f9f0;
extern Struct_ov031_0224f7f0 data_ov031_0224f7f0;
extern char data_ov031_0224fa28[4][0x28];
extern Struct_ov031_0224f804 data_ov031_0224f804[4];
extern Struct_ov031_0224f884 data_ov031_0224f884;
struct Struct_ov031_0224fac0_2 {
    char text[0x40];
    int length;
    int unknown_44_;
};
extern Struct_ov031_0224fac0_2 data_ov031_0224fac0;
extern "C" void func_ov031_022208b4(Struct_ov031_0224f804* destination, const char* text, int length);

// USA: func_ov031_02220968
extern "C" THUMB int func_ov031_02220968() {
    int result = 1;
    strcpy(data_ov031_0224f7dc, data_ov031_0224f9c4);
    switch (data_ov031_0224f9f0.type) {
    case 0:
        data_ov031_0224f7f0.mode = 0;
        break;
    case 1: {
        if (data_ov031_0224f9f0.unknown_4_ == 0) {
            result = -7;
            break;
        }
        data_ov031_0224f7f0.unknown_10_ = data_ov031_0224f9f0.unknown_4_;
        Struct_ov031_02220968_4 key;
        const Struct_ov031_02220968_4* text;
        const char (*source)[0x28] = data_ov031_0224fa28;
        Struct_ov031_0224f804* destination = data_ov031_0224f804;
        int i = 0;
        text = &key;
        do {
            memcpy(key.text, *source, 0x20);
            key.text[0x20] = 0;
            switch (strlen(key.text)) {
            case 0:
                break;
            case 5:
                data_ov031_0224f7f0.mode = 1;
                destination->unknown1_0_ = text->unknown1_0_;
                break;
            case 10:
                data_ov031_0224f7f0.mode = 1;
                func_ov031_022208b4(destination, text->text, 10);
                break;
            case 13:
                data_ov031_0224f7f0.mode = 2;
                destination->unknown2_0_ = text->unknown2_0_;
                break;
            case 26:
                data_ov031_0224f7f0.mode = 2;
                func_ov031_022208b4(destination, text->text, 26);
                break;
            case 16:
                data_ov031_0224f7f0.mode = 3;
                destination->unknown3_0_ = text->unknown3_0_;
                break;
            case 32:
                data_ov031_0224f7f0.mode = 3;
                func_ov031_022208b4(destination, text->text, 32);
                break;
            default:
                result = -7;
                break;
            }
            source++;
            destination++;
            i++;
        } while (i < 4);
        break;
    }
    case 2:
        data_ov031_0224f7f0.mode = 4;
        __memcpy(&data_ov031_0224f884, data_ov031_0224fac0.text, sizeof(data_ov031_0224f884));
        break;
    case 3:
        data_ov031_0224f7f0.mode = 5;
        __memcpy(&data_ov031_0224f884, data_ov031_0224fac0.text, sizeof(data_ov031_0224f884));
        break;
    default:
        result = -7;
        break;
    }
    return result;
}
