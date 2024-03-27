.PHONY: lunarbox.exe
lunarbox.exe: main.c
	@gcc main.c -static -static-libgcc -ffreestanding -mno-sse -mno-sse2 -pie -Wno-unused-command-line-argument -Wno-return-type -o lunarbox.exe
	pwd
main.c:
	@ls main.c
main.S:
	@ls main.S
run: lunarbox.exe main.S
	@./lunarbox.exe main.S
verbose: lunarbox.exe main.S
	@./lunarbox.exe main.S -v