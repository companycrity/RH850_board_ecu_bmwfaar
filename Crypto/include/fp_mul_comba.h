/**
*  \file
*
*  \brief       BMW Crypto Library
*
*  This file is the header file of the ECDSA algorithm of the Crypto lib
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef FP_MUL_COMBA_H
#define FP_MUL_COMBA_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Crypto_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Crypto_CHECK_VERSION(5,2,0))
#error "Version of fp_mul_comba.h does not match the version of the module!"
#endif

#if defined(TFM_PRESCOTT) && defined(TFM_SSE2)
#undef TFM_SSE2
   #define TFM_X86
#endif

/* these are the combas.  Worship them. */
#if defined(TFM_X86)
/* Generic x86 optimized code */

/* anything you need at the start */
#define COMBA_START

/* clear the chaining variables */
#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

/* forward the carry to the next digit */
#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

/* store the first sum */
#define COMBA_STORE(x) \
   x = c0;

/* store the second sum [carry] */
#define COMBA_STORE2(x) \
   x = c1;

/* anything you need at the end */
#define COMBA_FINI

/* this should multiply i and j  */
#define MULADD(i, j)                                      \
asm(                                                      \
     "movl  %6,%%eax     \n\t"                            \
     "mull  %7           \n\t"                            \
     "addl  %%eax,%0     \n\t"                            \
     "adcl  %%edx,%1     \n\t"                            \
     "adcl  $0,%2        \n\t"                            \
     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%edx","cc");

#elif defined(TFM_X86_64)
/* x86-64 optimized */

/* anything you need at the start */
#define COMBA_START

/* clear the chaining variables */
#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

/* forward the carry to the next digit */
#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

/* store the first sum */
#define COMBA_STORE(x) \
   x = c0;

/* store the second sum [carry] */
#define COMBA_STORE2(x) \
   x = c1;

/* anything you need at the end */
#define COMBA_FINI

/* this should multiply i and j  */
#define MULADD(i, j)                                      \
asm  (                                                    \
     "movq  %6,%%rax     \n\t"                            \
     "mulq  %7           \n\t"                            \
     "addq  %%rax,%0     \n\t"                            \
     "adcq  %%rdx,%1     \n\t"                            \
     "adcq  $0,%2        \n\t"                            \
     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "g"(i), "g"(j)  :"%rax","%rdx","cc");

#elif defined(TFM_SSE2)
/* use SSE2 optimizations */

/* anything you need at the start */
#define COMBA_START

/* clear the chaining variables */
#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

/* forward the carry to the next digit */
#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

/* store the first sum */
#define COMBA_STORE(x) \
   x = c0;

/* store the second sum [carry] */
#define COMBA_STORE2(x) \
   x = c1;

/* anything you need at the end */
#define COMBA_FINI \
   asm("emms");

/* this should multiply i and j  */
#define MULADD(i, j)                                     \
asm(                                                     \
    "movd  %6,%%mm0     \n\t"                            \
    "movd  %7,%%mm1     \n\t"                            \
    "pmuludq %%mm1,%%mm0\n\t"                            \
    "movd  %%mm0,%%eax  \n\t"                            \
    "psrlq $32,%%mm0    \n\t"                            \
    "addl  %%eax,%0     \n\t"                            \
    "movd  %%mm0,%%eax  \n\t"                            \
    "adcl  %%eax,%1     \n\t"                            \
    "adcl  $0,%2        \n\t"                            \
    :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","cc");

#elif defined(TFM_ARM)
/* ARM code */

#define COMBA_START

#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

#define COMBA_STORE(x) \
   x = c0;

#define COMBA_STORE2(x) \
   x = c1;

#define COMBA_FINI

#define MULADD(i, j)                                          \
asm(                                                          \
"  UMULL  r0,r1,%6,%7           \n\t"                         \
"  ADDS   %0,%0,r0              \n\t"                         \
"  ADCS   %1,%1,r1              \n\t"                         \
"  ADC    %2,%2,#0              \n\t"                         \
:"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j) : "r0", "r1", "cc");

#elif defined(TFM_PPC32)
/* For 32-bit PPC */

#define COMBA_START

#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

#define COMBA_STORE(x) \
   x = c0;

#define COMBA_STORE2(x) \
   x = c1;

#define COMBA_FINI

/* untested: will mulhwu change the flags?  Docs say no */
#define MULADD(i, j)              \
asm(                              \
   " mullw  16,%6,%7       \n\t" \
   " addc   %0,%0,16       \n\t" \
   " mulhwu 16,%6,%7       \n\t" \
   " adde   %1,%1,16       \n\t" \
   " addze  %2,%2          \n\t" \
:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"16");

#elif defined(TFM_PPC64)
/* For 64-bit PPC */

#define COMBA_START

#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

#define COMBA_STORE(x) \
   x = c0;

#define COMBA_STORE2(x) \
   x = c1;

#define COMBA_FINI

/* untested: will mulhdu change the flags?  Docs say no */
#define MULADD(i, j)              \
asm(                              \
   " mulld  r16,%6,%7       \n\t" \
   " addc   %0,%0,16       \n\t" \
   " mulhdu r16,%6,%7       \n\t" \
   " adde   %1,%1,16       \n\t" \
   " addze  %2,%2          \n\t" \
:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"r16");

#elif defined(TFM_AVR32)

/* ISO C code */

#define COMBA_START

#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

#define COMBA_STORE(x) \
   x = c0;

#define COMBA_STORE2(x) \
   x = c1;

#define COMBA_FINI

#define MULADD(i, j)             \
asm(                             \
   " mulu.d r2,%6,%7        \n\t"\
   " add    %0,r2           \n\t"\
   " adc    %1,%1,r3        \n\t"\
   " acr    %2              \n\t"\
:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"r2","r3");

#elif defined(TFM_MIPS)

#define COMBA_START

#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

#define COMBA_STORE(x) \
   x = c0;

#define COMBA_STORE2(x) \
   x = c1;

#define COMBA_FINI

#define MULADD(i, j)              \
asm(                              \
   " multu  %6,%7          \n\t"  \
   " mflo   $12            \n\t"  \
   " mfhi   $13            \n\t"  \
   " addu    %0,%0,$12     \n\t"  \
   " sltu   $12,%0,$12     \n\t"  \
   " addu    %1,%1,$13     \n\t"  \
   " sltu   $13,%1,$13     \n\t"  \
   " addu    %1,%1,$12     \n\t"  \
   " sltu   $12,%1,$12     \n\t"  \
   " addu    %2,%2,$13     \n\t"  \
   " addu    %2,%2,$12     \n\t"  \
:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"$12","$13");

#else
/* ISO C code */

#define COMBA_START

#define COMBA_CLEAR \
   c0 = c1 = c2 = 0;

#define COMBA_FORWARD \
   do { c0 = c1; c1 = c2; c2 = 0; } while (0);

#define COMBA_STORE(x) \
   x = c0;

#define COMBA_STORE2(x) \
   x = c1;

#define COMBA_FINI

#define MULADD(i, j)                                    \
   do { fp_word t;                                      \
   t = (fp_word)c0 + ((fp_word)i) * ((fp_word)j);       \
   c0 = t;                                              \
   t = (fp_word)c1 + (t >> DIGIT_BIT);                  \
   c1 = t;                                              \
   c2 += t >> DIGIT_BIT;                                \
   } while (0);

#endif

#endif /* FP_MUL_COMBA_H */
