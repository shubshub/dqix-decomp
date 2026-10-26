#include <globaldefs.h>
extern "C" int func_020db2dc(int,int);
struct Struct_020db6e4 {
 unsigned int position;
 union { unsigned short value; struct { unsigned short tile:10; unsigned short mode:2; unsigned short palette:4; } fields; } unknown_4_;
 unsigned short pad;
};
// USA: func_020db6e4
extern "C" ARM void func_020db6e4(unsigned char* object, unsigned short value) {
 Struct_020db6e4* entries=(Struct_020db6e4*)func_020db2dc((int)object,object[0x3c]);
 value|=0xf800;
 for(int row=0;row<3;++row) {
  for(int col=0;col<4;++col) {
   int index=col+row*4+0x10;
   entries[index].position=0xc0000000|((row<<6)&0xff)|((unsigned)(col<<29)>>7);
   entries[index].unknown_4_.value=value;
   entries[index].unknown_4_.fields.mode=2;
  }
 }
}
