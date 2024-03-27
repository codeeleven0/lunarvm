.PHONY: compile produce
compile:
	@gcc main.c -I. -static -ffreestanding -static-libgcc -pie -o lunambly -Wno-all
produce:
	@./lunambly > ../out.S