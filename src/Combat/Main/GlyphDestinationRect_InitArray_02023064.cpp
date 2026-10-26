#include <globaldefs.h>

// One rectangle of a glyph destination (GlyphDestination_DrawText draws text into the rectangles' 4bpp pixels): where its
// pixels start in the buffer, and its place and size in the text area
struct Struct02020520 {
    int pixelOffset;
    short x;
    short y;
    short width;
    short height;
};

extern "C" void GlyphDestinationRect_Clear(struct Struct02020520* s);

// Fills count rectangles from the four arrays, each one's pixels following the previous one's (4bpp: w * h / 2 bytes)
// Main, originally InitWeightedEntries02023064 (USA 0x02023064, EUR 0x02023074, JPN 0x02022ae4)
extern "C" ARM void GlyphDestinationRect_InitArray(struct Struct02020520* rects, unsigned int count, short* xs, short* ys, short* widths, short* heights) {
    int pixelOffset = 0;
    unsigned int i;
    for (i = 0; i < count; i++) {
        struct Struct02020520* rect = &rects[i];
        GlyphDestinationRect_Clear(rect);
        rect->pixelOffset = pixelOffset;
        rect->x = xs[i];
        rect->y = ys[i];
        rect->width = widths[i];
        rect->height = heights[i];
        pixelOffset += (widths[i] * heights[i]) / 2;
    }
}
