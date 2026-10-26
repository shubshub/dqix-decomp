#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern char* data_ov004_021707c0; // pointer to struct with fields at 0x78 (short), 0x7a (short)
extern "C" short func_ov004_021537e0(void);
extern "C" short func_ov004_02153860(void);
extern "C" short func_ov004_021538f0(void);

// Real virtual calls: index 0x3c/4=15 (MethodNotify), index 0xec/4=59 (CallEc).
class Struct_ov004_02154c78 {
public:
	virtual void v00(); virtual void inline_ov004_02154c78_44(); virtual void inline_ov004_02154c78_45(); virtual void inline_ov004_02154c78_46();
	virtual void v04(); virtual void inline_ov004_02154c78_48(); virtual void inline_ov004_02154c78_49(); virtual void inline_ov004_02154c78_50();
	virtual void v08(); virtual void inline_ov004_02154c78_52(); virtual void v10(); virtual void inline_ov004_02154c78_54();
	virtual void inline_ov004_02154c78_55(); virtual void inline_ov004_02154c78_56(); virtual void v14();
	virtual void inline_ov004_02154c78_58(int a);
	virtual void inline_ov004_02154c78_59(); virtual void inline_ov004_02154c78_60(); virtual void v18(); virtual void inline_ov004_02154c78_2();
	virtual void v20(); virtual void inline_ov004_02154c78_4(); virtual void inline_ov004_02154c78_5(); virtual void inline_ov004_02154c78_6();
	virtual void v24(); virtual void inline_ov004_02154c78_8(); virtual void inline_ov004_02154c78_9(); virtual void inline_ov004_02154c78_10();
	virtual void v28(); virtual void inline_ov004_02154c78_12(); virtual void v30(); virtual void inline_ov004_02154c78_14();
	virtual void inline_ov004_02154c78_15(); virtual void inline_ov004_02154c78_16(); virtual void v34(); virtual void inline_ov004_02154c78_18();
	virtual void inline_ov004_02154c78_19(); virtual void inline_ov004_02154c78_20(); virtual void v38(); virtual void inline_ov004_02154c78_22();
	virtual void v40(); virtual void inline_ov004_02154c78_24(); virtual void inline_ov004_02154c78_25(); virtual void inline_ov004_02154c78_26();
	virtual void v44(); virtual void inline_ov004_02154c78_28(); virtual void inline_ov004_02154c78_29(); virtual void inline_ov004_02154c78_30();
	virtual void v48(); virtual void inline_ov004_02154c78_32(); virtual void v50(); virtual void inline_ov004_02154c78_34();
	virtual void inline_ov004_02154c78_35(); virtual void inline_ov004_02154c78_36(); virtual void v54(); virtual void inline_ov004_02154c78_38();
	virtual void inline_ov004_02154c78_39(); virtual void inline_ov004_02154c78_40(); virtual void v58();
	virtual void inline_ov004_02154c78_42();
};

// USA: func_ov004_02154c78
extern "C" ARM int func_ov004_02154c78(void* self) {
	Struct_ov004_02154c78* node = (Struct_ov004_02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
	if (!node) return 0;
#if defined(jpn)
	if (func_ov023_021f6f10(node) != 0x12) return 0;
#else
	if (func_ov024_021f6f10(node) != 0x12) return 0;
#endif

	node->inline_ov004_02154c78_42();
	if (!node) return 0;

	if (*(short*)(data_ov004_021707c0 + 0x7a) == 0) {
		Struct_ov004_02154c78* n2 = (Struct_ov004_02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1a);
		if (n2) n2->inline_ov004_02154c78_58(0);
	}

	if (func_ov004_021537e0() == 0) {
		Struct_ov004_02154c78* n2 = (Struct_ov004_02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1b);
		if (n2) n2->inline_ov004_02154c78_58(0);
	}

	if (func_ov004_02153860() == 0) {
		Struct_ov004_02154c78* n2 = (Struct_ov004_02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1c);
		if (n2) n2->inline_ov004_02154c78_58(0);
	}

	if (func_ov004_021538f0() == 0) {
		Struct_ov004_02154c78* n2 = (Struct_ov004_02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1d);
		if (n2) n2->inline_ov004_02154c78_58(0);
	}

	return 0;
}
