#include <globaldefs.h>

struct Struct_ov031_02233178_2 { unsigned char entries[4]; };
struct Struct_ov031_02249064 { Struct_ov031_02233178_2 selected, detail; };
struct Struct_ov031_02233178 { void* first; void* entries[3]; };
struct Struct_ov031_02290cc0_10 { unsigned char selection; unsigned char padding[3]; Struct_ov031_02233178* objects; };
extern Struct_ov031_02249064 data_ov031_02249064;
extern Struct_ov031_02290cc0_10 data_ov031_02290cc0;
extern "C" void func_ov031_02234ff8(void*, int, int);
extern "C" int func_ov031_0223607c(int);
extern "C" void func_ov031_0223bb58(void*, int, int, int);

// USA: func_ov031_02233178
extern "C" ARM void func_ov031_02233178() {
    Struct_ov031_02233178_2 selected = {{data_ov031_02249064.selected.entries[0], data_ov031_02249064.selected.entries[1], data_ov031_02249064.selected.entries[2], data_ov031_02249064.selected.entries[3]}};
    Struct_ov031_02233178_2 detail = {{data_ov031_02249064.detail.entries[0], data_ov031_02249064.detail.entries[1], data_ov031_02249064.detail.entries[2], data_ov031_02249064.detail.entries[3]}};
    unsigned char* colors = selected.entries;
    if (data_ov031_02290cc0.selection > 3) return;
    int value = colors[data_ov031_02290cc0.selection];
    func_ov031_02234ff8(data_ov031_02290cc0.objects->first, value, value);
    if (data_ov031_02290cc0.selection == 3) return;
    int index = func_ov031_0223607c(data_ov031_02290cc0.selection);
    if (index > 2) index = 3;
    func_ov031_0223bb58(data_ov031_02290cc0.objects->entries[data_ov031_02290cc0.selection], -1, 0, detail.entries[index]);
}
