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
extern "C" int func_ov003_0215c300(struct Struct_ov003_02158e94_2* arg0, int arg1);
extern "C" void func_ov003_02159464(void* arg0);
extern "C" void func_ov003_0215c510(void* arg0);

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* arg0);

struct Struct_0205d81c;
struct Struct_0205d0e0 {
    unsigned char unknown_0_[0xc5];
    unsigned char unknown_c5_;
};
struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
int WindowPane_IsReady(unsigned char* obj);
void TouchGrid_SetTouchedCell(void* obj, int value);
extern "C" int Window_Update(void* p, int val);

extern "C" void func_ov003_021594c4(void* arg0);
extern "C" void func_ov003_02159b20(void* arg0);
extern "C" void func_ov003_02159c04(void* arg0);
extern "C" void func_ov003_02159d0c(void* arg0, int arg1);
extern "C" void func_ov003_0215a5b4(void* arg0);
extern "C" void func_ov003_0215a740(void* arg0, int arg1, int arg2);
extern "C" void func_ov003_0215af00(void* arg0);
extern "C" void func_ov003_0215b1dc(void* arg0, int arg1);
extern "C" void func_ov003_0215af9c(void* arg0);
extern "C" void func_ov003_0215b0e8(void* arg0);
extern "C" void func_ov003_0215c0ec(void* arg0);

struct Struct_ov003_02158e94 {
    unsigned char unknown_0_[0xf4];
    unsigned char unknown_f4_[0x4];
    unsigned char unknown_f8_[0x478];
    struct Struct_020e28dc* unknown_570_;
    int unknown_574_;
    unsigned char unknown_578_[0xa];
    unsigned char unknown_582_;
    unsigned char unknown_583_[0x4];
    unsigned char unknown_587_;
    signed char unknown_588_;
    unsigned char unknown_589_[0x16];
    unsigned char unknown_59f_;
};

// USA: func_ov003_02158e94
extern "C" ARM int func_ov003_02158e94(struct Struct_ov003_02158e94* arg0, int arg1) {
    if (arg0->unknown_588_ == 11) {
        return 1;
    }

    arg0->unknown_574_ = arg1;

    if (func_ov003_0215c300((struct Struct_ov003_02158e94_2*)arg0, arg1) != 0) {
        return 0;
    }

    func_ov003_02159464(arg0);

    if ((arg0->unknown_59f_ & 8) && !(arg0->unknown_59f_ & 0x10)) {
        func_ov003_0215c510(arg0);
        return 0;
    }

    if (self->choice != 0 && !GetInnerFlagBit0020e28dc(self->choice) && self->state != 0 && self->field_0x587 == 0) {
        struct Elem_0205d81c* elem = Window_GetActivePane((struct Struct_0205d81c*)self->elements);
        if (elem != 0 && WindowPane_IsReady((unsigned char*)elem) != 0 && (elem->flagsC5 & 2) == 0) {
            TouchGrid_SetTouchedCell(self->field_0xf8, -1);
        }
        self->field_0x582 = Window_Update(self->elements, amount);
    }

    switch (arg0->unknown_588_) {
    case 0:
        func_ov003_021594c4(arg0);
        break;
    case 1:
        func_ov003_02159b20(arg0);
        break;
    case 2:
        func_ov003_02159c04(arg0);
        break;
    case 3:
        func_ov003_02159d0c(arg0, arg1);
        break;
    case 4:
        func_ov003_0215a5b4(arg0);
        break;
    case 5:
        func_ov003_0215a740(arg0, arg1, 0x406);
        break;
    case 6:
        func_ov003_0215a740(arg0, arg1, 0x410);
        break;
    case 7:
        func_ov003_0215a740(arg0, arg1, 0x41a);
        break;
    case 8:
        func_ov003_0215af00(arg0);
        break;
    case 9:
        func_ov003_0215b1dc(arg0, arg1);
        break;
    case 10:
        func_ov003_0215af9c(arg0);
        break;
    case 12:
        func_ov003_0215b0e8(arg0);
        break;
    }

    func_ov003_0215c0ec(arg0);
    return 0;
}
