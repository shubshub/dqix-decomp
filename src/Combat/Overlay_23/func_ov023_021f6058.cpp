#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"

extern "C" unsigned long long func_ov023_021f6324(int count, unsigned char* ptr);
extern "C" void func_ov031_022118a8(void* ctx, unsigned char* key, int arg2);
extern "C" void func_ov031_02211938(unsigned char* ctx, const unsigned char* in, int len, unsigned char* out);
extern unsigned char data_ov023_021fe3c8[];

struct ResetStruct;
struct StreamState;
struct StreamHeader;
struct Struct_0201f040_3;
extern int data_ov023_021fe34c;

struct Struct_ov023_021fff08_13 { char pad[0x8]; char* unknown_8_; char* data; };
extern struct Struct_ov023_021fff08_13 data_ov023_021fff08;

struct Struct_ov023_021f6058 {
    char pad[0x10c];
    unsigned short flags : 13;
    unsigned short unknown_10d_5_ : 3;
};

// USA: func_ov023_021f6058
extern "C" ARM int func_ov023_021f6058(unsigned char* buf, int len, unsigned char* out) {
#if defined(jpn)
 enum {regionalOffset0=0x5c0c, regionalOffset1=0x6120};
#else
 enum {regionalOffset0=0x5e6c, regionalOffset1=0x6380};
#endif
    char local[0x430];
    if (func_ov023_021f6324(len, buf) != 0) {
        return 0;
    }
    char ctx[0x104];
    char* key = (char*)data_ov023_021fe3c8;
    int var3 = strlen(key);
    func_ov031_022118a8(ctx, (unsigned char*)key, var3);
    func_ov031_02211938((unsigned char*)ctx, buf, len - 4, out);
    char* bs = (char*)GameState::GetInstance();
    Struct_ov023_021f6058* d = (Struct_ov023_021f6058*)(bs + regionalOffset0);
    buf = (unsigned char*)bs + regionalOffset1;
    data_ov023_021fff08.data = (char*)d;
    data_ov023_021fff08.unknown_8_ = (char*)buf;
    d->flags &= ~0x240;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov023_021fe34c);
    ((Script*)((struct StreamState*)local))->Load((struct StreamHeader*)out, len - 4);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
    return 1;
}
