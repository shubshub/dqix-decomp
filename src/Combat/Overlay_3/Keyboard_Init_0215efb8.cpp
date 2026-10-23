#include <globaldefs.h>

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
ARM void Keyboard_Init(Struct0215efb8* s) {
    s->key_ = 0;
    s->layout_ = 0;
    s->text_ = 0;
    s->widthLimit_ = 0;
    s->textSize_ = 0;
    s->maxLength_ = 0;
    s->repeatTimer_ = 0;
    s->repeatDir_ = 0;
    s->page_ = 1; // KeyboardPage lowercase
    s->font_ = 0;
    s->shift_ = 0;
    s->wrap_ = 1;
    s->allowAlt_ = 0;
    s->allowCancel_ = 1;
    s->autoRepeat_ = 1;
}
