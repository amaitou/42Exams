
int	ft_list_size(t_list *begin_list)
{
	int i = ;
	while (begin_list)
	{
		++i;
		begin_list = begin->next;
	}
	return (i);
}
