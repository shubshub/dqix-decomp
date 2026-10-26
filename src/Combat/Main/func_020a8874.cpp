#include <globaldefs.h>

extern char g_sePlayer;
extern "C" void SePlayer_UnloadExtraArchiveA(void* obj);

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_ov017_021d1874(unsigned char a, unsigned char b, unsigned char c, int d, int e, int f, int g);

struct Struct_020a84e0 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};

// USA: func_020a8874
extern "C" ARM void func_020a8874(struct Struct_020a84e0* obj) {
    if (obj->unknown_4_ != 0) {
        obj->unknown_4_ = 0;
        SePlayer_UnloadExtraArchiveA(&g_sePlayer);
        signed char idx = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)LinkSession_GetInstance());
        obj->unknown_5_ &= ~(1 << idx);
        func_ov017_021d1874(obj->byte0, obj->unknown_1_, obj->unknown_2_, 0, (unsigned char)idx, 0, 0);
    }
}
