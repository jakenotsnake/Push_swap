/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:17:08 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/15 12:19:12 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_arrays	*s;

	s = (t_arrays *)malloc(sizeof (t_arrays));
	arrayinit(s, ac, av);
	if (!s->a || !s->b)
		error("4");
	checkiforder(s);
	if (ac == 3 || s->q == 2)
	{
		if (s->a[1] > s->a[0])
			sa(s);
		exit(0);
	}
	if (ac == 4 || s->q == 3)
		threesort(s);
	else if ((ac > 4 && ac < 15) || (s->q > 3 && s->q < 14))
		sortfive(s);
	else if (ac >= 14 || s->q >= 14)
		sortplus(s);
	exit(0);
}
