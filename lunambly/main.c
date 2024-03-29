#include <lunarstd.h>
/*
* Copyright (C) 2024 - Mustafa E
* This project is licenced under GNU GPLv3!
*/
int main(){
    for(int i = 0; i < 10; i++){
        lunar_mov(i,i);
        lunar_nadd(i,48);
        lunar_put_reg(i);
        lunar_nl();
    }
    lunar_req_dump();
    lunar_printf("Hello, World!");
    lunar_nl();
    lunar_input("[LunarVM Input] ",16);
    lunar_cpy(13,16);
    lunar_printf("You entered ");
    lunar_put('"');
    lunar_put_reg(13);
    lunar_put('"');
    lunar_put('.');
    lunar_nl();
    /*
    * I will add a simple comparison thingy.
    * I don't know whether it'll work but gonna try.
    */
    return 0; // make is quiet now
}