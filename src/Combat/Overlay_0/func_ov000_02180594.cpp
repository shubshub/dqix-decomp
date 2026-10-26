#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define REGION_BASE 0x1f38
#else
#define REGION_BASE 0x1d00
#endif

extern "C" ARM int func_ov000_02180528(char* obj);

struct Struct_ov000_02180594 {
    short x;
    short y;
    unsigned short delay;
};

struct Struct_ov000_021836b0 {
    int x[7];
};

extern Struct_ov000_021836b0 data_ov000_021836b0;

struct Struct_ov000_02180594_2 {
    char pad0[0x910];
    int state;
    int timer;
    int unknown_918_;
    int unknown_91c_;
    int unknown_920_;
    int unknown_924_;
    int unknown_928_;
    int unknown_92c_;
    char unknown_930_[REGION_BASE + 0x5e - 0x930];
    short scroll;
    char unknown_1d60_[0x72 - 0x60];
    unsigned short flags;
    char unknown_1d74_[0x7c - 0x74];
    Struct_ov000_02180594* points;
};

// USA: func_ov000_02180594
extern "C" ARM int func_ov000_02180594(Struct_ov000_02180594_2* obj, int speed, SafeAllocator* allocator) {
    Struct_ov000_021836b0 offsets = data_ov000_021836b0;
    int i;
    int j;
    int k;

    if (speed <= 0) {
        speed = 1;
    }
    if (obj->state < 5 && allocator != 0 && obj->points == 0) {
        obj->points = (Struct_ov000_02180594*)allocator->Allocate(sizeof(Struct_ov000_02180594) * 7);
        for (i = 0; i < 7; i++) {
            obj->points[i].x = offsets.x[i] + 0x100;
            obj->points[i].y = 8;
            obj->points[i].delay = i * 2;
        }
        obj->flags |= 8;
    }

    if (obj->state == 0) {
        obj->timer = 0;
        obj->unknown_918_ = 0;
        obj->unknown_91c_ = 0;
        obj->state++;
        func_ov000_02180528((char*)obj);
        obj->flags |= 8;
        return 1;
    } else if (obj->state == 1) {
        obj->timer = 0;
        obj->scroll -= speed * 2;
        if (obj->scroll < 0) {
            obj->scroll = 0;
            obj->state++;
        }
        return 1;
    } else if (obj->state == 2) {
        if (obj->flags & 0x20) {
            obj->unknown_928_ -= speed * 16;
            if (obj->unknown_928_ <= 0x56) {
                obj->unknown_928_ = 0x56;
                obj->unknown_91c_ = (obj->unknown_91c_ + speed) & 0x3f;
                obj->state = 5;
            }
        } else if (obj->flags & 0x10) {
            obj->unknown_924_ -= speed * 16;
            if (obj->unknown_924_ <= 0x5c) {
                obj->unknown_924_ = 0x5c;
                obj->unknown_918_ = (obj->unknown_918_ + speed) & 0x3f;
                obj->state = 5;
            }
        } else if ((obj->flags & 8) && obj->points != 0) {
            int step = 0.0f - 1.5f * (float)(speed * 16);
            for (j = 0; j < 7; j++) {
                obj->points[j].x += step;
            }
            if (obj->points[0].x <= 0x48) {
                for (k = 0; k < 7; k++) {
                    obj->points[k].x = offsets.x[k] + 0x48;
                }
                obj->timer = 0;
                obj->state++;
            }
        }
        return 1;
    } else if (obj->state == 3) {
        if (obj->timer >= 10) {
            obj->state++;
        }
        return 1;
    } else if (obj->state == 4) {
        Struct_ov000_02180594* points = obj->points;
        if (points == 0) {
            obj->unknown_92c_ = (float)obj->unknown_92c_ - 1.5f * (float)(speed * 4);
            if (obj->unknown_92c_ < -0x20) {
                obj->state++;
            }
        } else {
            int count = 0;
            int step = 0.0f - 1.5f * (float)(speed * 4);
            for (i = 0; i < 7; i++) {
                if (speed < obj->points[i].delay) {
                    obj->points[i].delay -= speed;
                } else {
                    obj->points[i].delay = 0;
                    obj->points[i].y += step;
                }
                if (obj->points[i].y < -0x20) {
                    count++;
                }
            }
            if (count == 7) {
                obj->points = 0;
                obj->state++;
            }
            if (count > 0) {
                return 0;
            }
        }
        return 1;
    }
    obj->points = 0;
    return 0;
}
