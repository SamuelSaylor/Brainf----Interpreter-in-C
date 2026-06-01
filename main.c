#include <stdio.h>
#include <stdlib.h>

#define TAPE_SIZE 30000 //the TAPE is basically an array of cells for the program to manipulate. we choose 30000  as the size becasue the original suggests that the tape should be 30,000

char tape[TAPE_SIZE];
int tape_pointer = 0;

int *bracket_map;

//argc is argument count. argv is the argument vector
int main(int argc, char *argv[]) {

    if(argc < 2){ printf("Usage: %s <filename>\n", argv[0]); return 1; }

    FILE *f = fopen(argv[1], "r");
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char *program = malloc(size + 1);
    fread(program, 1, size, f);
    program[size] = '\0';
    fclose(f);
    
    int cnt = 0;
    
    bracket_map = malloc(TAPE_SIZE * sizeof(int));

    while(program[cnt]){
        switch(program[cnt]){
            case '>': break; //moves cursor right
            case '<': break; //moves cursor left
            case '+': break; //increments cell value
            case '-': break; //decrements cell value
            case '.': break; //outputs cell value
            case ',': break; //inputs value into cell
            case '[': break; //start loop
            case ']': break; //end loop
        }  
        cnt++;
    }




    return 0;
}