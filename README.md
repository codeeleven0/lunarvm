# lunarvm
A simple emulated CPU.<br>
LunarVM uses an assembly-like syntax.<br>
If you want to build a compiler you need to follow this simple steps:<br>
    * Create code (Make sure it's compilable with the `-static` flag, `staticx` is not allowed.)<br>
    * Test code (I don't want to hassle with segfaults.)<br>
    * Run through `clang-format` (`main.c -> fmain.c`, see the difference.)<br>
    * Open an issue with the code<br>
    * Wait... :)<br>
If you want to extend the assembler you need to follow this simple steps:<br>
    * Create code<br>
    * Test code<br>
    * Make sure it also works with LunarVM Assembly.<br>
    * Run through `clang-format` (`main.c -> fmain.c`, see the difference.)<br>
    * Open an issue with the code<br>
    * Wait... :)<br>
If you want to create a release for Windows you need to follow this simple steps:<br>
    * Clone repo<br>
    * Enable GitHub Actions in your repo<br>
    * Create the build'n'release Action (All build numbers must be timestamped!)<br>
    * Open an issue with the Action `.yml` file<br>
    * Wait... :)<br>

# Arguments
`FILENAME` Must be argv[1]<br>
`-v` Be Verbose - must be at argv[2]<br>

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
Halt.