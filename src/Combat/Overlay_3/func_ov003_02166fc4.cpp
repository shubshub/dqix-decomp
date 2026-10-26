#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02166fc4_804=0x20c, Enum_ov003_02166fc4_1124=0x28c, Enum_ov003_02166fc4_1213=0x2e5, Enum_ov003_02166fc4_54=0x2a, kWidth=20 };
#else
enum { Enum_ov003_02166fc4_804=0x324, Enum_ov003_02166fc4_1124=0x464, Enum_ov003_02166fc4_1213=0x4bd, Enum_ov003_02166fc4_54=0x36, kWidth=21 };
#endif
struct Struct_0204b010_2 { char pad[Enum_ov003_02166fc4_54]; short selected; short inline_ov003_02166fc4() const { return selected; } };
struct Struct_ov003_02166fc4 { char pad[0x40]; char buffer[1]; };
struct Struct_ov003_02166fc4_2 {
 char pad[Enum_ov003_02166fc4_804]; Struct_0204b010_2* model; Struct_ov003_02166fc4* background;
 char unknown_32c_[Enum_ov003_02166fc4_1124-Enum_ov003_02166fc4_804-8]; unsigned int flags;
 char unknown_468_[Enum_ov003_02166fc4_1213-Enum_ov003_02166fc4_1124-4]; unsigned char first;
};
struct BackgroundGraphics;
extern "C" void Background_ClearMap(BackgroundGraphics*, void*);
extern "C" void Background_FillRect(void*,int,int,int,int,int,int);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_FlushMap(void*,int);
// USA: func_ov003_02166fc4
extern "C" ARM void func_ov003_02166fc4(Struct_ov003_02166fc4_2* self) {
 Struct_ov003_02166fc4* bg=self->background;
 if((self->flags&0x80000) || (self->flags&0x100000) || (self->flags&0x200000) || (self->flags&0x800000)) {
  Background_ClearMap((BackgroundGraphics*)bg->buffer, 0);
  if(self->flags&0x80000) {
   Background_FillRect(bg->buffer,0,0,0,32,25,0);
   self->flags|=0x40000;self->flags&=~0x80000;
  }
  if(self->flags&0x100000) {
   Background_DrawScreen((BackgroundGraphics*)bg->buffer, 0, 0, 0, 0, 0, 32, 12, 0xffff);
   self->flags|=0x40000;self->flags&=~0x100000;
  }
  if(self->flags&0x200000) {
   Background_DrawScreen((BackgroundGraphics*)bg->buffer, 1, 0, 0, 11, 0, kWidth, 2, 0xffff);
   self->flags|=0x40000;self->flags&=~0x200000;
  }
  if(self->flags&0x400000) {
   short selected=self->model->inline_ov003_02166fc4();
   short delta=selected-self->first;
   short y=(delta%4)*2+2;
   Background_DrawScreen((BackgroundGraphics*)bg->buffer, 2, 0, 0, 2, y, 28, 2, 0xffff);
   self->flags|=0x40000;self->flags&=~0x400000;
  }
  if(self->flags&0x800000) {
   Background_DrawScreen((BackgroundGraphics*)bg->buffer, 3, 0, 0, 3, 10, 1, 2, 0xffff);
   Background_DrawScreen((BackgroundGraphics*)bg->buffer, 4, 0, 0, 28, 10, 1, 2, 0xffff);
   self->flags|=0x40000;self->flags&=~0x800000;
  }
  if(self->flags&0x40000) Background_FlushMap(bg->buffer,0);
 }
}
