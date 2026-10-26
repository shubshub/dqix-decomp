#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* func_ov017_021b8478(void* obj);

struct Struct_ov017_021bd35c { unsigned short h0, h2, h4, h6, h8; };
struct Struct_ov017_021bd35c_2 {
    unsigned char pad0[0x16];
    unsigned short unknown_16_;
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
    unsigned char unknown_1c_[0x52 - 0x1c];
    unsigned short unknown_52_;
};
struct Obj_021bd3a4;

extern "C" void func_ov017_021bd35c(Struct_ov017_021bd35c_2* obj, Struct_ov017_021bd35c* src);
extern "C" void func_ov017_021bb9ec(void* obj, unsigned short v);
extern "C" int func_ov017_021bd3a4(Obj_021bd3a4* obj);
extern "C" void func_ov017_021cdd70(unsigned short a0, unsigned short a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, unsigned char a6);

struct Struct_ov017_021d6ce8 { unsigned char v[3]; };
extern const Struct_ov017_021d6ce8 data_ov017_021d6ce8;

struct Struct_ov017_021cddd4_3 {
    unsigned char pad0[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned char field_0x10;
};

struct Struct_ov017_021cddd4 {
    unsigned char pad0[0xc];
    int unknown_c_;
};

struct Struct_ov017_021cddd4_2 {
#if defined(jpn)
    unsigned char pad0[0x3508];
#else
    unsigned char pad0[0x3718];
#endif
    void* table;
    unsigned char unknown_371c_[0x3734 - 0x371c];
    Struct_ov017_021bd35c_2* obj;
};

// USA: func_ov017_021cddd4
extern "C" ARM void func_ov017_021cddd4(int p0, Struct_ov017_021cddd4_3* evt, int unused, Struct_ov017_021cddd4_2* base, SearchStruct0202c1a4* search) {
    Struct_ov017_021cddd4* entry = (Struct_ov017_021cddd4*)func_ov017_021b8478(base->table);
    Struct_ov017_021bd35c_2* obj = base->obj;
    if (p0 == 0) {
        if (evt->field_0x10 == LinkSession_GetOwnSlot(search)) {
            Struct_ov017_021bd35c src;
            src.h0 = evt->unknown_4_;
            src.h2 = evt->unknown_8_;
            src.h4 = evt->unknown_a_;
            src.h8 = evt->unknown_c_;
            src.h6 = evt->unknown_e_;
            func_ov017_021bd35c(obj, &src);
            Struct_ov017_021d6ce8 tbl = data_ov017_021d6ce8;
            func_ov017_021bb9ec(obj, tbl.v[evt->unknown_6_]);
        }
    } else if (LinkSession_GetOwnSlot(search) == 0) {
        int kind = entry->unknown_c_;
        Struct_ov017_021bd35c_2* cur = base->obj;
        if (kind == evt->unknown_4_) {
            func_ov017_021cdd70(evt->unknown_4_, 0, 0, 0, 0, 0, p0);
        } else if (kind == 0x13) {
            func_ov017_021cdd70(evt->unknown_4_, 1, 0x71e8, 0xffff, 0x199, 0x71e8, p0);
        } else if (func_ov017_021bd3a4((Obj_021bd3a4*)cur)) {
            Struct_ov017_021bd35c_2* o = base->obj;
            func_ov017_021cdd70(evt->unknown_4_, 1, o->unknown_16_, o->unknown_52_, o->unknown_1a_, o->unknown_18_, p0);
        } else {
            func_ov017_021cdd70(evt->unknown_4_, 2, 0, 0, 0, 0, p0);
        }
    }
}
