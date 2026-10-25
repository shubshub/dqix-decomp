#include <globaldefs.h>

struct Inner0218d618 { char pad[0x10]; int f10; };
struct Struct0218d618 { char pad[
#if defined(jpn)
0x41e8
#else
0x4498
#endif
]; Inner0218d618* f498; };

// Overlay 17, originally IsField10Eq2_0218d618 (USA/EUR 0x0218d618, JPN 0x0218e1f8)
ARM int GameResources_IsSpecialItemEffectLoaded(Struct0218d618* p) {
    Inner0218d618* q = p->f498;
    if (q == NULL) goto ret0;
    if (q->f10 == 2) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
