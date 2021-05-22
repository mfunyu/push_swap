#include "utils.h"

void	null_free(void **elem)
{
	if (!elem || !*elem)
		return ;
	free(*elem);
	*elem = NULL;
}
