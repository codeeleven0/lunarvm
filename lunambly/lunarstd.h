#include <stdio.h>
void lunar_printf(char* what){
    while(*what != 0){
        printf("%s %d %d\n%s %d\n","set",16,(int)*what,"put",16);
        *what++;
    }
}
void lunar_mov(int x, int y){
    printf("%s %d %d\n","set",x,y);
}
void lunar_data_set(int y){
    printf("%s %d %d\n","set",16,y);
}
void lunar_asm(char *x){
    printf("%s\n",x);
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