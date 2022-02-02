TARGETS = check_ofast check_fm check_ofast_nofm check_fm_nofm check_ofast_fm_nofm

all: result.txt

check_ofast: fast_math_flags.c
	gcc -Ofast -o $@ $< -v 2>&1 | grep crtfastmath.o || true

check_fm: fast_math_flags.c
	gcc -Ofast -o $@ $< -v 2>&1 | grep crtfastmath.o || true

check_ofast_nofm: fast_math_flags.c
	gcc -Ofast -fno-fast-math -o $@ $< -v 2>&1 | grep crtfastmath.o || true

check_fm_nofm: fast_math_flags.c
	gcc -ffast-math -fno-fast-math -o $@ $< -v 2>&1 | grep crtfastmath.o || true

check_ofast_fm_nofm: fast_math_flags.c
	gcc -Ofast -ffast-math -fno-fast-math -o $@ $< -v 2>&1 | grep crtfastmath.o || true

result.txt: $(TARGETS)
	./check_ofast | tee result.txt
	./check_fm | tee -a result.txt
	./check_ofast_nofm | tee -a result.txt
	./check_fm_nofm | tee -a result.txt
	./check_ofast_fm_nofm | tee -a result.txt

clean:
	rm -f $(TARGETS) result.txt
