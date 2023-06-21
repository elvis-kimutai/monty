#include "monty.h"

#define MAX_LINE_LENGTH 256
int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 1;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, " \n");
	if (line[0] == '#')
	{
		line_number++;
		continue;
	}
        if (token)
        {
            if (strcmp(token, "push") == 0)
            {
                push(&stack, line_number);
            }
            else if (strcmp(token, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else if (strcmp(token, "pint") == 0)
            {
                pint(&stack, line_number);
            }
            else if (strcmp(token, "pop") == 0)
            {
                pop(&stack, line_number);
            }
            else if (strcmp(token, "add") == 0)
            {
                add(&stack, line_number);
            }
            else if (strcmp(token, "swap") == 0)
            {
                swap(&stack, line_number);
            }
            else if (strcmp(token, "nop") == 0)
            {
                nop(&stack, line_number);
            }
            else if (strcmp(token, "sub") == 0)
            {
                sub(&stack, line_number);
            }
	    else if (strcmp(token, "div") == 0)
	    {
                div_op(&stack, line_number);
            }
	    else if (strcmp(token, "mul") == 0)
	    {
		    mul_op(&stack, line_number);
	    }
	    else if (strcmp(token, "mod") == 0)
	    {
		    mod_op(&stack, line_number);
	    }
	    else if (strcmp(token, "pchar") == 0)
	    {
		    pchar(&stack, line_number);
	    }
	    else if (strcmp(token, "pstr") == 0)
	    {
		    pstr(&stack);
	    }
	    else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
                fclose(file);
                free_stack(&stack);
                return EXIT_FAILURE;
            }
        }
        line_number++;
    }

    fclose(file);
    free_stack(&stack);
    return EXIT_SUCCESS;
}
