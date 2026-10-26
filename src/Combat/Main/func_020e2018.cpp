#include <globaldefs.h>
struct Struct_020e1568 { int pointer, value; unsigned char x, y, width, height; };
struct Struct02020520 { int pointer; short x, y, width, height; };
struct S_b20c { int pointer, layout; unsigned char mode; };
struct Struct_020e2018 { int pointer; char unknown4[6]; unsigned char width, height; };
struct Struct_020e2018_2 {
    char unknown0[8];
    Struct_020e2018* image;
    char unknownC[0x24-0xc];
    Struct_020e1568 clipping;
    int offset, stride;
    char unknown_38_[2];
    unsigned char width, height;
};
struct Struct_020e2018_3 { int buffer; Struct_020e2018_2* panel; };
extern "C" void func_020e1568(Struct_020e1568*);
extern "C" void GlyphDestinationRect_Clear(Struct02020520*);
extern "C" void GlyphDestination_Clear(S_b20c*);
extern "C" void GlyphDestination_SetPixels(void*, int);
extern "C" void GlyphDestination_SetRects(void*, int, unsigned char);
extern "C" void Canvas_FillRect(S_b20c*, int, int, int, int, int);
// USA: func_020e2018
extern "C" ARM void func_020e2018(Struct_020e2018_3* owner) {
    Struct_020e2018_2* panel = owner->panel;
    Struct_020e2018* image = panel->image;
    func_020e1568(&panel->clipping);
    panel->clipping.pointer = image->pointer;
    panel->clipping.value = 0;
    panel->clipping.x = 0;
    panel->clipping.y = 0;
    panel->clipping.width = image->width - 4;
    panel->clipping.height = image->height - 4;
    int width = owner->panel->width - 4;
    if (width <= panel->clipping.width) panel->clipping.width = width;
    int height = owner->panel->height - 4;
    if (height <= panel->clipping.height) panel->clipping.height = height;
    Struct02020520 layout;
    GlyphDestinationRect_Clear(&layout);
    layout.width = image->width;
    layout.height = image->height;
    S_b20c destination;
    GlyphDestination_Clear(&destination);
    GlyphDestination_SetPixels(&destination, owner->buffer + (owner->panel->offset + owner->panel->stride));
    GlyphDestination_SetRects(&destination, (int)&layout, 1);
    Canvas_FillRect(&destination, 0, 0, panel->clipping.width, panel->clipping.height, 1);
}
