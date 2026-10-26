#include <globaldefs.h>

extern "C" void func_0209c2e0(char* p, unsigned char b, unsigned short h);
extern char g_bgmPlayer;

struct Struct_ov025_021e8024 { char pad[8]; unsigned char field8; unsigned short fieldA; };

// USA: func_ov025_021e8024
extern "C" ARM int func_ov025_021e8024(struct Struct_ov025_021e8024* p) {
    func_0209c2e0(&g_bgmPlayer, p->field8, p->fieldA);
    return 1;
}
