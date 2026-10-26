#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* func_ov017_021b8478(void* obj);

struct Struct_ov017_021bd35c { unsigned short unknown_0_, unknown_2_, unknown_4_, unknown_6_, unknown_8_; };
struct Struct_ov017_021bd35c_2 {
    unsigned char unknown_0_[0x16];
    unsigned short unknown_16_;
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
    unsigned char unknown_1c_[0x52 - 0x1c];
    unsigned short unknown_52_;
};
struct Struct_ov017_0218e674;

extern "C" void func_ov017_021bd35c(Struct_ov017_021bd35c_2* arg0, Struct_ov017_021bd35c* arg1);
extern "C" void func_ov017_021bb9ec(void* arg0, unsigned short arg1);
extern "C" int func_ov017_021bd3a4(Struct_ov017_0218e674* arg0);
extern "C" void func_ov017_021cdd70(unsigned short arg0, unsigned short arg1, unsigned short arg2, unsigned short arg3, unsigned short arg4, unsigned short arg5, unsigned char arg6);

struct Struct_ov017_021d6ce8 { unsigned char unknown_0_[3]; };
extern const Struct_ov017_021d6ce8 data_ov017_021d6ce8;

struct Struct_ov017_021cddd4_3 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned char unknown_10_;
};

struct Struct_ov017_021cddd4 {
    unsigned char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov017_021cddd4_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x3508];
#else
    unsigned char unknown1_0_[0x3718];
#endif
    void* unknown_3718_;
    unsigned char unknown_371c_[0x3734 - 0x371c];
    Struct_ov017_021bd35c_2* unknown_3734_;
};

// USA: func_ov017_021cddd4
extern "C" ARM void func_ov017_021cddd4(int p0, Evt021cddd4* evt, int unused, Base021cddd4* base, SearchStruct0202c1a4* search) {
    Entry021cddd4* entry = (Entry021cddd4*)func_ov017_021b8478(base->table);
    S021bd35c* obj = base->obj;
    if (p0 == 0) {
        if (evt->field_0x10 == LinkSession_GetOwnSlot(search)) {
            Src021bd35c src;
            src.h0 = evt->field_0x4;
            src.h2 = evt->field_0x8;
            src.h4 = evt->field_0xa;
            src.h8 = evt->field_0xc;
            src.h6 = evt->field_0xe;
            CopyFiveHalfwords_021bd35c(obj, &src);
            ByteTable3 tbl = data_ov017_021d6ce8;
            SetFieldA_021bb9ec(obj, tbl.v[evt->field_0x6]);
        }
    } else if (LinkSession_GetOwnSlot(search) == 0) {
        int kind = entry->field_0xc;
        S021bd35c* cur = base->obj;
        if (kind == evt->field_0x4) {
            EnqueueEventTag107_021cdd70(evt->field_0x4, 0, 0, 0, 0, 0, p0);
        } else if (kind == 0x13) {
            EnqueueEventTag107_021cdd70(evt->field_0x4, 1, 0x71e8, 0xffff, 0x199, 0x71e8, p0);
        } else if (HasFlag3orFlag2And9a_021bd3a4((Obj_021bd3a4*)cur)) {
            S021bd35c* o = base->obj;
            EnqueueEventTag107_021cdd70(evt->field_0x4, 1, o->field_0x16, o->field_0x52, o->field_0x1a, o->field_0x18, p0);
        } else {
            func_ov017_021cdd70(arg1->unknown_4_, 2, 0, 0, 0, 0, arg0);
        }
    }
}
