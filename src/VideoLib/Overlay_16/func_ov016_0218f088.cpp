#include <globaldefs.h>

struct Struct_ov016_0218f088_2 {
	char* cursor;
	char unknown_4_[0x3b0];
	int value;
};

struct Struct_ov016_0218f088 {
	char unknown_0_[8];
	signed char tag0;
	signed char unknown_9_;
	char unknown_a_[0x2a];
	Struct_ov016_0218f088_2* stream;
	int (*advance)(Struct_ov016_0218f088_2*);
	char unknown_3c_[0x28];
	int* table;
	char unknown_68_[0x34];
	unsigned int count;
	unsigned int limit;
	#if !defined(jpn)
	int unknown_a4_;
#endif
	unsigned int wrap;
	int idx[6];
	char unknown_c4_[8];
	int unknown_cc_;
	int unknown_d0_;
};

// USA: func_ov016_0218f088
extern "C" ARM int func_ov016_0218f088(Struct_ov016_0218f088* o) {
	int adj;
	int i;

	if (o->count > o->limit) {
		return 0;
	}

	if ((*(unsigned short*)o->stream->cursor & 0x8000) != 0) {
#if !defined(jpn)
		o->unknown_a4_ = 1;
#endif
		adj = 4;
	} else {
#if !defined(jpn)
		o->unknown_a4_ = 0;
#endif
		adj = 0;
	}

	o->stream->cursor += o->advance(o->stream);

	if (o->tag0 == 0x4e && o->unknown_9_ == 0x33) {
		o->stream->cursor += adj;
	}

	o->table[o->idx[0]] = o->stream->value;

	o->unknown_cc_ = 0;
	o->unknown_d0_ = 0;

	for (i = 0; i < 6; i++) {
		o->idx[i]++;
		if (o->wrap == o->idx[i]) {
			o->idx[i] = 0;
		}
	}

	o->limit = o->limit + 1;
	return 1;
}
