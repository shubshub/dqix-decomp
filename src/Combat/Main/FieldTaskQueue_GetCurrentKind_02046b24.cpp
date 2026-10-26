#include <globaldefs.h>

struct HeadNode02046b24 {
    signed char id;
};

// Main, originally GetHeadNodeIdOrMinusOne (USA 0x02046b24, EUR 0x02046b34, JPN 0x02047944)
extern "C" ARM int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj) {
    struct HeadNode02046b24* node = obj[0];
    if (node != 0) {
        return node->id;
    }
    return -1;
}
