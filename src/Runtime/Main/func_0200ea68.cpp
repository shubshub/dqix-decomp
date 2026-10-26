#include <globaldefs.h>

struct Struct_0200e984 { int count, field4, field8; unsigned char* entries; };
struct Struct_0200e984_2;
struct Struct_0200ea68 { int unknown_0_[21]; };
struct Struct_0200ea68_2 {
    void* text_; int unknown_4_[6]; Struct_0200ea68 unknown_1c_;
};
struct Struct_0200ea68_3 {
    int unknown_0_, unknown_4_; unsigned char* unknown_8_;
    int unknown_c_, unknown_10_, unknown_14_;
};
struct Struct_0200ea68_4 { Struct_0200ea68_3 cursor_; Struct_0200ea68_2 unknown_18_; };
struct Struct_0200ea68_5 { unsigned char* unknown_0_; int unknown_4_, unknown_8_; };
extern "C" int func_0200dbdc(Struct_0200ea68_4*);
extern "C" int func_0200dbf8(Struct_0200ea68_4*);
extern "C" unsigned char* func_0200d9e4(unsigned char*, int*);
extern "C" unsigned char* func_0200d958(unsigned char*, int*);
extern "C" int func_0200eff0(void*, unsigned char*, Struct_0200e984_2*);
extern "C" int func_0200e984(void*, Struct_0200e984*);
extern "C" void func_0200ea08(Struct_0200ea68_2*, Struct_0200ea68_3*, Struct_0200e984*, unsigned char*);
extern "C" void func_0200efb8();

// USA: func_0200ea68
extern "C" ARM unsigned char* func_0200ea68(Struct_0200ea68_2* owner, Struct_0200ea68_3* cursor, Struct_0200e984_2* state) {
    Struct_0200ea68_4 context;
    Struct_0200ea68_5 var1;
    Struct_0200e984 list;
    context.cursor_.unknown_0_ = cursor->unknown_0_;
    context.cursor_.unknown_4_ = cursor->unknown_4_;
    context.cursor_.unknown_8_ = cursor->unknown_8_;
    context.cursor_.unknown_c_ = cursor->unknown_c_;
    context.cursor_.unknown_10_ = cursor->unknown_10_;
    context.cursor_.unknown_14_ = cursor->unknown_14_;
    context.unknown_18_.text_ = owner->text_;
    context.unknown_18_.unknown_4_[0] = owner->unknown_4_[0];
    context.unknown_18_.unknown_4_[1] = owner->unknown_4_[1];
    context.unknown_18_.unknown_4_[2] = owner->unknown_4_[2];
    context.unknown_18_.unknown_4_[3] = owner->unknown_4_[3];
    context.unknown_18_.unknown_4_[4] = owner->unknown_4_[4];
    context.unknown_18_.unknown_4_[5] = owner->unknown_4_[5];
    context.unknown_18_.unknown_1c_ = owner->unknown_1c_;
    int var3 = func_0200dbdc(&context);
    for (;;) {
        switch (var3) {
        case 12: {
            unsigned char* data = context.cursor_.unknown_8_;
            var1.unknown_0_ = (unsigned char*)(data[1] | (data[2] << 8) | (data[3] << 16) | (data[4] << 24));
            unsigned char* next = func_0200d9e4(data + 5, &var1.unknown_4_);
            func_0200d958(next, &var1.unknown_8_);
            if (!func_0200eff0(owner->text_, var1.unknown_0_, state)) break;
            goto done;
        }
        case 15: {
            unsigned char* next = func_0200d9e4(context.cursor_.unknown_8_ + 1, &list.count);
            next = func_0200d9e4(next, &list.field4);
            list.entries = func_0200d958(next, &list.field8);
            if (!func_0200e984(owner->text_, &list)) func_0200ea08(owner, cursor, &list, context.cursor_.unknown_8_);
            break;
        }
        case 0: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 13: case 16: case 17: case 18: case 19:
            break;
        default:
            func_0200efb8();
            goto done;
        }
        var3 = func_0200dbf8(&context);
    }
done:
    return context.cursor_.unknown_8_;
}
