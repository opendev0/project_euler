#ifndef __TIMING_H
#define __TIMING_H

#if defined(__i386__)

__inline__ uint64_t rdtsc(void)
{
	uint64_t x;
	__asm__ __volatile__ (".byte 0x0f, 0x31" : "=A"(x));
	return x;
}

#elif defined(__x86_64__)

__inline__ uint64_t rdtsc(void) {
	uint32_t lo, hi;
	__asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
	return static_cast<uint64_t>(hi) << 32 | lo;
}

#endif

#endif
