#include <globaldefs.h>

struct Struct_020be828_2 {
    unsigned short unknown_0_;
    unsigned char volume;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned short reserved;
};

struct Struct_020be828 {
    unsigned long unknown_0_;
    Struct_020be828_2 param;
};

struct Struct_020be828_3 {
    char header[0x18];
    unsigned long baseOffset;
};

struct Struct_020bc454;
struct Struct_020bc5bc;
struct Struct_020bc4f8_3;
struct Struct_020bc16c_2;
struct Struct_020bc1ac;
struct Holder;

extern "C" Struct_020bc5bc* func_020bc454(Struct_020bc454* handle, int arg1, int arg2);
extern "C" void* func_020bc5bc(int arg0, Struct_020bc5bc* player);
extern "C" int func_020bded0(int arg0, unsigned long arg1, void* heap, int arg3, void** data);
extern "C" int func_020bddec(int arg0, unsigned long arg1, void* heap, int arg3,
                             Struct_020be828_3** data);
extern "C" void func_020bc4ec(void* player);
extern "C" void func_020bc4f8(Struct_020bc4f8_3* player, int arg1, int arg2, int bank);
extern "C" void func_020bc16c(Struct_020bc16c_2* handle, unsigned char volume);
extern "C" void func_020bc1ac(Struct_020bc1ac* handle, int arg1);
extern "C" void func_020bc1ec(Holder* handle, int arg1);

// USA: func_020be828
extern "C" ARM int func_020be828(void* handle, int arg1, int arg2, int arg3,
                                 const Struct_020be828* info, int arg5) {
    Struct_020bc5bc* player;
    void* heap;
    Struct_020be828_3* seq;
    void* bank;
    int result;

    player = func_020bc454((Struct_020bc454*)handle, arg1, arg3);
    if (player == NULL)
        return 0;

    heap = func_020bc5bc(arg1, player);

    result = func_020bded0(arg2, 6, heap, 0, &bank);
    if (result != 0) {
        func_020bc4ec(player);
        return 0;
    }

    result = func_020bddec(arg5, 1, heap, 0, &seq);
    if (result != 0) {
        func_020bc4ec(player);
        return 0;
    }

    func_020bc4f8((Struct_020bc4f8_3*)player, (int)((unsigned char*)seq + seq->baseOffset), 0,
                                    (int)bank);

    func_020bc16c((Struct_020bc16c_2*)handle, info->param.volume);
    func_020bc1ac((Struct_020bc1ac*)handle, info->param.unknown_3_);
    func_020bc1ec((Holder*)handle, arg5);
    return 1;
}
