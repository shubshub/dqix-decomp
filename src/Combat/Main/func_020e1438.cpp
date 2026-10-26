#include <globaldefs.h>

struct Struct_020ee958 {
    unsigned char width;
    unsigned char height;
    unsigned char pad[2];
    unsigned int attr;
};

struct Struct_020e1438 {
    unsigned int attr;
    unsigned int reserved;
    unsigned char x;
    unsigned char y;
    unsigned char width;
    unsigned char height;
};

extern Struct_020ee958 data_020ee958[];

#pragma opt_common_subs off

// USA: func_020e1438
extern "C" ARM unsigned int func_020e1438(Struct_020e1438* out, unsigned int maxCount,
                                                      unsigned int x, unsigned int arg3,
                                                      unsigned int width, unsigned int height) {
    unsigned int count;
    unsigned int y;
    unsigned char left;

    if (maxCount == 0) {
        return 0;
    }
    count = 0;
    y = 0;
    left = (unsigned char)x;

    while (y < height) {
        Struct_020ee958* best = 0;
        Struct_020ee958* e = data_020ee958;
        unsigned int i = 0;
        unsigned int remaining = height - y;

        while (i < 12) {
            if (e->width == width && e->height <= remaining) {
                best = e;
                break;
            }
            i++;
            e++;
        }

        if (best != 0) {
            out[count].x = left;
            out[count].y = (unsigned char)(y + arg3);
            out[count].width = best->width;
            out[count].height = best->height;
            out[count].attr = best->attr;
            count++;
            y += best->height;
        } else {
            unsigned int half = width >> 1;
            unsigned int rest = height - y;
            count += func_020e1438(out + count, maxCount - count, x, y, half, rest);
            count += func_020e1438(out + count, maxCount - count, x + (width >> 1), y,
                                               half, rest);
            break;
        }

        if (count >= maxCount) {
            break;
        }
    }
    return count;
}
