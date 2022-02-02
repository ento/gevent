#include <stdio.h>
#include <xmmintrin.h>

// Taken from crtfastmath.c: https://github.com/gcc-mirror/gcc/blob/releases/gcc-10.3.0/libgcc/config/i386/crtfastmath.c#L25-L26
#define MXCSR_DAZ (1 << 6) /* Denormals are zero mode */
#define MXCSR_FTZ (1 << 15) /* Flush to zero mode */

int main(int argc, char *argv[]) {
  unsigned int mxcsr = _mm_getcsr();
  unsigned int daz_enabled = mxcsr & MXCSR_DAZ;
  unsigned int ftz_enabled = mxcsr & MXCSR_FTZ;
  printf("%s\n",argv[0]);
  printf("DAZ enabled: %s\n", daz_enabled ? "yes" : "no");
  printf("FTZ enabled: %s\n", ftz_enabled ? "yes" : "no");
  return 0;
}
