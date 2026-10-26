#include <globaldefs.h>

struct Rect0205b1ac {
    int f0;
    short x;
    short y;
    short w;
    short h;
};

// USA: func_0205b1ac
extern "C" ARM struct Rect0205b1ac* func_0205b1ac(struct Rect0205b1ac* list, unsigned int count, int px, int arg3) {
    struct Rect0205b1ac* e = list;
    unsigned char i;
    for (i = 0; i < count; i++) {
        if (e->x <= px && px < e->x + e->w && e->y <= arg3 && arg3 < e->y + e->h) {
            return e;
        }
        e++;
    }
    return NULL;
}
