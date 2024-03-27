#include <stdio.h>
/*assembly implementations*/
void lunar_mov(int x, int y){
    printf("%s %d %d\n","set",x,y);
}
void lunar_data_set(int y){
    printf("%s %d %d\n","set",16,y);
}
void lunar_asm(char *x){
    printf("%s\n",x);
}
void lunar_memwrite(int x, int y){
    lunar_data_set(y);
    printf("m%s %d %d\n","w",x,16);
}
void lunar_memread(int x, int reg){
    printf("m%s %d %d\n","r",x,reg);
}
void lunar_nadd(int x, int y){
    printf("%s %d %d\n","add",x,y);
}
void lunar_nsub(int x, int y){
    printf("%s %d %d\n","sub",x,y);
}
void lunar_nmul(int x, int y){
    printf("%s %d %d\n","mul",x,y);
}
void lunar_ndiv(int x, int y){
    printf("%s %d %d\n","div",x,y);
}
void lunar_rval_dump(int r){
    printf("%s %d\n","dump",r);
}
void lunar_req_dump(){
    lunar_asm("fdump");
}
/*end assembly implementations*/
/*misc*/
void lunar_put(char x){
    int y = (int)x;
    lunar_memwrite(0,y);
    lunar_data_set(65);
    lunar_memread(0,16);
    lunar_asm("put 16");
}
void lunar_nl(){
    lunar_data_set(13);
    lunar_asm("put 16");
    lunar_data_set(10);
    lunar_asm("put 16");
}
void lunar_printf(char* what){
    while(*what != 0){
        lunar_put(*what);
        *what++;
    }
}
/*end misc*/