#include <globaldefs.h>
#include "Resource/Keyboard.h"

struct Struct0215efb8 {
    int key_;
    int layout_;
    int text_;
    int widthLimit_;
    int textSize_;
    int maxLength_;
    int repeatTimer_;
    unsigned short repeatDir_;
    unsigned char page_;
    unsigned char font_;
    unsigned char shift_;
    unsigned char wrap_;
    unsigned char allowAlt_;
    unsigned char allowCancel_;
    unsigned char autoRepeat_;
};

// Overlay 3, originally InitStruct0215efb8 (USA/EUR 0x0215efb8; JPN not identified)
ARM void Keyboard_Init(Struct0215efb8* keyboard) {
    keyboard->key_ = 0;
    keyboard->layout_ = 0;
    keyboard->text_ = 0;
    keyboard->widthLimit_ = 0;
    keyboard->textSize_ = 0;
    keyboard->maxLength_ = 0;
    keyboard->repeatTimer_ = 0;
    keyboard->repeatDir_ = 0;
    keyboard->page_ = KeyboardPage_Lowercase;
    keyboard->font_ = 0;
    keyboard->shift_ = 0;
    keyboard->wrap_ = 1;
    keyboard->allowAlt_ = 0;
    keyboard->allowCancel_ = 1;
    keyboard->autoRepeat_ = 1;
}
