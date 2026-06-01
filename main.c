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
    
    bracket_map = malloc(size * sizeof(int));
    int *stack = malloc(size * sizeof(int));
    int stack_pointer = 0;
    for(int i = 0; i < size; i++){
        if(program[i] == '['){
            stack[stack_pointer++] = i; //in python terms im basically appending here
        }else if (program[i] == ']'){
            int new_point = stack[--stack_pointer]; //and ther eright here im popping
            bracket_map[new_point] = i;
            bracket_map[i] = new_point;
        }
    }
    free(stack);

    int cnt = 0;
    while(program[cnt]){
        switch(program[cnt]){
            case '>': tape_pointer++;                                 break; //moves cursor right
            case '<': tape_pointer--;                                 break; //moves cursor left
            case '+': tape[tape_pointer]++;                           break; //increments cell value
            case '-': tape[tape_pointer]--;                           break; //decrements cell value
            case '.': putchar(tape[tape_pointer]);                    break; //outputs cell value
            case ',': tape[tape_pointer] = getchar();                 break; //inputs value into cell
            case '[': if(!tape[tape_pointer]) cnt = bracket_map[cnt]; break; //start loop
            case ']': if(tape[tape_pointer]) cnt = bracket_map[cnt];  break; //end loop

            //yes i felt fancy and evened out the break for aesthetic affects
        }  
        cnt++;
    }

    return 0;

}