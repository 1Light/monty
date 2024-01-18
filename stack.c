#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Releases a stack.
 * @stack: Pointer that points to the first stack or
 *         last queue of stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Starts stack_t stack with first
 *              stack and finalizing queue nodes.
 * @stack: Pointer that points to undeclared stack_t stack.
 *
 * Return: Error Exit if error, else Successful Exit.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Verifies wheter stack_t linked list is found
 *              within stack or queue.
 * @stack: Pointer that points to the first stack or
 *         last queue of stack_t.
 *
 * Return: When stack_t is in stack mode then return 0.
 *         When stack_t is in queue mode then return 1.
 *         else return 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
