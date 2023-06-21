#include "monty.h"

/**
 * pstr - Prints the string starting from the top of the stack.
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 */
void pstr(stack_t **stack)
{
	stack_t *curren = *stack;

	while (curren != NULL && curren->n != 0 && curren->n >= 0 && curren->n <= 127)
	{
		if (curren->n == 0)
			break;
		putchar(curren->n);
		curren = curren->next;
	}

	putchar('\n');
}
