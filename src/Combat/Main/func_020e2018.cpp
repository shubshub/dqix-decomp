#include <globaldefs.h>
struct Struct_020e1568 { int unknown_0_, unknown_4_; unsigned char unknown_8_, unknown_9_, unknown_a_, unknown_b_; };
struct Struct_020200c0_3 { int unknown_0_; short unknown_4_, unknown_6_, unknown_8_, unknown_a_; };
struct Struct_020200c0_4 { int unknown_0_, unknown_4_; unsigned char unknown_8_; };
struct Struct_020e2018 { int unknown_0_; char unknown_4_[6]; unsigned char unknown_a_, unknown_b_; };
struct Struct_020e2018_2 {
    char unknown_0_[8];
    Struct_020e2018* unknown_8_;
    char unknown_c_[0x24-0xc];
    Struct_020e1568 unknown_24_;
    int unknown_30_, unknown_34_;
    char unknown_38_[2];
    unsigned char unknown_3a_, unknown_3b_;
};
struct Owner020e2018 { int buffer; Panel020e2018* panel; };
void ClearZeroStruct_020e1568(ZeroStruct*);
void GlyphDestinationRect_Clear(Struct02020520*);
void GlyphDestination_Clear(S_b20c*);
void GlyphDestination_SetPixels(void*, int);
void GlyphDestination_SetRects(void*, int, unsigned char);
extern "C" void Canvas_FillRect(S_b20c*, int, int, int, int, int);
// USA: func_020e2018
extern "C" ARM void func_020e2018(Owner020e2018* owner) {
    Panel020e2018* panel = owner->panel;
    Image020e2018* image = panel->image;
    ClearZeroStruct_020e1568(&panel->clipping);
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
