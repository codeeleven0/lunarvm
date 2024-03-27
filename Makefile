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
lunambly: lunarbox.exe
	@cd lunambly && make
	@cd lunambly && ./lunambly > out.S
	@./lunarbox.exe lunambly/out.S 
lunambly-verbose: lunarbox.exe
	@cd lunambly && make
	@cd lunambly && ./lunambly > out.S
	@./lunarbox.exe lunambly/out.S -v
commit:
	@git add .
	@git commit -m "Update! (automated commit script)"
	@git pull
	@git push