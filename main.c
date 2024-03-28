#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
int pc = 0;
int registers[16] = {0x0};
int reserved = 0;
int * mem;
int * allocmem(){ 
    int * arr;
    arr = calloc(512, sizeof(int));
    return arr;
}
void dump(){
    printf("\nData Register\n");
    printf("\td%0d (x%0d) = %d\n",0,16,reserved);
    printf("Registers\n");
    for (int i = 0; i < (sizeof(registers)/sizeof(int)); i++)
        printf("\tx%0d = %d\n",i,registers[i]);
}
void readLine(FILE *fp, char to[512]){
    //TODO: Implement line for 'jmp'. Help?
    for(int i = 0; i < 512; i++){ to[i] = 0; }
    char x;
    x = fgetc(fp);
    int i = 0;
    while ((x!=EOF) && (x!='\n')){
        to[i] = x;
        x = fgetc(fp);
        i++;
    }
    to[i] = '\0';
}
void setreg(int x, int y) { 
    if (x != 16)
        registers[x] = y;
    else if(x == 16)
        reserved = y;
    else
        return;
}
int readreg(int x){ 
    if (x != 16)
        return registers[x];
    else if(x == 16)
        return reserved;
    else
        return 0;
}
int parseargs(int opcode, int args[3]){
    if(opcode == 0){ // SET r1 val
        setreg(args[0],args[1]);
        return 0;
    }
    if(opcode == 1){ // PUT r1
        printf("%c",(char)readreg(args[0]));
        return 0;
    }
    if(opcode == 2){ // LPC r1
        setreg(args[0],pc);
        return 0;
    }
    if(opcode == 3){ // ADD r1 val
        setreg(args[0],readreg(args[0])+args[1]);
        return 0;
    }
    if(opcode == 4){ // SUB r1 val
        setreg(args[0],readreg(args[0])-args[1]);
        return 0;
    }
    if(opcode == 5){ // MUL r1 val
        setreg(args[0],readreg(args[0])*args[1]);
        return 0;
    }
    if(opcode == 6){ // DIV r1 val
        setreg(args[0],readreg(args[0])/args[1]);
        return 0;
    }
    if(opcode == 7){ // DUMP r1
        printf("%d",readreg(args[0]));
        return 0;
    }
    if(opcode == 8){ // FDUMP
        dump();
        return 0;
    }
    if(opcode == 9){ // MW sec r1
        mem[args[0]] = readreg(args[1]);
        return 0;
    }
    if(opcode == 10){ // MR sec r1
        setreg(args[1],mem[args[0]]);
        return 0;
    }
}
int main(int argc, char** argv){
    mem = allocmem();
    if(mem[0] != 0){
        printf("Memory allocating failed!\n");
        exit(1);
    }
    if(!(argc > 1)){ printf("Error: %s\n","no input file."); return 1; }
    FILE *fp;
    if(!(fp = fopen(argv[1],"r"))){ printf("Error: %s\n","input file can not be opened."); return 1; }
    if(!(argc > 2 && (strcmp(argv[2],"-v") == 0))){
        printf("LunarVM v1.0 - Starting emulation.\n");
    }else{
        printf("LunarVM v1.0 - Starting emulation.");
    }
    fseek(fp,0,0);
    char buf[512];
    readLine(fp,buf);
    char *x = buf;
    char *opcodelist[11] = {"set","put","lpc","add","sub","mul","div","dump","fdump","mw","mr"}; // 'hlt' caused a bug. Removed.
    int opcodelen = sizeof(opcodelist)/sizeof(char*);
    int opcode = 0;
    int i = 0;
    int args[3];
    for(int z = 0; z < sizeof(args)/sizeof(int); z++) args[z] = 0;
    while (buf[0] != '\0'){
        char * token = strtok(x," ");
        while (token != NULL){
            i++;
            if(i == 1){
                for(int x = 0; x < opcodelen; x++){
                    if(strcmp(opcodelist[x],token) == 0){
                        opcode = x;
                    }
                }
            }else{
                int _ = atoi(token);
                args[i-2] = _;
            }
            token = strtok(NULL, " ");
        }
        i = 0;
        if(argc > 2 && (strcmp(argv[2],"-v") == 0)){
            printf("\n%d: [%d, %d, %d] PC: %d, %s\n",opcode,args[0],args[1],args[2],pc,x);
        }
        parseargs(opcode,args);
        for(int z = 0; z < sizeof(args)/sizeof(int); z++) args[z] = 0;
        pc++;
        readLine(fp,buf);
        char *x = buf;
    }
    return 0;
}