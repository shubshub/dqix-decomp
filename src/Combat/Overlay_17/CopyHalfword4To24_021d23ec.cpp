#include <globaldefs.h>
#include "Resource/GameResources.h"

struct SrcObj_021d23ec { unsigned char pad[4]; unsigned short h4; };
struct DstObj_021d23ec { unsigned char pad[0x24]; unsigned short h24; };

// USA: func_ov017_021d23ec
ARM void CopyHalfword4To24_021d23ec(int unused0, SrcObj_021d23ec* src, int unused2, GameResources* ov) {
	DstObj_021d23ec* dst = (DstObj_021d23ec*)ov->unknown_ptr_array_3700[3];
	dst->h24 = src->h4;
}
