/*******************************/
/*James Schvaneveldt            *
/*CPSC 2310 Fall 23             *
/*UserName: jschvan             *
/*Instructor: Dr. Yvon Feaster  *
/*******************************/

#ifndef PPMUTIL_H
#define PPMUTIL

#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

typedef struct Pixel
{
    unsigned char r, g, b;
}pixel_t;

typedef struct Header
{
    char type[3];
    unsigned int width;
    unsigned int height;
    unsigned int maxVal;
}header_t;

/* Parameters: input - file pointer for the input data to be read from
                header - the header struct to be read to
 * Return: void
 * this function takes in data from the input file and through pass by 
 * reference, assigns the values to the header object
 */
void readHeader(FILE* input, header_t* header);

/* Parameters: input - file pointer for the input data to be read from
                header - the header struct pull info from
 * Return: a pixel array of pixel data
 * this function takes in data from the input file and creates a pixel arary
 */
pixel_t* readPixels(FILE* input, header_t header);

/* Parameters: output - file pointer for the input data to be read from
                header - the header struct to be read from
 * Return: void
 * this function takes the header object and prints it out onto the output file
 */
void writeHeader(FILE* output, header_t header);

/* Parameters: output - file pointer for the output data to be printed to
 *             pixels - the pixel data to be printed
 *             header - the header struct to be read from to establish the size
 * Return: void
 * this function takes the pixel data and prints it out using the header info
 */
void writePixels(FILE* output, pixel_t* pixels, header_t header);

/* Parameters: input - file pointer for the input data to be read from
                header - the header struct to be read from
 * Return: a pixel array of pixel data
 * this function calls the readHeader and readPixels functions to read in info 
 */
pixel_t* read(FILE* input, header_t* header);

/* Parameters: output - file pointer for the output data to be printed to
 *              header - the header struct to be read from to establish the size     
 *              pixels - the pixel data to be printed   
 * Return: void
 * this function calls writeHeader and writePixels to print out info to output
 */
void write(FILE* output, header_t header, pixel_t* pixels);

/* Parameters: header - the header struct to be read from to establish the size     
 * Return: the allocated pixel array memory
 * this function dynamically allocates memory for the pixel data
 */
pixel_t* allocatePixMemory(header_t header);

/* Parameters: pixels - the pixel data dynmically allocated
 * Return: void
 * this function frees the dynamically allocated memory allocated 
 */
void freeMemory(pixel_t* pixels);

/* Parameters: fp - the file pointer to the input file
 * Return: void
 * this function moves the file pointer past any comments in the input file
 */
void ckComment(FILE* fp);

#endif
