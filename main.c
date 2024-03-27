#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
void * pc = (void *)0x1;
int convpc(void * pc){ return (int)(long)pc; }
int registers[16] = {0x0};
int reserved = 0;
void readLine(FILE *fp, char to[512]){
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
        setreg(args[0],convpc(pc));
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
    if(opcode == 7){ // HLT
        for(;;);
    }
}
int main(int argc, char** argv){
    if(!(argc > 1)){ printf("Error: %s\n","no input file."); return 1; }
    FILE *fp;
    if(!(fp = fopen(argv[1],"r"))){ printf("Error: %s\n","input file can not be opened."); return 1; }
    if(!(argc > 2 && (strcmp(argv[2],"-v") == 0))){
        printf("LunarVM v1.0 - Starting emulation.\n");
    }else{
        printf("LunarVM v1.0 - Starting emulation.");
    }
    char y[512];   
    readLine(fp,y);
    char * x = y; 
    char *opcodelist[8] = {"set","put","lpc","add","sub","mul","div","hlt"};
    int opcodelen = sizeof(opcodelist)/sizeof(char*);
    int opcode = 0;
    int i = 0;
    int args[3];
    for(int z = 0; z < sizeof(args)/sizeof(int); z++) args[z] = 0;
    while (y[0] != '\0'){
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
            printf("\n%d: [%d, %d, %d] PC: %p/%d\n",opcode,args[0],args[1],args[2],pc,convpc(pc));
        }
        parseargs(opcode,args);
        for(int z = 0; z < sizeof(args)/sizeof(int); z++) args[z] = 0;
        readLine(fp,y);
        char * x = y;
        pc++;
    }
}