#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Adds together first two items of the stack_t linked list.
 * @stack: Points toawrds the top node of a given stack_t linked list.
 * @line_number: The line number presently being worked on
 *               from the Monty bytecodes file.
 *
 * Description: The returned value is kept in the second item node
 *              from the top then top item is deleted.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Subtracts the second item by the top item
 *             of the stack_t linked list.
 * @stack: Points toawrds the top node of a given stack_t linked list.
 * @line_number: The line number presently being worked on
 *               from the Monty bytecodes file.
 *
 * Description: The returned value is kept in the second item node
 *              from the top then top item is deleted.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divides the second item by the top item
 *             of the stack_t linked list.
 * @stack: Points toawrds the top node of a given stack_t linked list.
 * @line_number: The line number presently being worked on
 *               from the Monty bytecodes file.
 *
 * Description: The returned value is kept in the second item node
 *              from the top then top item is deleted.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiplies first two items of the stack_t linked list.
 * @stack: Points toawrds the top node of a given stack_t linked list.
 * @line_number: The line number presently being worked on
 *               from the Monty bytecodes file.
 *
 * Description: The returned value is kept in the second item node
 *              from the top then top item is deleted.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - works out modulus of the second item by the top item
 *             of the stack_t linked list.
 * @stack: Points toawrds the top node of a given stack_t linked list.
 * @line_number: The line number presently being worked on
 *               from the Monty bytecodes file.
 *
 * Description: The returned value is kept in the second item node
 *              from the top then top item is deleted.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
