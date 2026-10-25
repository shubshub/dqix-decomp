#pragma once

#if defined(jpn)
extern "C" void TextQueue_Push(void *receiver, void *input, int style, int flag7, unsigned char ignoreDuplicates);
#else
extern "C" void TextQueue_Push(void *receiver, void *input, int style, int flag7, unsigned char ignoreDuplicates,
                              unsigned char flag6);
#endif
