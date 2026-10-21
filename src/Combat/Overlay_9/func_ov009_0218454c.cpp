#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"
#include "World/Object3D.h"
#include "Resource/CreationSlotLayout.h"

struct Struct_0201099c_14 {
    char unknown_0_[0x18];
};

struct Struct_0205cfd4 {
    char unknown_0_[0xbc];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xe0];
};

struct Struct_0205bef8 {
    int unknown_0_[0x10];
};

unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ZeroInit020de848(void* table);
void ResetStruct020dfc40(Struct020dfc40* table);
#if defined(jpn)
#define func_ov009_021847ec func_ov009_02185850
#endif
extern "C" void func_ov009_021847ec(void* checker);
void ResetList0204af64(List0204af64* background);
void InitStruct0205cfd4(InitTarget0205cfd4* window);
extern "C" void func_0204c684(Canvas* canvas);
void Init0205bef8(Struct_0205bef8* cursor);
void ResetFields021847c4(CreationSlotLayout* grid);
int FindEntryIndexByKey020424e4(int text, int mode);

extern char data_ov009_0218aca4[];

struct Struct_ov009_021842a0_2 {
#if defined(jpn)
    SafeAllocator unknown_0_[8];
#else
    SafeAllocator unknown_0_[9];
#endif
    SafeAllocator* unknown_b4_;
    SafeAllocator* unknown_b8_;
#if !defined(jpn)
    void* unknown_bc_;
    void* unknown_c0_;
    void* unknown_c4_;
#endif
    char unknown_c8_[0x18];
    Struct_0201099c_14 unknown_e0_;
    void* unknown_f8_;
#if defined(jpn)
    char unknown_fc_[0x20];
#else
    char unknown_fc_[0x3c];
#endif
    List0204af64 backgrounds_[6];
    InitTarget0205cfd4 windows_[2];
    Canvas canvases_[1];
    Canvas canvases2_[4];
    void* pixels_;
    void* pixels2_;
    void* renderer_;
    void* sprites_;
    void* unk_7e0;
    void* renderer2_;
    void* sprites2_;
    void* unk_7ec;
    void* characters_[2];
    void* character_;
    void* nextCharacter_;
    int unk_800;
    int targetAngle_;
    char unk_808[0x70];
    Object3D object_;
    char camera_[0x2c8];
    Struct_0205bef8 cursor_;
    CreationSlotLayout grid_;
    short cursorX_;
    short cursorY_;
    short cursorWidth_;
    short cursorHeight_;
    short lastX_;
    short lastY_;
    signed char state_;
    unsigned char step_;
    char unk_c5a[2];
    int modelTasks_[3];
    char unk_c68[0x70];
    Object3D object2_;
    unsigned char selection_;
    unsigned char unk_d85;
    char unk_d86[2];
    void* member_;
    int touchedChoice_;
    int task_;
    unsigned char loadStep_;
    unsigned char mode_;
    short timer_;
    short unk_d98;
    char unk_d9a[2];
    unsigned int flags_;
    signed char lastStates_[2];
    unsigned char vocation_;
    unsigned char sex_;
    unsigned char bodyType_[2];
    unsigned char hairStyle_[2];
    unsigned char skinColor_[2];
    unsigned char eyeColor_[2];
    unsigned char face_[2];
    unsigned char hairColor_[2];
#if defined(jpn)
    char unknown_d74_[2][11];
    unsigned char unknown_d8a_[2];
    unsigned char unknown1_d8c_;
    unsigned char unknown_d8d_;
    unsigned char unknown_db6_;
    char unknown_d8f_;
#else
    char** unknown_db0_;
    unsigned char unknown_db4_;
    unsigned char unknown_db5_;
    unsigned char unknown_db6_;
    char unknown_db7_;
#endif
};

// USA: func_ov009_0218454c
extern "C" ARM void func_ov009_0218454c(Struct_ov009_021842a0_2* arg0, int arg1, int arg2)
{
    arg0->unknown_d95_ = arg2;
    if (arg0->unknown_d95_ == 1)
        func_020466e4(func_020d6c00(), 0xf);
    arg0->unknown_0_[0].ResetAllocatorPointer();
    arg0->unknown_0_[1].ResetAllocatorPointer();
    arg0->unknown_0_[2].ResetAllocatorPointer();
    arg0->unknown_0_[3].ResetAllocatorPointer();
    arg0->unknown_0_[4].ResetAllocatorPointer();
    arg0->unknown_0_[5].ResetAllocatorPointer();
    arg0->unknown_0_[6].ResetAllocatorPointer();
    arg0->unknown_0_[7].ResetAllocatorPointer();
#if !defined(jpn)
    arg0->unknown_0_[8].ResetAllocatorPointer();
#endif
    arg0->unknown_b4_ = NULL;
    arg0->unknown_b8_ = NULL;
#if !defined(jpn)
    arg0->unknown_c0_ = NULL;
    arg0->unknown_c4_ = NULL;
#endif
    func_020de848(&arg0->unknown_c8_);
    func_020dfc40(&arg0->unknown_e0_);
    arg0->unknown_f8_ = NULL;
    func_ov009_021847ec(&arg0->unknown_fc_);
    func_0204af64(&arg0->unknown_138_[0]);
    func_0204af64(&arg0->unknown_138_[1]);
    func_0204af64(&arg0->unknown_138_[2]);
    func_0204af64(&arg0->unknown_138_[3]);
    func_0204af64(&arg0->unknown_138_[4]);
    func_0204af64(&arg0->unknown_138_[5]);
    func_0205cfd4(&arg0->unknown_1f8_[0]);
    func_0205cfd4(&arg0->unknown_1f8_[1]);
    for (int var0 = 0; var0 < 1; var0++)
        func_0204c684(&arg0->unknown_370_[var0]);
    for (int var1 = 0; var1 < 4; var1++)
        func_0204c684(&arg0->unknown_450_[var1]);
    arg0->unknown_7d0_ = NULL;
    arg0->unknown_7d4_ = NULL;
    arg0->unknown_7d8_ = NULL;
    arg0->unknown_7dc_ = NULL;
    arg0->unknown_7e0_ = NULL;
    arg0->unknown_7e4_ = NULL;
    arg0->unknown_7e8_ = NULL;
    arg0->unknown_7ec_ = NULL;
    arg0->unknown_7f0_[0] = NULL;
    arg0->unknown_7f0_[1] = NULL;
    arg0->unknown_7f8_ = NULL;
    arg0->unknown_7fc_ = NULL;
    arg0->unknown_800_ = 0;
    arg0->unknown_804_ = 0;
    arg0->unknown_878_.Initialize();
    arg0->unknown_cd8_.Initialize();
    func_0205bef8(&arg0->unknown_bec_);
    func_ov009_021847c4(&arg0->unknown_c2c_);
    arg0->unknown_c4c_ = -1;
    arg0->unknown_c4e_ = -1;
    arg0->unknown_c50_ = -1;
    arg0->unknown_c52_ = -1;
    arg0->unknown_c54_ = -1;
    arg0->unknown_c56_ = -1;
    arg0->unknown_c58_ = 0;
    arg0->unknown_c59_ = 0;
    arg0->unknown_d84_ = 0;
    arg0->unknown_d85_ = 0;
    arg0->unknown_d88_ = NULL;
    arg0->unknown_d8c_ = -1;
    arg0->unknown_d90_ = 0;
    arg0->unknown_d94_ = 0;
    arg0->unknown_d96_ = 0;
    arg0->unknown_d98_ = 0;
    memset(&arg0->unknown_d9c_, 0, sizeof(arg0->unknown_d9c_));
    for (int var2 = 0; var2 < 2; var2++)
        arg0->unknown_da0_[var2] = 1;
    arg0->unknown_da2_ = arg1;
    arg0->unknown_da3_ = 0;
    for (int var3 = 0; var3 < 2; var3++)
    {
        arg0->unknown_da4_[var3] = 0;
        arg0->unknown_da6_[var3] = 0;
        arg0->unknown_da8_[var3] = 0;
        arg0->unknown_daa_[var3] = 0;
        arg0->unknown_dac_[var3] = 0;
        arg0->unknown_dae_[var3] = 0;
#if defined(jpn)
        memset(arg0->unknown_d74_[var3], 0, sizeof(arg0->unknown_d74_[var3]));
        arg0->unknown_d8a_[var3] = 0;
#endif
    }
#if defined(jpn)
    arg0->unknown1_d8c_ = 0;
    arg0->unknown_d8d_ = 0;
#else
    arg0->unknown_db0_ = NULL;
    arg0->unknown_db4_ = func_020424e4((int)data_ov009_0218aca4, 0);
#endif
    arg0->unknown_db6_ = 0;
#if defined(jpn)
    arg0->unknown_d8f_ = 0;
#endif
}
