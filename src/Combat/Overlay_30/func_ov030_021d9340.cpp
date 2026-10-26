#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov015_0218b5a0(void);
struct GameResources;
void InitializeBrightnessState(GameResources*);
unsigned int EnableSpecificInterrupts(unsigned int mask);
struct Struct_02054280;
extern "C" void func_02054280(Struct_02054280*);
extern "C" void SprSprite_Init(void* obj);
extern "C" void func_ov017_0219a674(unsigned char*);
extern "C" void MapDisplay_Init(void* obj);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void func_ov017_0218b664(char* base);
struct Struct_02046958;
extern "C" void func_02046958(Struct_02046958*);
extern "C" void func_ov017_021a124c(void* obj);
extern "C" void FieldTask_InitEnterZone(unsigned char*, int);
extern "C" void func_ov017_021b8d1c(void* obj);
extern "C" void func_ov017_021b6f18(void* obj);
extern "C" void func_ov017_021a5568(void* obj);
extern "C" void func_ov017_021bf410(void* obj);
struct Struct_ov017_021b8c70;
extern "C" void func_ov017_021b8c70(Struct_ov017_021b8c70*);
extern "C" void func_ov017_021bac58(void* obj);
struct Struct_ov017_0219bfb4;
extern "C" void func_ov017_021ba90c(Struct_ov017_0219bfb4*);
struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c*);
extern "C" void func_ov017_021baedc(void* obj, int flag);
extern "C" void func_ov017_021b2c4c(void* obj);
extern "C" void func_ov017_021b2f64(unsigned char*);
struct Struct_ov017_0219dc90_3;
extern "C" void func_ov017_021b46d8(Struct_ov017_0219dc90_3*);
extern "C" void FieldTask_InitSearchPot(void* obj);
struct Struct_ov017_021aa3f4;
extern "C" void func_ov017_021aa3f4(Struct_ov017_021aa3f4*);
struct Struct_ov017_021aa4cc;
extern "C" void func_ov017_021aa50c(Struct_ov017_021aa4cc*);
struct Struct_ov017_021ab250;
extern "C" void func_ov017_021ab250(Struct_ov017_021ab250*);
struct Obj021abb68;
extern "C" void func_ov017_021abb68(Obj021abb68*, unsigned char);
struct Struct_ov017_0219931c;
extern "C" void func_ov017_021ac2ec(Struct_ov017_0219931c*);
struct Struct_ov017_021c0124;
extern "C" void func_ov017_021c0124(Struct_ov017_021c0124*, unsigned char);
extern "C" void func_ov017_021acd7c(void* obj);
struct OpenChestTask;
extern "C" void FieldTask_InitOpenChest(OpenChestTask*);
struct Obj021ae800;
extern "C" void func_ov017_021ae800(Obj021ae800*);
struct Struct_ov003_02164400;
extern "C" void func_ov017_021aeedc(Struct_ov003_02164400*);
extern "C" void func_ov017_021af59c(void* obj);
struct Struct021b11b0;
extern "C" void func_ov017_021b11b0(Struct021b11b0*);
struct Struct_ov017_021c0334;
extern "C" void func_ov017_021c0334(Struct_ov017_021c0334*);
extern "C" void func_ov017_021c0760(unsigned char*, unsigned char);
struct Struct_ov017_021b146c;
extern "C" void func_ov017_021b14a0(Struct_ov017_021b146c*);
extern "C" void func_ov017_021b1d44(void* obj, int size, int flag);
extern "C" void func_ov017_021b2174(unsigned char*);
struct Struct_ov017_021c12fc;
extern "C" void func_ov017_021c1350(Struct_ov017_021c12fc*, unsigned char, unsigned char);
extern "C" void func_ov017_021c17cc(void* obj);
extern "C" void func_ov017_021c16a8(unsigned char*);
struct Struct_ov017_021b61e4;
extern "C" void func_ov017_021b61e4(Struct_ov017_021b61e4*);
extern "C" void func_ov017_021bdbf0(unsigned char*);
extern "C" void func_ov017_021be0a0(unsigned char*);
extern "C" void FieldTask_InitAcquireTreasureMap(void* obj, int flag);
extern "C" void func_ov017_021beba4(char*);
struct Struct_ov017_021befe4;
extern "C" void func_ov017_021befe4(Struct_ov017_021befe4*);
struct Struct_02061c04_8;
extern "C" void func_ov017_021aa16c(Struct_02061c04_8*);
struct Struct_ov017_021913d0;
extern "C" void func_ov017_021c1e40(Struct_ov017_021913d0*);
extern "C" void func_ov017_021c2688(unsigned char*);
struct WhistleTask;
extern "C" void FieldTask_InitWhistle(WhistleTask*);
extern "C" void func_ov017_021c2b28(void* obj, unsigned char a, unsigned char b);
struct Struct_ov017_02192700_2;
extern "C" void func_ov017_021c316c(Struct_ov017_02192700_2*, int);
extern "C" void func_ov017_021a967c(void* obj, int flag);
struct Struct_02061c04_15;
extern "C" void func_020d9dec(Struct_02061c04_15*, int);
struct Struct_020dac40_2;
extern "C" void func_020dac68(Struct_020dac40_2*);
struct Struct020d9850;
extern "C" void func_020d9850(Struct020d9850*);
struct Obj020d8080;
extern "C" void func_020d8080(Obj020d8080*);
struct Struct_020dbc5c;
extern "C" void func_020dbc9c(Struct_020dbc5c*);
struct CombatState020e3c34;
extern "C" void func_020e3c34(CombatState020e3c34*);
struct Struct_ov017_021be40c;
extern "C" void func_ov017_021be40c(Struct_ov017_021be40c*);
extern "C" void func_ov017_021996fc(unsigned char* base);
extern "C" void func_ov017_021a5b48(unsigned char* base);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void func_ov017_021941ec(unsigned char*);
extern "C" void func_ov017_02191b70(void* obj);

// USA: func_ov030_021d9340
extern "C" ARM void func_ov030_021d9340(GameResources* arg0) {
    unsigned char* self = (unsigned char*)arg0;
    func_ov015_0218b5a0();
    InitializeBrightnessState(arg0);

    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short old = *ime;
    (void)old;
    *ime = 1;
    EnableSpecificInterrupts(8);
    GameState::GetInstance();

    *(int*)(self + 0x2c) = 0;
    *(int*)(self + 0x30) = 0;
    *(int*)(self + 0x34) = 0;
    for (int i = 0; i < R(0x1d, 0x21); i++) {
        ((SafeAllocator*)(self + 0x38 + i * 0x14))->ResetAllocatorPointer();
    }
    ((SafeAllocator*)(self + R(0xf2c, (0x1000 + 0x13c))))->ResetAllocatorPointer();
    ((SafeAllocator*)(self + R(0xfb0, 0x11c0)))->ResetAllocatorPointer();
    ((SafeAllocator*)(self + R(0x1034, (0x1000 + 0x244))))->ResetAllocatorPointer();
    for (int i = 0; i < 4; i++) {
        func_02054280((Struct_02054280*)(self + R(0x10b8, (0x1000 + 0x2c8)) + i * 0x5ec));
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 0xb; j++) {
            signed char* row = (signed char*)self + i * 0xb;
            *(row + j + R(0x41ac, (0x4000 + 0x45c))) = -1;
        }
    }

    *(int*)(self + R(0x4188, (0x4000 + 0x438))) = 0;
    *(int*)(self + R(0x418c, (0x4000 + 0x43c))) = 0;
    *(int*)(self + R(0x4190, (0x4000 + 0x440))) = 0;
    *(int*)(self + R(0x28f8, (0x2000 + 0xb08))) = -1;
    ((SafeAllocator*)(self + R(0x28fc, (0x2000 + 0xb0c))))->ResetAllocatorPointer();

    for (int i = 0; i < 0x12; i++) {
        SprSprite_Init(self + R(0x2980, (0x2000 + 0xb90)) + i * 0x88);
    }
    SprSprite_Init(self + R(0x3310, (0x3000 + 0x520)));
    SprSprite_Init(self + R(0x3398, (0x3400 + 0x1a8)));

    *(int*)(self + R(0x3420, (0x3000 + 0x630))) = 0;
    for (int i = 0; i < 0x12; i++) {
        unsigned char* slot = self + i;
        slot[R(0x3424, (0x3000 + 0x634))] = 0;
        slot[R(0x3436, (0x3000 + 0x646))] = 0;
        slot[R(0x3448, (0x3000 + 0x658))] = 0;
        *(int*)(self + R(0x345c, (0x3000 + 0x66c)) + i * 4) = 0;
    }

    func_ov017_0219a674((unsigned char*)(self + R(0x34a4, (0x3400 + 0x2b4))));
    ((Model3D*)(*(void**)(self + R(0x34b8, (0x3000 + 0x6c8)))))->Clear();
    ((Object3D*)(*(void**)(self + R(0x34bc, (0x3000 + 0x6cc)))))->Initialize();
    self[R(0x4111, (0x4000 + 0x331))] = 0;
    MapDisplay_Init(*(void**)(self + R(0x34c0, (0x3000 + 0x6d0))));

    *(int*)(self + R(0x34c4, (0x3000 + 0x6d4))) = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char* entry = self + i * R(0xc, 0x30);
        entry[R(0x413c, (0x4000 + 0x35c))] = 0;
    }

    VectorizedMemset(self + R(0x34cc, (0x3400 + 0x2dc)), 0, 5);
    VectorizedMemset(self + R(0x34d1, (0x3600 + 0xe1)), 0, 9);
    Background_Init((BackgroundGraphics*)(*(void**)(self + R(0x34c8, (0x3000 + 0x6d8)))));

    *(int*)(self + R(0x34dc, (0x3000 + 0x6ec))) = -1;
    *(int*)(self + R(0x34e0, (0x3000 + 0x6f0))) = 0;
    *(int*)(self + R(0x34e4, (0x3000 + 0x6f4))) = 0;
    *(int*)(self + R(0x34e8, (0x3000 + 0x6f8))) = 0;
    *(int*)(self + R(0x41dc, (0x4000 + 0x48c))) = 0;
    self[R(0x41e0, (0x4000 + 0x490))] = 0;
    func_ov017_0218b664((char*)self);

    *(signed char*)(self + R(0x4196, (0x4000 + 0x446))) = -1;
    for (int i = 0; i < 4; i++) {
        *(short*)(self + R(0x419a, (0x4400 + 0x4a)) + i * 2) = 0;
    }

    *(int*)(self + R(0x41a4, (0x4000 + 0x454))) = 0x24;
    *(int*)(self + R(0x41a8, (0x4000 + 0x458))) = 1;
    self[R(0x41d8, (0x4000 + 0x488))] = 0;
    self[R(0x41d9, (0x4000 + 0x489))] = 1;
    self[R(0x41da, (0x4000 + 0x48a))] = 0;

    func_02046958((Struct_02046958*)(*(void**)(self + R(0x34ec, (0x3000 + 0x6fc)))));
    func_02046958((Struct_02046958*)(*(void**)(self + R(0x34f0, (0x3000 + 0x700)))));
    func_02046958((Struct_02046958*)(*(void**)(self + R(0x34f4, (0x3000 + 0x704)))));
    func_ov017_021a124c(*(void**)(self + R(0x34f8, (0x3000 + 0x708))));
    FieldTask_InitEnterZone((unsigned char*)(*(void**)(self + R(0x34fc, (0x3000 + 0x70c)))), 1);
    func_ov017_021b8d1c(*(void**)(self + R(0x3500, (0x3000 + 0x710))));
    func_ov017_021b6f18(*(void**)(self + R(0x3508, (0x3000 + 0x718))));
    func_ov017_021a5568(*(void**)(self + R(0x350c, (0x3000 + 0x71c))));
    func_ov017_021bf410(*(void**)(self + R(0x3510, (0x3000 + 0x720))));
    func_ov017_021b8c70((Struct_ov017_021b8c70*)(*(void**)(self + R(0x3514, (0x3000 + 0x724)))));
    func_ov017_021bac58(*(void**)(self + R(0x3518, (0x3000 + 0x728))));
    func_ov017_021ba90c((Struct_ov017_0219bfb4*)(*(void**)(self + R(0x351c, (0x3000 + 0x72c)))));

    func_0204693c((ByteHeader0204693c*)(*(void**)(self + R(0x3520, (0x3000 + 0x730)))));
    **(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) = 0x11;
    *(int*)(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 8) = 0;
    ((SafeAllocator*)(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 0xc))->ResetAllocatorPointer();
    *(int*)(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 0x20) = 0;
    *(*(unsigned char**)(self + R(0x3520, (0x3000 + 0x730))) + 0x24) = 0xff;

    func_ov017_021baedc(*(void**)(self + R(0x3524, (0x3000 + 0x734))), 0);
    func_ov017_021b2c4c(*(void**)(self + R(0x3528, (0x3000 + 0x738))));

    for (int i = 0; i < 0xc; i++) {
        func_ov017_021b2f64((unsigned char*)(self + R(0x352c, (0x3400 + 0x33c)) + i * 0x48));
    }
    for (int i = 0; i < 4; i++) {
        func_ov017_021b46d8((Struct_ov017_0219dc90_3*)(self + R(0x388c, (0x3800 + 0x29c)) + i * R(0x14, 0x18)));
    }

    FieldTask_InitSearchPot(*(void**)(self + R(0x38dc, (0x3000 + 0xafc))));

    func_0204693c((ByteHeader0204693c*)(*(void**)(self + R(0x38e0, (0x3000 + 0xb00)))));
    **(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) = 0x17;
    *(int*)(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x24) = 0;
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1f) = 0;
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1c) = 0;
    ((SafeAllocator*)(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 8))->ResetAllocatorPointer();
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1d) = 0;
    *(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x1e) = 0xff;
    *(signed char*)(*(unsigned char**)(self + R(0x38e0, (0x3000 + 0xb00))) + 0x20) = -1;

    func_0204693c((ByteHeader0204693c*)(*(void**)(self + R(0x38e4, (0x3000 + 0xb04)))));
    **(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) = 0x18;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0x20) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0x1c) = 0;
    *(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xb4) = 0;
    ((SafeAllocator*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 8))->ResetAllocatorPointer();
    *(unsigned short*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xa0) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xa4) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xa8) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xac) = 0;
    *(int*)(*(unsigned char**)(self + R(0x38e4, (0x3000 + 0xb04))) + 0xb0) = 0;

    func_ov017_021aa3f4((Struct_ov017_021aa3f4*)(*(void**)(self + R(0x38e8, (0x3000 + 0xb08)))));
    func_ov017_021aa50c((Struct_ov017_021aa4cc*)(*(void**)(self + R(0x38ec, (0x3000 + 0xb0c)))));
    func_ov017_021ab250((Struct_ov017_021ab250*)(*(void**)(self + R(0x38f0, (0x3000 + 0xb10)))));
    func_ov017_021abb68((Obj021abb68*)(*(void**)(self + R(0x38f4, (0x3000 + 0xb14)))), 0);
    func_ov017_021ac2ec((Struct_ov017_0219931c*)(*(void**)(self + R(0x38f8, (0x3000 + 0xb18)))));
    func_ov017_021c0124((Struct_ov017_021c0124*)(*(void**)(self + R(0x38fc, (0x3000 + 0xb1c)))), 0);
    func_ov017_021acd7c(*(void**)(self + R(0x3900, (0x3000 + 0xb20))));
    FieldTask_InitOpenChest((OpenChestTask*)(*(void**)(self + R(0x3904, (0x3000 + 0xb24)))));
    func_ov017_021ae800((Obj021ae800*)(*(void**)(self + R(0x3908, (0x3000 + 0xb28)))));
    func_ov017_021aeedc((Struct_ov003_02164400*)(*(void**)(self + R(0x390c, (0x3000 + 0xb2c)))));
    func_ov017_021af59c(*(void**)(self + R(0x3910, (0x3000 + 0xb30))));
    func_ov017_021b11b0((Struct021b11b0*)(*(void**)(self + R(0x3914, (0x3000 + 0xb34)))));
    func_ov017_021c0334((Struct_ov017_021c0334*)(*(void**)(self + R(0x3918, (0x3000 + 0xb38)))));
    func_ov017_021c0760((unsigned char*)(*(void**)(self + R(0x391c, (0x3000 + 0xb3c)))), 1);

    func_0204693c((ByteHeader0204693c*)(*(void**)(self + R(0x3920, (0x3000 + 0xb40)))));
    **(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) = 0x2a;
    *(int*)(*(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) + 0xc) = 0;
    *(int*)(*(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) + 0x10) = 0;
    unsigned char* var16 = *(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40)));
    var16[0x3a] = 0;
    var16[0x3b] = 0;
    *(*(unsigned char**)(self + R(0x3920, (0x3000 + 0xb40))) + 0x28) = 0xff;

    func_ov017_021b14a0((Struct_ov017_021b146c*)(*(void**)(self + R(0x3924, (0x3000 + 0xb44)))));
    func_ov017_021b1d44(*(void**)(self + R(0x3928, (0x3000 + 0xb48))), 0x40, 1);
    *(*(unsigned char**)(self + R(0x3928, (0x3000 + 0xb48))) + 0x33) = R(5, 8);
    func_ov017_021b2174((unsigned char*)(*(void**)(self + R(0x392c, (0x3000 + 0xb4c)))));
    func_ov017_021c1350((Struct_ov017_021c12fc*)(*(void**)(self + R(0x3930, (0x3000 + 0xb50)))), 0, 0);
    func_ov017_021c17cc(*(void**)(self + R(0x3934, (0x3000 + 0xb54))));
    func_ov017_021c16a8((unsigned char*)(*(void**)(self + R(0x3938, (0x3000 + 0xb58)))));
    func_ov017_021b61e4((Struct_ov017_021b61e4*)(*(void**)(self + R(0x393c, (0x3000 + 0xb5c)))));
    func_ov017_021bdbf0((unsigned char*)(*(void**)(self + R(0x3940, (0x3000 + 0xb60)))));
    func_ov017_021be0a0((unsigned char*)(*(void**)(self + R(0x3944, (0x3000 + 0xb64)))));
    FieldTask_InitAcquireTreasureMap(*(void**)(self + R(0x3948, (0x3000 + 0xb68))), 0);
    func_ov017_021beba4((char*)(*(void**)(self + R(0x394c, (0x3000 + 0xb6c)))));
    func_ov017_021befe4((Struct_ov017_021befe4*)(*(void**)(self + R(0x3950, (0x3000 + 0xb70)))));

    func_0204693c((ByteHeader0204693c*)(*(void**)(self + R(0x3954, (0x3000 + 0xb74)))));
    **(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) = 0x36;
    *(unsigned short*)(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 8) = 0;
    *(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xa) = 0;
    *(short*)(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xc) = -1;
    *(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xe) = 0;
    *(*(unsigned char**)(self + R(0x3954, (0x3000 + 0xb74))) + 0xf) = 0;

    func_ov017_021aa16c((Struct_02061c04_8*)(*(void**)(self + R(0x3968, (0x3000 + 0xb88)))));
    func_ov017_021c1e40((Struct_ov017_021913d0*)(*(void**)(self + R(0x3980, (0x3000 + 0xba0)))));
    func_ov017_021c2688((unsigned char*)(*(void**)(self + R(0x3988, (0x3000 + 0xba8)))));
    FieldTask_InitWhistle((WhistleTask*)(*(void**)(self + R(0x398c, (0x3000 + 0xbac)))));
    func_ov017_021c2b28(*(void**)(self + R(0x3990, (0x3000 + 0xbb0))), 0, 0);
    func_ov017_021c316c((Struct_ov017_02192700_2*)(*(void**)(self + R(0x3994, (0x3000 + 0xbb4)))), 0);
    func_ov017_021a967c(*(void**)(self + R(0x3964, (0x3000 + 0xb84))), 0);
    func_020d9dec((Struct_02061c04_15*)(*(void**)(self + R(0x399c, (0x3000 + 0xbbc)))), 1);
    func_020dac68((Struct_020dac40_2*)(*(void**)(self + R(0x39a4, (0x3000 + 0xbc4)))));
    func_020d9850((Struct020d9850*)(*(void**)(self + R(0x3998, (0x3000 + 0xbb8)))));
    func_020d8080((Obj020d8080*)(*(void**)(self + R(0x3984, (0x3000 + 0xba4)))));

    for (int i = 0; i < 3; i++) {
        func_020dbc9c((Struct_020dbc5c*)(self + R(0x39a8, (0x3800 + 0x3c8)) + i * 0x14));
    }
    for (int i = 0; i < 4; i++) {
        func_020e3c34((CombatState020e3c34*)(self + R(0x39e4, (0x3c00 + 4)) + i * 0x28));
    }

    func_ov017_021be40c((Struct_ov017_021be40c*)(*(void**)(self + R(0x3a84, (0x3000 + 0xca4)))));
    func_ov017_021996fc(self);
    func_ov017_021a5b48(self);

    self[R(0x40c0, (0x4000 + 0x2e0))] = 2;
    self[R(0x40c1, (0x4000 + 0x2e1))] = 0;
    self[R(0x40c4, (0x4000 + 0x2e4))] = 0;
    self[R(0x40ca, (0x4000 + 0x2ea))] = 0;
    *(unsigned short*)(self + R(0x40cc, (0x4200 + 0xec))) = 0;
    *(unsigned short*)(self + R(0x40ce, (0x4200 + 0xee))) = 0;
    self[R(0x40d0, (0x4000 + 0x2f0))] = 0;
    memset(self + R(0x40d1, (0x4200 + 0xf1)), 0, 0x2d);

    self[R(0x40fe, (0x4000 + 0x31e))] = 0;
    *(int*)(self + R(0x4100, (0x4000 + 0x320))) = 1;
    *(int*)(self + R(0x4104, (0x4000 + 0x324))) = 0;
    *(signed char*)(self + R(0x410c, (0x4000 + 0x32c))) = -1;
    for (int i = 0; i < 3; i++) {
        signed char* extra = (signed char*)self + i;
        extra[R(0x410d, (0x4000 + 0x32d))] = -1;
    }

    self[R(0x4110, (0x4000 + 0x330))] = 0;
    *(int*)(self + R(0x4114, (0x4000 + 0x334))) = 0;
    *(int*)(self + R(0x4118, (0x4000 + 0x338))) = 0;
    *(int*)(self + R(0x411c, (0x4000 + 0x33c))) = 0;
    *(int*)(self + R(0x4120, (0x4000 + 0x340))) = 0;
    self[R(0x41e1, (0x4000 + 0x491))] = 0;
    self[R(0x40c7, (0x4000 + 0x2e7))] = 0;
    self[R(0x40c8, (0x4000 + 0x2e8))] = 0;
    *(int*)(self + R(0x41e4, (0x4000 + 0x494))) = 0;
    *(int*)(self + R(0x4128, (0x4000 + 0x348))) = 0;
    *(int*)(self + R(0x412c, (0x4000 + 0x34c))) = 0;
    *(int*)(self + R(0x4130, (0x4000 + 0x350))) = 0;
    self[R(0x40c9, (0x4000 + 0x2e9))] = 0;
    self[R(0x4134, (0x4000 + 0x354))] = 0;
    self[R(0x40c2, (0x4000 + 0x2e2))] = 0;
    self[R(0x40c3, (0x4000 + 0x2e3))] = 0;
    *(int*)(self + R(0x4124, (0x4000 + 0x344))) = 0;
    *(int*)(self + R(0x41e8, (0x4000 + 0x498))) = 0;
    func_ov017_021941ec((unsigned char*)(*(void**)(self + R(0x416c, (0x4000 + 0x41c)))));

    self[R(0x4170, (0x4000 + 0x420))] = 1;
    self[R(0x4171, (0x4000 + 0x421))] = 0;
    *(unsigned short*)(self + R(0x4172, (0x4400 + 0x22))) = 0;
    *(unsigned short*)(self + R(0x4174, (0x4400 + 0x24))) = 0;
    *(int*)(self + R(0x4178, (0x4000 + 0x428))) = -1;
    self[R(0x417c, (0x4000 + 0x42c))] = 0;
    self[R(0x417d, (0x4000 + 0x42d))] = 0;
    self[R(0x417e, (0x4000 + 0x42e))] = 0;
    *(short*)(self + R(0x4180, (0x4400 + 0x30))) = -1;
    self[R(0x417f, (0x4000 + 0x42f))] = 0;
    *(int*)(self + R(0x4184, (0x4000 + 0x434))) = 0;
    self[R(0x4182, (0x4000 + 0x432))] = 2;
    self[R(0x40c5, (0x4000 + 0x2e5))] = 0;
    self[R(0x4135, (0x4000 + 0x355))] = 0;
    func_ov017_02191b70(self);
    *(unsigned short*)(self + R(0x41fc, (0x4400 + 0xac))) = 0;
}
