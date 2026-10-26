#include <globaldefs.h>

struct ShortField0x22e_020968c4 {
    char pad[0x22e];
    short field;
};

// Main, originally GetShortAt0x22e (USA 0x020968c4, EUR 0x020968d4, JPN 0x02098514)
extern "C" ARM int TouchWalk_GetHeading(struct ShortField0x22e_020968c4* obj) {
    return obj->field;
}
