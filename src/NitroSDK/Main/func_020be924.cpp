#include <globaldefs.h>

struct Struct_020be924_2 {
    unsigned short unknown_0_;
    unsigned char volume;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned short reserved;
};

struct Struct_020be924 {
    unsigned long offset;
    Struct_020be924_2 param;
};

struct Struct_020be924_3 {
    char header[0x18];
    unsigned long baseOffset;
};

struct Struct_020bc454;
struct Struct_020bc5bc;
struct Struct_020bc4f8_3;
struct Struct_020bc16c_2;
struct Struct_020bc1ac;
struct Struct_02061c04_19;

extern "C" Struct_020bc5bc* func_020bc454(Struct_020bc454* handle, int arg1, int arg2);
extern "C" void* func_020bc5bc(int arg0, Struct_020bc5bc* player);
extern "C" int func_020bded0(int arg0, unsigned long arg1, void* heap, int arg3, void** data);
extern "C" void func_020bc4ec(void* player);
extern "C" void func_020bc4f8(Struct_020bc4f8_3* player, int arg1, int arg2, int bank);
extern "C" void func_020bc16c(Struct_020bc16c_2* handle, unsigned char volume);
extern "C" void func_020bc1ac(Struct_020bc1ac* handle, int arg1);
extern "C" void func_020bc210(Struct_02061c04_19* handle, int arg1, int index);

// USA: func_020be924
extern "C" ARM int func_020be924(void* handle, int arg1, int arg2, int arg3,
                                 const Struct_020be924* sound, const Struct_020be924_3* arg5,
                                 int arg6, int index) {
    Struct_020bc5bc* player;
    void* heap;
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

    func_020bc4f8((Struct_020bc4f8_3*)player, (int)((unsigned char*)arg5 + arg5->baseOffset),
                                    sound->offset, (int)bank);

    func_020bc16c((Struct_020bc16c_2*)handle, sound->param.volume);
    func_020bc1ac((Struct_020bc1ac*)handle, sound->param.unknown_3_);
    func_020bc210((Struct_02061c04_19*)handle, arg6, index);
    return 1;
}
