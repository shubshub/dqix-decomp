#include <globaldefs.h>

struct Struct_ov023_021e1b0c_2 {
    Struct_ov023_021e1b0c_2* next;
    unsigned char unknown4[6];
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned char selected : 1;
    unsigned char unknown_e_1_ : 1;
    unsigned char category : 6;
    unsigned char unknown_f_;
};

struct Struct_ov023_021e1b0c {
    Struct_ov023_021e1b0c_2* first;
    Struct_ov023_021e1b0c_2* entries;
    short count;
};

extern "C" Struct_ov023_021e1b0c_2* func_ov023_021e1bac(Struct_ov023_021e1b0c* selection, int arg1, int category, int arg3);

// USA: func_ov023_021e1b0c
extern "C" ARM void func_ov023_021e1b0c(void* context, int arg1, int category, int arg3) {
    Struct_ov023_021e1b0c* selection = (Struct_ov023_021e1b0c*)context;
	Struct_ov023_021e1b0c_2* node = func_ov023_021e1bac(selection, arg1, category, arg3);
	if (node == 0) return;
	selection->first = node;
	while (node != 0) {
		Struct_ov023_021e1b0c_2* next = func_ov023_021e1bac(selection, arg1, category, arg3);
		node->next = next;
		node = next;
	}
}
