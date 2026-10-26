#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" int func_ov004_02155090(void);
extern "C" int func_ov004_02155104(void);

extern char* data_ov004_021707c4;

// Real virtual calls: index 0x3c/4=15 (MethodNotify), index 0xec/4=59 (CallEc).
class Struct_ov004_02155ea4 {
public:
	virtual void v00(); virtual void inline_ov004_02155ea4_34(); virtual void inline_ov004_02155ea4_35(); virtual void inline_ov004_02155ea4_36();
	virtual void v04(); virtual void inline_ov004_02155ea4_38(); virtual void inline_ov004_02155ea4_39(); virtual void inline_ov004_02155ea4_40();
	virtual void v08(); virtual void inline_ov004_02155ea4_42(); virtual void v10(); virtual void inline_ov004_02155ea4_44();
	virtual void inline_ov004_02155ea4_45(); virtual void inline_ov004_02155ea4_46(); virtual void v14();
	virtual void inline_ov004_02155ea4_48(int a);
	virtual void inline_ov004_02155ea4_49(); virtual void inline_ov004_02155ea4_50(); virtual void v18(); virtual void inline_ov004_02155ea4_52();
	virtual void v20(); virtual void inline_ov004_02155ea4_54(); virtual void inline_ov004_02155ea4_55(); virtual void inline_ov004_02155ea4_56();
	virtual void v24(); virtual void inline_ov004_02155ea4_58(); virtual void inline_ov004_02155ea4_59(); virtual void inline_ov004_02155ea4_60();
	virtual void v28(); virtual void inline_ov004_02155ea4_2(); virtual void v30(); virtual void inline_ov004_02155ea4_4();
	virtual void inline_ov004_02155ea4_5(); virtual void inline_ov004_02155ea4_6(); virtual void v34(); virtual void inline_ov004_02155ea4_8();
	virtual void inline_ov004_02155ea4_9(); virtual void inline_ov004_02155ea4_10(); virtual void v38(); virtual void inline_ov004_02155ea4_12();
	virtual void v40(); virtual void inline_ov004_02155ea4_14(); virtual void inline_ov004_02155ea4_15(); virtual void inline_ov004_02155ea4_16();
	virtual void v44(); virtual void inline_ov004_02155ea4_18(); virtual void inline_ov004_02155ea4_19(); virtual void inline_ov004_02155ea4_20();
	virtual void v48(); virtual void inline_ov004_02155ea4_22(); virtual void v50(); virtual void inline_ov004_02155ea4_24();
	virtual void inline_ov004_02155ea4_25(); virtual void inline_ov004_02155ea4_26(); virtual void v54(); virtual void inline_ov004_02155ea4_28();
	virtual void inline_ov004_02155ea4_29(); virtual void inline_ov004_02155ea4_30(); virtual void v58();
	virtual void inline_ov004_02155ea4_32();
};

// USA: func_ov004_02155ea4
extern "C" ARM int func_ov004_02155ea4(void* obj) {
    Struct_ov004_02155ea4* node = (Struct_ov004_02155ea4*)func_ov023_021f6880(func_ov011_021849c8(obj), 0x39);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 0x12) return 0;

    node->inline_ov004_02155ea4_32();
    if (!node) return 0;

    if (*(short*)(data_ov004_021707c4 + 0xe) == 0) {
        Struct_ov004_02155ea4* n2 = (Struct_ov004_02155ea4*)func_ov023_021f6880(func_ov011_021849c8(obj), 0x1a);
        if (n2) n2->inline_ov004_02155ea4_48(0);
    }

    if (func_ov004_02155090() == 0) {
        Struct_ov004_02155ea4* n2 = (Struct_ov004_02155ea4*)func_ov023_021f6880(func_ov011_021849c8(obj), 0x1b);
        if (n2) n2->inline_ov004_02155ea4_48(0);
    }

    if (func_ov004_02155104() == 0) {
        Struct_ov004_02155ea4* n2 = (Struct_ov004_02155ea4*)func_ov023_021f6880(func_ov011_021849c8(obj), 0x1c);
        if (n2) n2->inline_ov004_02155ea4_48(0);
    }

    return 0;
}
