/*******************************/
/*James Schvaneveldt            *
/*CPSC 2310 Fall 23             *
/*UserName: jschvan             *
/*Instructor: Dr. Yvon Feaster  *
/*******************************/

#include "ppmUtil.h"

void readHeader(FILE* input, header_t* header){
    //read in header info, using ckComment to move the file pointer past the comments
    fscanf(input, "%s", header->type);
    ckComment(input);
 
    fscanf(input, "%u", &header->width);
    ckComment(input);

    fscanf(input, "%u", &header->height);
    ckComment(input);

    fscanf(input, "%u\n", &header->maxVal);
}

pixel_t* readPixels(FILE* input, header_t header){
    //read in all pixels using fread and return the values
    pixel_t* pix = allocatePixMemory(header);
    fread(pix, sizeof(pixel_t), header.width * header.height, input);
    return pix;

}

void writeHeader(FILE* output, header_t header){
    //print out elements of header
    fprintf(output, "%s\n", header.type);
    fprintf(output, "%u %u\n", header.width, header.height);
    fprintf(output, "%u\n", header.maxVal);
}

void writePixels(FILE* output, pixel_t* pixels, header_t header){
    //print out pixels using fwrite
    fwrite(pixels, sizeof(pixel_t), header.width * header.height, output);
}

pixel_t* read(FILE* input, header_t* header){
    //read in input from the file for the header
    readHeader(input, header);

    //read in info for the pixels and pass it to array of pixels
    pixel_t* pix = readPixels(input, *header);

    //return the pixels read in
    return pix; 
}

void write(FILE* output, header_t header, pixel_t* pixels){
    //call writeHeader
    writeHeader(output, header);
    //call writePixels
    writePixels(output, pixels, header);
}

pixel_t* allocatePixMemory(header_t header){
    //use malloc to dynamically allocate memory for the pixel array and return the memory
    pixel_t* pix = (pixel_t*)malloc(header.height * header.width * sizeof(pixel_t));
    return pix;

}

void freeMemory(pixel_t* pixels){
    //free the allocated memory for the pixel array
    free(pixels);
}

void ckComment(FILE* fp){
    //create input character to move along file
    char input;

    //take in first character from file
    input = fgetc(fp);

    //move pointer to next line if line is empty
    while(input == ' ' || input == '\n'){
        input = fgetc(fp);
    }

    //if comment is met, move until next line
    while(input == '#'){
        while(input != '\n'){
            input = fgetc(fp);
        }
        //moves one final character
        input = fgetc(fp);
    }

    //once loop is done, put back final character removed 
    ungetc(input, fp);
    
}