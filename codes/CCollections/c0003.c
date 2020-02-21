// 命令行参数

// ./a.out para1 para2 c0003.txt 5 "hello world."

#include <stdio.h>

int
main(int argc, char * argv[]){
    for (int i = 0; i < argc; ++i)
        printf("%s\n", argv[i]);
    return(0);
}

// correct out is 6 parameters:
// ./a.out para1 para2 c0003.txt 5 hello world.