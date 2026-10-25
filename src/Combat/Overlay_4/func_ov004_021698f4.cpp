#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#if defined(jpn)

#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov004_02169658 func_ov004_02169b80
extern "C" void* func_ov004_02168fa4(void*, int);
#endif

#if defined(jpn)
extern "C" void* func_ov004_02168fd8(void*, int);
#define TYPE1_LOOKUP func_ov004_02168fd8
#else
extern "C" void* func_ov004_02168aa0(void* arg0, int arg1);
#define TYPE1_LOOKUP func_ov004_02168aa0
#endif
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" int func_ov023_021f6f10(void* obj);
int WindowPane_IsOpen(unsigned char* obj);
extern "C" void func_ov023_021f8120(void* obj);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov023_021f6844(void* extra, int v);
struct Fields021849e0;
void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);
extern "C" void* func_ov023_021f6524(void* ctx, int value);
struct S021f9c0c;
void* ClearBuffer_021f9c0c(struct S021f9c0c* obj);
void SetByte38_021fb274(void* obj, int val);
extern "C" void func_ov004_02169658(void* a);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
struct Data02171030 {
#if defined(jpn)
 char unknown_0_[0x20];
#else
 char unknown1_0_[0x1a0];
#endif
 unsigned char field1a0; };
extern Data02171030* data_ov004_02171030;
extern struct SePlayer g_sePlayer;

// USA: func_ov004_021698f4
extern "C" ARM int func_ov004_021698f4(void* arg0) {
    int var0 = 0;
    void* var1 = TYPE1_LOOKUP(arg0, 0x1f);
    if (!var1) return 0;

#if defined(jpn)
    void* var2 = func_ov004_02168fa4(arg0, 0x15);
#else
    void* var2 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x15);
    if (!var2 || func_ov023_021f6f10(var2) != 6) var2 = 0;
#endif

    if (node2) {
        unsigned char* f20 = (unsigned char*)node2 + 0x20;
        if (f20 && WindowPane_IsOpen(f20)) {
            func_ov023_021f8120(node2);
            void* av = func_ov011_021845f8(a, 2);
            if (av) {
                func_ov023_021f6844(func_ov011_021849c8(a), 2);
                ((SafeAllocator*)((char*)av + 4))->Reset();
            }
            func_ov011_021849e0((struct Struct_ov004_02158dcc*)arg0, 0);
            void* var5 = func_ov023_021f6524(arg0, 0x64);
            if (var5) {
                func_ov023_021f9c0c((struct Struct_ov004_021698f4*)var5);
                var0 = 1;
            }
        }
    }

    func_ov023_021fb274(var1, 2);
    func_ov004_02169658(arg0);
    func_ov011_021848a0(arg0, 0x53);
    if (var0) {
        func_ov011_021849e0((struct Struct_ov004_02158dcc*)arg0, 0x64);
    }

    if (data_ov004_02171030->field1a0 != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
    }
    data_ov004_02171030->unknown_1a0_ = 0;
    return 0;
}
