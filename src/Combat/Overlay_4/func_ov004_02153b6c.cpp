#include <globaldefs.h>


extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_020deb58(void*, int, int, int, int);
extern "C" void* func_020dec30(void*, int, int, int, int, int);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

class Struct_ov004_02153b6c_2 {
public:
	virtual void v00(); virtual void inline_ov004_02153b6c_37(); virtual void inline_ov004_02153b6c_38(); virtual void inline_ov004_02153b6c_39();
	virtual void v04(); virtual void inline_ov004_02153b6c_41(); virtual void inline_ov004_02153b6c_42(); virtual void inline_ov004_02153b6c_43();
	virtual void v08(); virtual void inline_ov004_02153b6c_45(); virtual void v10(); virtual void inline_ov004_02153b6c_47();
	virtual void inline_ov004_02153b6c_48(); virtual void inline_ov004_02153b6c_49(); virtual void v14(); virtual void inline_ov004_02153b6c_51();
	virtual void inline_ov004_02153b6c_52(); virtual void inline_ov004_02153b6c_53(); virtual void v18(); virtual void inline_ov004_02153b6c_55();
	virtual void v20(); virtual void inline_ov004_02153b6c_57(); virtual void inline_ov004_02153b6c_58(); virtual void inline_ov004_02153b6c_59();
	virtual void v24(); virtual void inline_ov004_02153b6c_2(); virtual void inline_ov004_02153b6c_3(); virtual void inline_ov004_02153b6c_4();
	virtual void v28(); virtual void inline_ov004_02153b6c_6(); virtual void v30(); virtual void inline_ov004_02153b6c_8();
	virtual void inline_ov004_02153b6c_9(); virtual void inline_ov004_02153b6c_10(); virtual void v34(); virtual void inline_ov004_02153b6c_12();
	virtual void inline_ov004_02153b6c_13(); virtual void inline_ov004_02153b6c_14(); virtual void v38(); virtual void inline_ov004_02153b6c_16();
	virtual void v40(); virtual void inline_ov004_02153b6c_18(); virtual void inline_ov004_02153b6c_19(); virtual void inline_ov004_02153b6c_20();
	virtual void v44(); virtual void inline_ov004_02153b6c_22(); virtual void inline_ov004_02153b6c_23(); virtual void inline_ov004_02153b6c_24();
	virtual void v48(); virtual void inline_ov004_02153b6c_26(); virtual void v50(); virtual void inline_ov004_02153b6c_28();
	virtual void inline_ov004_02153b6c_29(); virtual void inline_ov004_02153b6c_30(); virtual void v54(); virtual void inline_ov004_02153b6c_32();
	virtual void inline_ov004_02153b6c_33(); virtual void inline_ov004_02153b6c_34();
	virtual void* inline_ov004_02153b6c_35();
};

struct Struct_ov004_02153b6c {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int pad8;
    unsigned int fieldC;
};

// USA: func_ov004_02153b6c
extern "C" ARM void func_ov004_02153b6c(void* obj, int arg1, int arg2, int arg3, short* out1, short* out2) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0x2d);
    if (node) {
        if (func_ov023_021f6f10(node) == 0x11) {
            void* obj2 = ((Struct_ov004_02153b6c_2*)node)->inline_ov004_02153b6c_35();
            void* ptr = Scenario_GetInstance();
            int count = func_020deb58(obj2, 1, arg1, arg2, arg3);

            short matchCount = 0;
            short i;
            for (i = 0; i < count; i++) {
                struct Struct_ov004_02153b6c* entry = (struct Struct_ov004_02153b6c*)func_020dec30(obj2, i, 1, arg1, arg2, arg3);
                if (entry) {
                    int extracted = (entry->fieldC << 9) >> 21;
                    extracted = (unsigned short)extracted;
                    if (extracted > 0) {
                        if (Scenario_TestFlag((int)ptr, (unsigned char*)ptr + 0x8c, extracted + 0x76 + 0xc00)) {
                            matchCount++;
                        }
                    }
                }
            }
            *out1 = matchCount;
            *out2 = (short)count;
        }
    }
}
