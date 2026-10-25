#pragma once

#include "Graphics/Background.h"

// One pane of a window (0xe0 bytes): a text box drawn into one of the window's layers.
struct WindowPane {
    WindowPane* previous_;          // Window_SetPanes links each pane to the one before
    BackgroundGraphics* layer_;     // the window's layer it is drawn into (WindowPane_Draw)
    void* windowBuffer_;            // the window's shared buffer (WindowPane_AllocateBuffer)
    unsigned char unk_c[0xac - 0xc];
    short tileX_, tileY_;           // where WindowPane_Draw copies the pane into its layer, in tiles
    unsigned char unk_b0[8];
    unsigned short unk_b8;
    unsigned short sizeTagLineHeight_; // the line height after a <SIZE=n> tag when non-zero (func_0204cd60)
    short pixelX_, pixelY_;
    short unk_c0;
    unsigned short palette_;        // WindowPane_Draw's palette argument (Background_CopyScreenRect)
    unsigned char id_;              // what Window_SetPaneText, Window_SetPanePalette and FindElementByC40205d81c look panes up by
    unsigned char flags_;
    unsigned char unk_c6[0xd4 - 0xc6];
    void* buffer_;                  // the pane's own buffer (WindowPane_AllocateBuffer)
    unsigned char indicatorEnabled_ : 1; // the page indicator: WindowPane_SetIndicatorPage / _SetIndicatorPageCount
    unsigned char indicatorDirty_ : 1;
    unsigned char unk_d8_2_ : 6;
    unsigned char indicatorPage_;
    unsigned char indicatorPageCount_;
    unsigned char unk_db[0xe0 - 0xdb];
};

// What Window_HandleInput (and so Window_Update) returns.
enum WindowInput
{
    WindowInput_None = 0,
    WindowInput_Moved = 1,          // a tap on a cell, or the D-pad moved the selection
    WindowInput_TouchMoved = 2,     // a new touch selected a different cell than the last one
};
