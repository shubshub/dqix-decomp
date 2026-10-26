#include <globaldefs.h>

struct Struct_ov031_02223268_2;
struct Struct_ov031_022269d8;
extern "C" Struct_ov031_02223268_2* func_ov031_0223baa0(Struct_ov031_022269d8* obj, int idx);
extern "C" int func_ov031_0223bdb0(int, int, int);
struct Struct_ov031_02222ce4;
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4* obj, int idx, int val);
extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);

struct Struct_ov031_02290cc0_8 { unsigned char idx; char pad[3]; char* field4; };
extern Struct_ov031_02290cc0_8 data_ov031_02290cc0;
extern unsigned short data_ov031_02249082[];
extern unsigned short data_ov031_02249084[];

// USA: func_ov031_02232f58
extern "C" ARM void func_ov031_02232f58(void) {
    int r4 = data_ov031_02290cc0.idx - 4;
    Struct_ov031_02223268_2* elem = func_ov031_0223baa0(
        (Struct_ov031_022269d8*)*(void**)(data_ov031_02290cc0.field4 + r4 * 4 + 0x10), 0);
    func_ov031_0223bdb0(0, 0x32, (int)elem);

    func_ov031_0223bbd8(*(void**)(data_ov031_02290cc0.field4 + r4 * 4 + 0x10), -1,
        data_ov031_02249082[(r4 + 3) * 2], data_ov031_02249084[(r4 + 3) * 2]);

    func_ov031_0223bcc8(
        (Struct_ov031_02222ce4*)*(void**)(data_ov031_02290cc0.field4 + r4 * 4 + 0x10), -1, 3);
}
