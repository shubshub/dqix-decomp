extern "C" long long func_020c30ac(long long);
extern "C" long long func_020c3194(long long);
// USA: fix32_CosFx64c
extern "C" long long fix32_CosFx64c(int angle) {
 if(angle<0) return fix32_CosFx64c(-angle);
 long long var0=angle; var0*=0x145f306ddLL; var0>>=12;
 int var1=(int)(var0>>32);
 long long fraction=var0 & 0xffffffffLL;
 if(var1&1) fraction=0x100000000LL-fraction;
 long long result;
 if((var1+1)&2) result=func_020c30ac(fraction);
 else result=func_020c3194(fraction);
 if(((var1+2) & 7)>3) return -result;
 return result;
}
