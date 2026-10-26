#include <globaldefs.h>

extern "C" void func_ov004_02153978(void* self, short* a, short* b, short* c);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov023_021e1518(void* obj);
extern "C" void func_ov023_021e1564(void* a, int b, int c, int d);
extern "C" void func_ov023_021e15b4(void* a, int b, int c, int d);

struct Struct_ov004_0215482c {
    unsigned char pad[0x7c];
    unsigned char unknown_7c_;
};
struct Struct_ov004_0216fa7c {
    unsigned short ids[2];
};
extern Struct_ov004_0215482c* data_ov004_021707c0;
extern const Struct_ov004_0216fa7c data_ov004_0216fa7c;

class Struct_ov004_0215482c_2 {
public:
    virtual void v00(); virtual void inline_ov004_0215482c_51(); virtual void inline_ov004_0215482c_52(); virtual void inline_ov004_0215482c_53();
    virtual void v04(); virtual void inline_ov004_0215482c_55(); virtual void inline_ov004_0215482c_56(); virtual void inline_ov004_0215482c_57();
    virtual void v08(); virtual void inline_ov004_0215482c_59(); virtual void v10(); virtual void inline_ov004_0215482c();
    virtual void inline_ov004_0215482c_2(); virtual void inline_ov004_0215482c_3(); virtual void v14(); virtual void inline_ov004_0215482c_5();
    virtual void inline_ov004_0215482c_6(); virtual void inline_ov004_0215482c_7(); virtual void v18(); virtual void inline_ov004_0215482c_9();
    virtual void v20(); virtual void inline_ov004_0215482c_11(); virtual void inline_ov004_0215482c_12(); virtual void inline_ov004_0215482c_13();
    virtual void v24(); virtual void inline_ov004_0215482c_15(); virtual void inline_ov004_0215482c_16(); virtual void inline_ov004_0215482c_17();
    virtual void v28(); virtual void inline_ov004_0215482c_19(); virtual void v30(); virtual void inline_ov004_0215482c_21();
    virtual void inline_ov004_0215482c_22(); virtual void inline_ov004_0215482c_23(); virtual void v34(); virtual void inline_ov004_0215482c_25();
    virtual void inline_ov004_0215482c_26(); virtual void inline_ov004_0215482c_27(); virtual void v38(); virtual void inline_ov004_0215482c_29();
    virtual void v40(); virtual void inline_ov004_0215482c_31(); virtual void inline_ov004_0215482c_32(); virtual void inline_ov004_0215482c_33();
    virtual void v44(); virtual void inline_ov004_0215482c_35(); virtual void inline_ov004_0215482c_36(); virtual void inline_ov004_0215482c_37();
    virtual void v48(); virtual void inline_ov004_0215482c_39(); virtual void v50(); virtual void inline_ov004_0215482c_41();
    virtual void inline_ov004_0215482c_42(); virtual void inline_ov004_0215482c_43(); virtual void v54(); virtual void inline_ov004_0215482c_45();
    virtual void inline_ov004_0215482c_46(); virtual void inline_ov004_0215482c_47(); virtual void v58();
    virtual void* inline_ov004_0215482c_49();
};

// USA: func_ov004_0215482c
extern "C" ARM int func_ov004_0215482c(void* self) {
    short b, c, d;
    func_ov004_02153978(self, &b, &c, &d);

    unsigned short mode = 0x2c;
    if (b != 0) {
        if (d >= 0) {
            mode = d + 6;
        } else if (c >= 0) {
            mode = c + 0x11;
            if (c == 7) mode = 0x18;
        }
    }

    func_ov023_021f645c(self, 0x34, mode, 0xf);

    Struct_ov004_0216fa7c pair = data_ov004_0216fa7c;
    func_ov023_021f645c(self, 0x35, pair.ids[data_ov004_021707c0->unknown_7c_], 0xf);

    int flag = (data_ov004_021707c0->unknown_7c_ == 0) ? 1 : 0;

    Struct_ov004_0215482c_2* node = (Struct_ov004_0215482c_2*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (node) {
        short var7, var8, var9;
        func_ov004_02153978(self, &var9, &var8, &var7);

        void* result = node->inline_ov004_0215482c_49();
        if (result) {
            func_ov023_021e1518(result);
            if (flag) {
                func_ov023_021e1564(result, var9, var8, var7);
            } else {
                func_ov023_021e15b4(result, var9, var8, var7);
            }
        }
    }
    return 0;
}
