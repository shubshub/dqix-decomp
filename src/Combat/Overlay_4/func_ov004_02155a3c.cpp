#include <globaldefs.h>

extern "C" int func_ov004_0215513c(void* obj, short* pB, short* arg2, short* arg3);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern unsigned char* data_ov004_021707c4;
extern unsigned short data_ov004_0216fadc[];
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov023_021e1518(void* obj);
extern "C" void func_ov023_021e1814(void* a, void* b, int c, int d, int e);
extern "C" void func_ov023_021e1870(void* a, void* b, int c, int d, int e);

class Struct_ov004_02155a3c {
public:
    virtual void v00(); virtual void inline_ov004_02155a3c_44(); virtual void inline_ov004_02155a3c_45(); virtual void inline_ov004_02155a3c_46();
    virtual void v04(); virtual void inline_ov004_02155a3c_48(); virtual void inline_ov004_02155a3c_49(); virtual void inline_ov004_02155a3c_50();
    virtual void v08(); virtual void inline_ov004_02155a3c_52(); virtual void v10(); virtual void inline_ov004_02155a3c_54();
    virtual void inline_ov004_02155a3c_55(); virtual void inline_ov004_02155a3c_56(); virtual void v14(); virtual void inline_ov004_02155a3c_58();
    virtual void inline_ov004_02155a3c_59(); virtual void inline_ov004_02155a3c_60(); virtual void v18(); virtual void inline_ov004_02155a3c_2();
    virtual void v20(); virtual void inline_ov004_02155a3c_4(); virtual void inline_ov004_02155a3c_5(); virtual void inline_ov004_02155a3c_6();
    virtual void v24(); virtual void inline_ov004_02155a3c_8(); virtual void inline_ov004_02155a3c_9(); virtual void inline_ov004_02155a3c_10();
    virtual void v28(); virtual void inline_ov004_02155a3c_12(); virtual void v30(); virtual void inline_ov004_02155a3c_14();
    virtual void inline_ov004_02155a3c_15(); virtual void inline_ov004_02155a3c_16(); virtual void v34(); virtual void inline_ov004_02155a3c_18();
    virtual void inline_ov004_02155a3c_19(); virtual void inline_ov004_02155a3c_20(); virtual void v38(); virtual void inline_ov004_02155a3c_22();
    virtual void v40(); virtual void inline_ov004_02155a3c_24(); virtual void inline_ov004_02155a3c_25(); virtual void inline_ov004_02155a3c_26();
    virtual void v44(); virtual void inline_ov004_02155a3c_28(); virtual void inline_ov004_02155a3c_29(); virtual void inline_ov004_02155a3c_30();
    virtual void v48(); virtual void inline_ov004_02155a3c_32(); virtual void v50(); virtual void inline_ov004_02155a3c_34();
    virtual void inline_ov004_02155a3c_35(); virtual void inline_ov004_02155a3c_36(); virtual void v54(); virtual void inline_ov004_02155a3c_38();
    virtual void inline_ov004_02155a3c_39(); virtual void inline_ov004_02155a3c_40(); virtual void v58();
    virtual void* inline_ov004_02155a3c_42();
};

// USA: func_ov004_02155a3c
extern "C" ARM int func_ov004_02155a3c(void* self) {
    short b, c, d;
    func_ov004_0215513c(self, &b, &c, &d);

    unsigned short mode = 7;
    if (b != 0 && c >= 0) {
        if (c == 8) mode = 5;
        if (c == 9) mode = 6;
    }

    func_ov023_021f645c(self, 0x34, mode, 0xf);

    unsigned char idx = data_ov004_021707c4[0x10];
    unsigned short val = data_ov004_0216fadc[idx];
    func_ov023_021f645c(self, 0x35, val, 0xf);

    int flag = (data_ov004_021707c4[0x10] == 0) ? 1 : 0;

    Struct_ov004_02155a3c* node = (Struct_ov004_02155a3c*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (node) {
        short var8, var9, var10;
        func_ov004_0215513c(self, &var10, &var9, &var8);

        void* result = node->inline_ov004_02155a3c_42();
        if (result) {
            func_ov023_021e1518(result);
            if (flag) {
                func_ov023_021e1814(result, (void*)(int)var10, var9, var8, 1);
            } else {
                func_ov023_021e1870(result, (void*)(int)var10, var9, var8, 1);
            }
        }
    }
    return 0;
}
