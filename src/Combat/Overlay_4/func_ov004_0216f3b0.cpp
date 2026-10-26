#include <globaldefs.h>
#include "Resource/GameResources.h"


extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void* func_ov017_021b1d44(void* p, int a, int b);
extern "C" void FieldTask_ConnectWifi(void* a, void* b);
struct Struct_ov004_0215883c_4;
extern "C" unsigned char func_ov017_021b2060(Struct_ov004_0215883c_4* obj);
struct Struct_ov004_0215883c_3;
extern "C" unsigned char func_ov017_021b204c(Struct_ov004_0215883c_3* obj);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int id);

struct Struct_ov004_02171048_4 { char pad[4]; unsigned char* ptr; };
extern Struct_ov004_02171048_4 data_ov004_02171048;

// USA: func_ov004_0216f3b0
extern "C" ARM int func_ov004_0216f3b0(void* a) {
    void* var0 = GetGameResources();
#if defined(jpn)
    void* list = *(void**)((char*)var0 + 0x3000 + 0x4ec);
    void* five = *(void**)((char*)var0 + 0x3000 + 0x928);
#else
    void* list = *(void**)((char*)var0 + 0x3000 + 0x6fc);
    void* five = *(void**)((char*)var0 + 0x3000 + 0xb48);
#endif
    unsigned char flag = data_ov004_02171048.ptr[0x2e];

    if (flag == 0) {
        void* obj2 = func_ov011_021845f8(a, 1);
        if (!obj2) {
            func_ov011_021848a0(a, 0xd2);
            data_ov004_02171048.ptr[0x2e] = 0;
            return 0;
        }
        func_ov017_021b1d44(five, 2, 1);
        *(void**)((char*)five + 8) = (char*)obj2 + 4;
        data_ov004_02171048.ptr[0x2e]++;
        goto returnOne;
    }

    if (flag == 1) {
        FieldTask_ConnectWifi(five, list);
        if (func_ov017_021b2060((Struct_ov004_0215883c_4*)five)) {
            if (func_ov017_021b204c((Struct_ov004_0215883c_3*)five)) {
#if defined(jpn)
                if (*(int*)((char*)var0 + 0x4000 + 0x1e4) == 0) {
#else
                if (*(int*)((char*)var0 + 0x4000 + 0x494) == 0) {
#endif
                    func_ov011_021848a0(a, 0xcc);
                    return 0;
                }
            }
            if (!func_ov017_021b204c((Struct_ov004_0215883c_3*)five)) {
                func_ov011_021848a0(a, 0xc9);
                data_ov004_02171048.ptr[0x2e]++;

                void* var5 = func_ov011_021849c8(a);
                void* node = func_ov023_021f6880(var5, 0x97);
                if (node) {
                    *(unsigned char*)((char*)node + 0xc) &= ~8;
                }
                return 0;
            }
        }
    }
returnOne:
    return 1;
}
