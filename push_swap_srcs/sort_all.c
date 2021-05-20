// #include "push_swap.h"

// int	find_pivot(t_stack *stack, int len)
// {
// 	int		middle;

// 	middle = len / 2;
// 	while (middle-- && !stack->next->nil)
// 		stack = stack->next;
// 	return (stack->elem);
// }

// void	sort_stack_b(t_stack **stack_b, t_stack **stack_a, t_list **instructions,
// 											t_stack_info *info)
// {
// 	int		len_b;

// 	len_b = count_stacklst(*stack_b);
// 	if (len_b <= 3)
// 	{
// 		sort_stack(stack_b, NULL, instructions, B);
// 	}
// 	else
// 	{
// 		info->pivot = find_pivot(*stack_b, len_b);
// 		info->type = B;
// 		split_stacklst_b(stack_b, stack_a, instructions, info);
// 		sort_stack_b(stack_b, stack_a, instructions, info);
// 	}
// }

// void	sort_all(t_info *info, int len_a)
// {
// 	t_stack_info	*st_info;
// 	// t_stack			*working;

// 	st_info = malloc(sizeof(t_stack_info));
// 	st_info->pivot = find_pivot(*info->stack_a, len_a);
// 	st_info->type = A;
// 	split_stacklst(info->stack_a, info->stack_b, info, st_info);
// 	sort_stack_b(info, st_info);
// 	stack_b_push_back(info, st_info);
// 	// working = *stack_b;
// 	// while (!working->nil)
// 	// {
// 	// 	exec_add_instructions(stack_b, stack_a, instructions, pa);
// 	// 	exec_add_instructions(stack_b, stack_a, instructions, ra);
// 	// 	working = working->next;
// 	// }
// 	// print_stack(*stack_a, *stack_b, "split a2");
// 	// free(info);
// }


// ///ToDO quicksort 実装

