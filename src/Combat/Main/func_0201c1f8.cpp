#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_0201c1f8;
struct Struct_0201c1f8_2 {
    unsigned short id_, unknown_2_;
    unsigned char unknown_4_;
    char name_[8], text_[28];
    unsigned char category_ : 3;
    unsigned char unknown_29_3_ : 1;
    unsigned char unknown_29_4_ : 1;
    unsigned char unknown_29_5_ : 1;
    unsigned char unknown_29_6_ : 1;
    unsigned char unknown_29_7_ : 1;
    unsigned char mode_;
    void inline_0201c1f8(unsigned short v) { id_ = v; }
    void inline_0201c1f8_2(unsigned short v) { unknown_2_ = v; }
    void inline_0201c1f8_3(unsigned char v) { category_ = v; }
    void SetMode(unsigned char v) { mode_ = v; }
    void inline_0201c1f8_5(unsigned char v) { unknown_29_3_ = v; }
    void inline_0201c1f8_6(unsigned char v) { unknown_29_4_ = v; }
    void inline_0201c1f8_7(unsigned char v) { unknown_29_5_ = v; }
    void inline_0201c1f8_8(unsigned char v) { unknown_29_6_ = v; }
    void inline_0201c1f8_9(unsigned char v) { unknown_29_7_ = v; }
};
struct Struct_020fdc14_2 { void* unknown_0_[2]; Struct_0201c1f8* unknown_8_; };
extern Struct_020fdc14_2 data_020fdc14 __attribute__((aligned(4)));
extern "C" void func_0201c4d4(Struct_0201c1f8*, Struct_0201c1f8_2*);

// USA: func_0201c1f8
extern "C" ARM int func_0201c1f8(Script::Parameter* params) {
    Struct_0201c1f8_2 record;
    int result = 0;
    record.id_ = 0;
    record.unknown_2_ = 0;
    record.name_[0] = 0;
    record.unknown_4_ = 0;
    record.category_ = 0;
    record.unknown_29_4_ = 1;
    record.unknown_29_3_ = 0;
    record.unknown_29_5_ = 0;
    record.unknown_29_6_ = 0;
    record.unknown_29_7_ = 0;
    record.inline_0201c1f8(params[0].ToInt());
    record.inline_0201c1f8_2(params[1].ToInt());
    const char* label = params[2].ToString();
    record.inline_0201c1f8_3(params[3].ToInt());
    const char* name = params[4].ToString();
    const char* text = params[5].ToString();
    record.SetMode(params[6].ToInt());
    record.inline_0201c1f8_6(params[7].ToInt());
    record.inline_0201c1f8_5(params[8].ToInt());
    record.inline_0201c1f8_7(params[9].ToInt());
    record.inline_0201c1f8_8(params[10].ToInt());
    record.inline_0201c1f8_9(params[11].ToInt());
    if (text == NULL) {
        result = 0;
    } else {
        memcpy(record.name_, name, sizeof(record.name_));
        record.name_[7] = 0;
        memcpy(record.text_, text, sizeof(record.text_));
        Struct_020fdc14_2* var5 = &data_020fdc14;
        Struct_0201c1f8* queue = var5->unknown_8_;
        record.text_[27] = 0;
        func_0201c4d4(queue, &record);
        result = 1;
    }
    return result;
}
