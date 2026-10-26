#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void* func_ov031_0223b61c(char* path, unsigned int* outSize, int align);
extern "C" void NNS_SndInit(void*);
extern "C" void func_020bd368(void*, int);
extern "C" void NNS_SndArcPlayerSetup(int);
extern "C" void NNS_SndHandleInit(int* field);
extern "C" void func_020bbf34(int index, int value);
extern "C" void func_020bbf4c(int index, int value);
extern "C" void func_020bbf6c(int index, void* value);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_02236900(void);

extern void* data_ov031_02290d00;
extern char data_ov031_0224be60[];

// USA: func_ov031_0223677c
extern "C" ARM void func_ov031_0223677c(void) {
	data_ov031_02290d00 = func_ov031_0223cf4c(0xa0, 4);

	unsigned int size;
	void* p = func_ov031_0223b61c(data_ov031_0224be60, &size, 0x20);
	*(void**)((char*)data_ov031_02290d00 + 0x98) = p;
	NNS_SndInit(p);

	func_020bd368(data_ov031_02290d00, *(int*)((char*)data_ov031_02290d00 + 0x98));
	NNS_SndArcPlayerSetup(0);

	NNS_SndHandleInit((int*)((char*)data_ov031_02290d00 + 0x94));

	int i = 0;
	do {
		func_020bbf34(i, 0x7f);
		func_020bbf4c(i, 1);
		func_020bbf6c(i, 0);
		i++;
	} while (i < 0x20);

	void* result = func_ov031_0223e218((void*)0, (void*)func_ov031_02236900, (void*)0, 0xc8);
	*(void**)((char*)data_ov031_02290d00 + 0x9c) = result;
}
