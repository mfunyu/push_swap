#include "libft/libft.h"
#include <stdio.h>

typedef struct s_params
{
    int n;
    int order;
}    t_params;

void    ft_put_list(void *content)
{
    printf("[n:");
    ft_putnbr_fd(((t_params *)content)->n, 1);
    printf(", ");
    printf("order:");
    ft_putnbr_fd(((t_params *)content)->order, 1);
    printf("]->");
}

int main()
{
    t_list * list;
    t_params    *param;

    param = (t_params *)malloc(sizeof(t_params *) * 1);
    param->n = 0;
    param->order = 1;
    list = ft_lstnew(param);
    int i = 0;
    while (i++ < 5)
    {
        param = (t_params *)malloc(sizeof(t_params *) * 1);
        param->n = i;
        param->order = i + 1;
        ft_lstadd_back(&list, ft_lstnew(param));
    }

    ft_lstiter(list, ft_put_list);
    printf("[NULL]");
    ft_lstclear(&list, free);
}
