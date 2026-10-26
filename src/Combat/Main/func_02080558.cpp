#include <globaldefs.h>

extern "C" void func_020804fc(void* obj, int p1);
extern "C" void func_020813ec(void* obj, int p1);

struct Struct_0207f0ac;
struct Struct_02080558 {
    short* unknown_0_;
    char pad[0x13 - 4];
    unsigned char count;
};
extern "C" Struct_02080558* func_0207f0ac(Struct_0207f0ac* list, int id);

struct Struct_0207f524;
struct Struct_02080558_2 {
    char pad[4];
    short id;
    char pad2[0x2a - 6];
    unsigned char flags;
};
extern "C" Struct_02080558_2* func_0207f6ac(Struct_0207f524* list, int id);

// USA: func_02080558
extern "C" ARM void func_02080558(void* obj, int p1, int result, int flag, unsigned char extra) {
    if (flag) {
        func_020804fc(obj, p1);
    }
    Struct_02080558* e = func_0207f0ac((Struct_0207f0ac*)((char*)obj + 0xc), p1);
    if (e != 0) {
        for (unsigned char i = 0; i < e->count; i++) {
            short var2 = e->unknown_0_[i];
            Struct_02080558_2* e2 = func_0207f6ac((Struct_0207f524*)((char*)obj + 4), var2);
            if (e2 != 0) {
                if (e2->id == result) {
                    e2->flags = e2->flags | 4;
                    goto end;
                }
            }
        }
    }
end:
    if (extra == 0) return;
    func_020813ec(obj, p1);
}
