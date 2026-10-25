#include <globaldefs.h>

extern char g_sePlayer;
void SePlayer_UnloadExtraArchiveA(void* obj);

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void* func_0202ae18(void);
extern "C" void func_ov017_021d1874(unsigned char a, unsigned char b, unsigned char c, int d, int e, int f, int g);

struct Obj020a8874 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3_pad;
    unsigned char flag_0x4;
    unsigned char mask_0x5;
};

// USA: func_020a8874
ARM void NotifyOv017SlotCleared020a8874(struct Obj020a8874* obj) {
    if (obj->flag_0x4 != 0) {
        obj->flag_0x4 = 0;
        SePlayer_UnloadExtraArchiveA(&g_sePlayer);
        signed char idx = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)func_0202ae18());
        obj->mask_0x5 &= ~(1 << idx);
        func_ov017_021d1874(obj->byte0, obj->byte1, obj->byte2, 0, (unsigned char)idx, 0, 0);
    }
}
