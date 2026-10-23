#if defined(jpn)
#define REGION(j,u) (j)
#define data_ov020_0218d95c data_ov020_0218e1ac
#define data_ov020_0218d968 data_ov020_0218e1b8
#define data_ov020_0218dc9d data_ov020_0218e55b
#else
#define REGION(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int v);
extern "C" void func_ov020_0218c7bc(int a, int b, int c, int d, int e);
extern "C" void func_ov020_0218cd64(int a, int b, int c, int d, int e);
extern "C" void Background_SetPriority(void*, int);

struct Foo0204af38;
extern "C" void Background_LoadFile(struct Foo0204af38* obj, void* data, SafeAllocator* alloc, int field44);

struct List0204af64;
void Background_Init(struct List0204af64* obj);

void Background_SetMapSize(unsigned char* obj, int value);

struct AllocTarget0204b12c;
void Background_AllocateMap(struct AllocTarget0204b12c* obj, SafeAllocator* alloc);

void Background_AllocateScreens(struct Foo0204af38* obj, int count, SafeAllocator* alloc);

struct Obj0204b5e8;
int Background_SetScroll(struct Obj0204b5e8* obj, int a, int b);

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

struct Obj0204b8d0;
void Background_DrawScreen(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
void Background_UploadMap(struct List0204b0e8* obj, void* buf);

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern "C" void func_020c39a0(short* out, int value);

extern int data_ov020_0218d95c;
extern int data_ov020_0218d968;
extern int data_ov020_0218dc9d;

struct ThreeInts_0218c98c {
    int a, b, c;
};

struct SelfLayout_0218c98c {
    char pad0[REGION(0x448, 0x4b8)];
    unsigned char bits1_lo : 4;
    unsigned char bits1_hi : 4;
    char pad1[REGION(0x468, 0x4d8) - REGION(0x449, 0x4b9)];
    unsigned char bits2_lo : 4;
    unsigned char bits2_hi : 4;
};

// USA: func_ov020_0218c98c  (semantic: RunFieldGroupInitAndDispatch_0218c98c)
extern "C" ARM void func_ov020_0218c98c(void* self) {
    char* base = (char*)self;

    ((SafeAllocator*)(base + REGION(0x400, 0x470)))->Reset();
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    Background_Init((struct List0204af64*)(base + REGION(0x42c, 0x49c)));
    Background_SetMapSize((unsigned char*)(base + REGION(0x42c, 0x49c)), 0);
    ((struct SelfLayout_0218c98c*)self)->bits1_lo = 0;
    ((struct SelfLayout_0218c98c*)self)->bits1_hi = 1;
    Background_SetPriority(base + REGION(0x42c, 0x49c), 1);
    Background_AllocateMap((struct AllocTarget0204b12c*)(base + REGION(0x42c, 0x49c)), (SafeAllocator*)(base + REGION(0x400, 0x470)));
    Background_AllocateScreens((struct Foo0204af38*)(base + REGION(0x42c, 0x49c)), 1, (SafeAllocator*)(base + REGION(0x400, 0x470)));
    Background_SetScroll((struct Obj0204b5e8*)(base + REGION(0x42c, 0x49c)), 0, 0);

    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 1, 1, 1, 0);

    Background_Init((struct List0204af64*)(base + REGION(0x44c, 0x4bc)));
    Background_SetMapSize((unsigned char*)(base + REGION(0x44c, 0x4bc)), 0);
    ((struct SelfLayout_0218c98c*)self)->bits2_lo = 1;
    ((struct SelfLayout_0218c98c*)self)->bits2_hi = 0;
    Background_SetPriority(base + REGION(0x44c, 0x4bc), 0);
    Background_AllocateMap((struct AllocTarget0204b12c*)(base + REGION(0x44c, 0x4bc)), (SafeAllocator*)(base + REGION(0x400, 0x470)));
    Background_AllocateScreens((struct Foo0204af38*)(base + REGION(0x44c, 0x4bc)), 1, (SafeAllocator*)(base + REGION(0x400, 0x470)));
    Background_SetScroll((struct Obj0204b5e8*)(base + REGION(0x44c, 0x4bc)), 0, 0);

    int handle;
    BackgroundLoader* data4 = BackgroundLoader::GetInstance();
    data4->MaybeReset();
    handle = data4->QueueLoadFile((char const*)((int)&data_ov020_0218dc9d), (SafeAllocator*)0);

    for (;;) {
        if (data4->GetTaskStatus(handle)) {
            void* dummyPtr;
            int recListHead, dummy2;
            data4->GetLoadedFileByID(handle, (void**)&recListHead, (unsigned int*)&dummy2);
            int count = Pac_CountFiles((struct ActiveEntry02046900*)recListHead);
            void* arrayC[5];
            int arrayB[5];
            for (int i = 0; i < count; i++) {
                arrayC[i] = Pac_GetFile((struct Rec020467f0*)recListHead, i, &dummyPtr, &arrayB[i]);
            }

            int idxA = 0;
            struct ThreeInts_0218c98c tbl_d95c = *(struct ThreeInts_0218c98c*)&data_ov020_0218d95c;
            struct ThreeInts_0218c98c tbl_d968 = *(struct ThreeInts_0218c98c*)&data_ov020_0218d968;
            int idxB = 0;
            for (int j = 0; j < count; j++) {
                if (j == ((int*)&tbl_d95c)[idxA]) {
                    Background_LoadFile((struct Foo0204af38*)(base + REGION(0x2c, 0x9c) + 0x400), arrayC[j], (SafeAllocator*)(base + REGION(0x400, 0x470)), arrayB[j]);
                    idxA++;
                }
                if (j == ((int*)&tbl_d968)[idxB]) {
                    Background_LoadFile((struct Foo0204af38*)(base + REGION(0x4c, 0xbc) + 0x400), arrayC[j], (SafeAllocator*)(base + REGION(0x400, 0x470)), arrayB[j]);
                    idxB++;
                }
            }

            data4->RemoveTask(handle);

            Background_DrawScreen((struct Obj0204b8d0*)(base + REGION(0x42c, 0x49c)), 0, 0, 0, 0, 0, 0x20, 0x19, 0);
            Background_DrawScreen((struct Obj0204b8d0*)(base + REGION(0x44c, 0x4bc)), 0, 0, 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((struct List0204b0e8*)(base + REGION(0x42c, 0x49c)), 0);
            Background_UploadMap((struct List0204b0e8*)(base + REGION(0x44c, 0x4bc)), 0);
            break;
        }
        data4->RemoveAllLocks();
    }

    *(short*)0x4000050 = 0;
    *(short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4001050, 1, 2, 0x1f, 0);

    *(unsigned int*)0x4000000 = (*(unsigned int*)0x4000000 & ~0x1f00) | 0x300;
    *(unsigned int*)0x4001000 = (*(unsigned int*)0x4001000 & ~0x1f00) | 0x100;
    func_020c39a0((short*)0x400006c, 0);
    func_020c39a0((short*)0x400106c, 0);
}
