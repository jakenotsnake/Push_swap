/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:29:26 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/19 14:41:07 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

void	tophalf(t_arrays *s, int i)
{
	while (i < s->as + 1)
	{
		ra(s);
		i++;
	}
}

void	bottomhalf(t_arrays *s, int i)
{
	while (i > 0)
	{
		rra(s);
		i--;
	}
}

void	rrr(t_arrays *s)
{
	s->c = 1;
	rra(s);
	rrb(s);
	s->c = 0;
	s->s += 1;
	printa(s, "rrr");
}

//returns amount of moves to get b[n]'s correlating a[i] to right spot
int	route(t_arrays *s, int n)
{
	int	i;
	int	t;
	int	ii;

	i = s->as;
	ii = s->as + 1;
	t = 0;
	s->a[ii] = -99999;
	while (i >= 0)
	{
		while (s->a[i] > s->b[n])
			i--;
		if (s->a[i] > s->a[ii])
			ii = i;
		i--;
	}
	if (ii > s->as)
		ii = findlarge(s, n);
	s->a[s->as + 1] = 0;
	if (ii > (s->as / 2))
		ii = 1 + s->as - ii;
	return (ii);
}

//returns i[a] to match b[n]
int	apos(t_arrays *s, int n)
{
	int	i;
	int	t;
	int	ii;

	i = s->as;
	ii = s->as + 1;
	t = 0;
	s->a[ii] = -99999;
	while (i >= 0)
	{
		while (s->a[i] > s->b[n])
			i--;
		if (i < 0)
			break ;
		if (s->a[i] > s->a[ii])
			ii = i;
		i--;
	}
	if (ii > s->as)
		ii = findlarge(s, n);
	s->a[s->as + 1] = 0;
	return (ii);
}
