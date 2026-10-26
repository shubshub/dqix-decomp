#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_02109404_3 {
    unsigned char field_0;
    unsigned char unknown_1_;
    unsigned char selected;
    unsigned char unknown_3_[3];
    unsigned short index;
};
struct Struct_02095364 {
    unsigned short id : 9;
    unsigned short unknown_1_1_ : 1;
    unsigned short unknown_1_2_ : 1;
    unsigned short bit11 : 1;
    unsigned short unknown_1_4_ : 1;
    unsigned short rest : 3;
};
struct Struct_02109418_2 {
    char unknown_0_[0xa8];
    Struct_02095364* entries;
};
extern Struct_02109404_3 data_02109404 __attribute__((aligned(4)));
extern Struct_02109418_2 data_02109418;
extern short data_020f13d8;

// USA: func_02095364
extern "C" ARM int func_02095364(Script::Parameter* params) {
    if (data_02109404.unknown_1_ != 0) {
        data_02109404.index++;
        return 1;
    }
    unsigned short id = params[0].ToInt();
    unsigned short var1 = params[5].ToInt();
    unsigned short bit11 = params[7].ToInt();
    unsigned short var3 = params[8].ToInt();
    unsigned short var4 = params[9].ToInt();
    Struct_02095364* table = data_02109418.entries;
    if (table != 0) {
        int index = data_02109404.index;
        table[index].id = id;
        table[index].unknown_1_1_ = var1;
        table[index].bit11 = bit11;
        table[index].unknown_1_2_ = var3;
        table[index].unknown_1_4_ = var4;
    }
    int var7 = data_02109404.index + 1;
    int selection = data_020f13d8;
    data_02109404.index = var7;
    if (selection >= 0 && id == selection)
        data_02109404.selected = var3 != 0;
    return 1;
}
