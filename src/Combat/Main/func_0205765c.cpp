#include <globaldefs.h>
#include "GameState/Field3b0.h"

#include "Combat/DistanceSort.h"
#include "GameState/GameState.h"

struct Struct_02057334_2;
extern "C" int func_02057854(Struct_02057334_2 *node);
struct Struct_020546c8;
extern "C" void *func_02055108(Struct_020546c8 *source);

extern "C" void func_02059a54(void *node);

struct Struct_0205765c {
    unsigned char unknown0[0x10];
    Vector3fix position;
    unsigned char unknown_1c_[0x10];
    unsigned char enabled;
    unsigned char unknown_2d_[3];
    Struct_020546c8 *source;
    Struct_0205765c *head;
    unsigned char unknown_38_;
    unsigned char unknown_39_[0x128 - 0x39];
    int unknown_128_;
    unsigned char unknown_12c_[0xc];
    float alpha;
    unsigned char unknown_13c_[0xc];
    Struct_0205765c *next;
};

struct Struct_0205765c_2 {
    unsigned char unknown0[5];
    unsigned char unknown_5_;
};

struct ViewPositionPrefix {
    int unknown0;
    Vector3fix position;
};

// USA: func_0205765c
extern "C" ARM void func_0205765c(int value) {
    Struct_0205765c *self = (Struct_0205765c *) value;
    if (func_02057854((Struct_02057334_2 *) self) && self->unknown_38_) {
        return;
    }

    Struct_0205765c_2 *source = (Struct_0205765c_2 *) func_02055108(self->source);
    if (!source->unknown_5_) {
        Struct_02056c3c entries[64];
        memset(entries, 0, sizeof(entries));
        Vector3fix viewPosition  = ((ViewPositionPrefix *) GameState::GetInstance()->GetCamera())->position;
        viewPosition.y           = 0;
        int count                = 0;
        Struct_0205765c *node = self->head;
        while (node != NULL) {
            if (!node->enabled) {
                node = node->next;
                continue;
            }
            int alpha = (int) node->alpha;
            if (alpha <= 0) {
                node = node->next;
                continue;
            }
            if (alpha > 31) {
                alpha = 31;
            }
            alpha += 31;
            if (alpha > 47) {
                alpha -= 17;
            }
            node->unknown_128_     = alpha;
            Vector3fix position     = node->position;
            position.y              = 0;
            entries[count].node     = node;
            entries[count].distance = (float) Vector3fix_Distance(&position, &viewPosition) / 4096.0f;
            node                    = node->next;
            count++;
        }
        if (count > 0) {
            func_02056c3c(self, entries, 0, count - 1);
            for (int index = 0; index < count; index++) {
                func_02059a54(entries[index].node);
            }
        }
    } else {
        Struct_0205765c *node = self->head;
        while (node != NULL) {
            if (!node->enabled) {
                node = node->next;
                continue;
            }
            func_02059a54(node);
            node = node->next;
        }
    }
}
