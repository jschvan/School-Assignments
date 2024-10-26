/*******************************/
/*James Schvaneveldt            *
/*CPSC 2310 Fall 23             *
/*UserName: jschvan             *
/*Instructor: Dr. Yvon Feaster  *
/*******************************/

#include "ppmUtil.h"

int main(int argc, char** argv){
    assert(argc == 3);

    FILE* input = fopen(argv[1], "rb");
    FILE* output = fopen(argv[2], "wb");

    assert(input != NULL);
    assert(output != NULL);

    header_t img_head;
    pixel_t* pxl_ptr;

    pxl_ptr = read(input, &img_head);
    write(output, img_head, pxl_ptr);
    freeMemory(pxl_ptr);
    fclose(input);
    fclose(output);

    return 0;

}