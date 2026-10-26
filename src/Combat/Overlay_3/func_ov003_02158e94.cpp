#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov003_02158e94_2;
extern "C" int func_ov003_0215c300(struct Struct_ov003_02158e94_2* obj, int amount);
extern "C" void func_ov003_02159464(void* obj);
extern "C" void func_ov003_0215c510(void* obj);

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xc5];
    unsigned char flagsC5;
};
extern "C" struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
extern "C" int WindowPane_IsReady(unsigned char* obj);
extern "C" void TouchGrid_SetTouchedCell(void* obj, int value);
extern "C" int Window_Update(void* p, int val);

extern "C" void func_ov003_021594c4(void* obj);
extern "C" void func_ov003_02159b20(void* obj);
extern "C" void func_ov003_02159c04(void* obj);
extern "C" void func_ov003_02159d0c(void* obj, int amount);
extern "C" void func_ov003_0215a5b4(void* obj);
extern "C" void func_ov003_0215a740(void* obj, int amount, int msgId);
extern "C" void func_ov003_0215af00(void* obj);
extern "C" void func_ov003_0215b1dc(void* obj, int amount);
extern "C" void func_ov003_0215af9c(void* obj);
extern "C" void func_ov003_0215b0e8(void* obj);
extern "C" void func_ov003_0215c0ec(void* obj);

struct Struct_ov003_02158e94 {
    unsigned char pad0[0xf4];
    unsigned char elements[0x4];
    unsigned char field_0xf8[0x478];
    struct Struct_020e28dc* choice;
    int unknown_574_;
    unsigned char unknown_578_[0xa];
    unsigned char field_0x582;
    unsigned char unknown_583_[0x4];
    unsigned char unknown_587_;
    signed char state;
    unsigned char unknown_589_[0x16];
    unsigned char flags;
};

// USA: func_ov003_02158e94
extern "C" ARM int func_ov003_02158e94(struct Struct_ov003_02158e94* self, int amount) {
    if (self->state == 11) {
        return 1;
    }

    self->unknown_574_ = amount;

    if (func_ov003_0215c300((struct Struct_ov003_02158e94_2*)self, amount) != 0) {
        return 0;
    }

    func_ov003_02159464(self);

    if ((self->flags & 8) && !(self->flags & 0x10)) {
        func_ov003_0215c510(self);
        return 0;
    }

    if (self->choice != 0 && !func_020e28dc(self->choice) && self->state != 0 && self->unknown_587_ == 0) {
        struct Elem_0205d81c* elem = Window_GetActivePane((struct Struct_0205d81c*)self->elements);
        if (elem != 0 && WindowPane_IsReady((unsigned char*)elem) != 0 && (elem->flagsC5 & 2) == 0) {
            TouchGrid_SetTouchedCell(self->field_0xf8, -1);
        }
        self->field_0x582 = Window_Update(self->elements, amount);
    }

    switch (self->state) {
    case 0:
        func_ov003_021594c4(self);
        break;
    case 1:
        func_ov003_02159b20(self);
        break;
    case 2:
        func_ov003_02159c04(self);
        break;
    case 3:
        func_ov003_02159d0c(self, amount);
        break;
    case 4:
        func_ov003_0215a5b4(self);
        break;
    case 5:
        func_ov003_0215a740(self, amount, 0x406);
        break;
    case 6:
        func_ov003_0215a740(self, amount, 0x410);
        break;
    case 7:
        func_ov003_0215a740(self, amount, 0x41a);
        break;
    case 8:
        func_ov003_0215af00(self);
        break;
    case 9:
        func_ov003_0215b1dc(self, amount);
        break;
    case 10:
        func_ov003_0215af9c(self);
        break;
    case 12:
        func_ov003_0215b0e8(self);
        break;
    }

    func_ov003_0215c0ec(self);
    return 0;
}
