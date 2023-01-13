
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int number;
	t_list *temp = lst;
	while (lst->next != NULL)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			number = lst->data;
			lst->data = lst->data->next;
			lst->next->data = number;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
