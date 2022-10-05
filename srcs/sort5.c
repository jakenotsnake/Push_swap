/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:26:32 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/19 18:09:11 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sortfive(t_arrays *s)
{
	int	i;
	int	c;

	i = s->as;
	c = 0;
	while (i > 2)
	{
		pb(s);
		i--;
		c++;
	}
	threesort(s);
	while (s->bs > -1)
		fivecheck(s);
}

void	fivecheck(t_arrays *s)
{
	if (s->b[s->bs] > s->b[s->bs -1])
	{
		backcheckf(s);
		return ;
	}
	else
		frontcheck(s);
}	

void	backcheckf(t_arrays *s)
{
	int	i;
	int	c;

	c = 0;
	i = s->as;
	while (s->b[s->bs] < s->a[0] && i >= 0)
	{
		rra(s);
		i--;
		c++;
	}
	pa(s);
	i--;
	while (s->b[s->bs] < s->a[0] && i >= -1)
	{
		rra(s);
		i--;
	}
	pa(s);
	while (i >= -1)
	{
		rra(s);
		i--;
	}
}
