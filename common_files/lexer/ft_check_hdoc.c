#include "../../header.h"

//Valid here doc delimiter
int	ft_valid_hd_delim(t_token *lst)
{
	if (lst)
		return (lst->type == WORD || \
		lst->type == WORD || lst->type == WORD);
	return (ERR);
}

//Check for the here doc delimiter
int	ft_check_hdoc(t_token *lst)
{
	int	i;

	if (lst && lst->prev)
	{
		if (ft_getlast(lst)->type == HDOC)
			return (ERR);
		while (lst && lst->type != HDOC)
			lst = lst->prev;
		if (lst->type == HDOC && ft_valid_hd_delim(lst->prev))
			return (SUCC);
		ft_check_hdoc(lst);
	}
	return (ERR);
}
