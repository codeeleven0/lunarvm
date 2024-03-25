.PHONY: lunarbox
lunarbox: fmain.c
	@clang fmain.c -static -static-libgcc -ffreestanding -mno-sse -mno-sse2 -pie -Wno-unused-command-line-argument -Wno-return-type -o lunarbox.exe
	pwd
fmain.c: main.c
	@clang-format main.c > fmain.c
main.c:
	@ls main.c
main.S:
	@ls main.S
run: lunarbox main.S
	@./lunarbox main.S