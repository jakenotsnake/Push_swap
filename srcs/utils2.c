/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:27:13 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/15 11:44:20 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

void	printa(t_arrays *s, char *ins)
{
	int	a;

	a = s->as;
	ft_printf("%s\n", ins);
}

void	ft_ibzero(t_arrays *s)
{
	int	i;

	i = s->as + 1;
	while (i--)
		s->b[i] = 0;
}

void	tophalfb(t_arrays *s, int i)
{
	while (i < s->bs + 1)
	{
		rb(s);
		i++;
	}
}

void	bottomhalfb(t_arrays *s, int i)
{
	while (i > 0)
	{
		rrb(s);
		i--;
	}
}

//rotates lowest number to top of array a
void	pushtotop(t_arrays *s)
{	
	int	i;

	i = findsmallest(s, 0);
	while (i < s->as)
	{
		ra(s);
		i++;
	}
	checkiforder(s);
}
