#include "Graphics/Background.h"
// USA: Background_SetRectPalette
extern "C" void Background_SetRectPalette(BackgroundGraphics* layer,int x,int y,int width,int height,unsigned palette) {
 unsigned short (*rows)[BackgroundMap_Columns]=(unsigned short (*)[BackgroundMap_Columns])layer->map_;
 if(!rows)return;
 if(x+width<0 || y+height<0)return;
 if(x>=BackgroundMap_Columns || y>=BackgroundMap_Rows)return;
 if(palette>15)return;
 if(x<0){width=(short)(x+width);x=0;}else if(x+width>=BackgroundMap_Columns)width=(short)(BackgroundMap_Columns-x);
 if(y<0){height=height+y;height=(short)height;y=0;}else if(y+height>=BackgroundMap_Rows)height=(short)(BackgroundMap_Rows-y);
 unsigned short* row=rows[y]+x;
 palette=(unsigned short)(palette<<12);
 int j=0;
 unsigned short i;
 while(j<height) {
  i=0;
  while(i<width) {
   row[i]&=0xfff;
   row[i]|=palette;
   i=i+1;
  }
  row+=BackgroundMap_Columns;
  j=(unsigned short)(j+1);
 }
}
