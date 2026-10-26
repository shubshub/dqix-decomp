#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02168438_1244 = 0x4d8 };
#else
enum { Enum_ov003_02168438_1244 = 0x4dc };
#endif


struct Struct_ov003_02168438 { char pad[Enum_ov003_02168438_1244]; void* unknown_4dc_; char pad2[0xc]; unsigned char unknown_4ec_; char pad3[0xb2]; unsigned char unknown_59f_; };

extern "C" ARM void func_ov003_021694b8(void* obj, int id);
extern "C" ARM void func_ov003_021685dc(void* obj);
extern "C" ARM void func_ov003_0216adbc(void* obj);
extern "C" void func_ov003_02168654(void* obj);
extern "C" void func_ov003_02168b50(void* obj);
extern "C" ARM void func_ov003_02168cc8(void* obj);
extern "C" void func_ov003_02168d3c(void* obj, void* arg, int val);
extern "C" ARM void func_ov003_02169430(void* obj);
extern "C" void func_ov003_0216aa28(void* obj);

// USA: func_ov003_02168438
extern "C" ARM int func_ov003_02168438(struct Struct_ov003_02168438* obj, void* arg) {
    obj->unknown_4dc_ = arg;
    unsigned char state = obj->unknown_4ec_;
    if (state != 0 && state != 3 && state != 4) {
        unsigned char flags = obj->unknown_59f_;
        if (!(flags & 2) || (flags & 4)) {
            func_ov003_021694b8(obj, (int)arg);
        }
    }
    if (obj->unknown_4ec_ != 0) {
        func_ov003_021685dc(obj);
    }
    unsigned char flags2 = obj->unknown_59f_;
    if ((flags2 & 2) && !(flags2 & 4)) {
        func_ov003_0216adbc(obj);
        return obj->unknown_4ec_ == 6;
    }
    switch (obj->unknown_4ec_) {
        case 0: func_ov003_02168654(obj); break;
        case 1: func_ov003_02168b50(obj); break;
        case 2: func_ov003_02168cc8(obj); break;
        case 3: func_ov003_02168d3c(obj, arg, 0x3f2); break;
        case 4: func_ov003_02168d3c(obj, arg, 0x3fc); break;
        case 5: func_ov003_02169430(obj); break;
        case 6: return 1;
        default: break;
    }
    func_ov003_0216aa28(obj);
    return 0;
}
