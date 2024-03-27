# LunarVM
A simple emulated CPU.<br>
LunarVM uses an assembly-like syntax.<br>
If you want to build a compiler you need to follow these simple steps:
- Create code (Make sure it's compilable with the `-static` flag, `staticx` is not allowed.)
- Test code (I don't want to hassle with segfaults.)
- Open an issue with the code
- Wait... :)

If you want to extend the assembler you need to follow these simple steps:
- Create code
- Test code
- Make sure it also works with LunarVM Assembly.
- Run through `clang-format` (`main.c -> fmain.c`, see the difference.)
- Open an issue with the code
- Wait... :)

# Arguments
`FILENAME` Must be `argv[1]`<br>
`-v` Be Verbose - must be `argv[2]`<br>

# Instruction Set
```
set r1 val
```
Sets `r1` to `val`.<br>
```
put r1
```
Prints `r1`.<br>
```
lpc r1
```
Sets `r1` to current PC.<br>
```
add r1 val
```
`r1` = `r1` + `val`<br>
```
sub r1 val
```
`r1` = `r1` - `val`<br>
```
mul r1 val
```
`r1` = `r1` * `val`<br>
```
div r1 val
```
`r1` = `r1` / `val`<br>
```
hlt
```
Halts.

# Lunambly? What's that?
C library to produce LunarVM's `.S` files.