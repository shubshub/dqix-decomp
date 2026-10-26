#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
struct Struct_ov025_021ef988_36 { char pad[4]; void* target; };
#else
struct Struct_ov025_021ef988_36 { char pad[0xc]; void* target; };
#endif
extern struct Struct_ov025_021ef988_36 data_ov025_021ef988;
extern char data_ov025_021ef87f;

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" int func_ov025_021e25a4(char* buf);
extern "C" void func_ov025_021eb05c(void* ctx, int val);

struct Struct_ov025_021e8344 { char pad[0x10]; void* unknown_10_; };
struct Struct_ov025_021e8344_2 { char pad[0x49c]; unsigned char flag : 1; };

// USA: func_ov025_021e8344
extern "C" ARM int func_ov025_021e8344(void* unused0, struct Struct_ov025_021e8344* ctx) {
#if defined(jpn)
 enum {regionalOffset0=0x144};
#else
 enum {regionalOffset0=0x150};
#endif
    char buf[0x50];
    (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54((char*)data_ov025_021ef988.target);
    GameState* bs = GameState::GetInstance();
    int id = *(unsigned short*)((char*)ctx->unknown_10_ + 0x20);
    GameObject* c = func_0200ff1c(bs, id);
    struct Struct_ov025_021e8344_2* c2 = *(struct Struct_ov025_021e8344_2**)((char*)c + regionalOffset0);
    char ch = 'm';
    if (c2->flag == 1) {
        ch = 'w';
    }
    sprintf(buf, &data_ov025_021ef87f, ch);
    int r = func_ov025_021e25a4(buf);
    func_ov025_021eb05c(data_ov025_021ef988.target, r);
    return 1;
}
