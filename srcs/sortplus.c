/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortplus.c                                            :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:26:32 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/15 12:21:29 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sortplus(t_arrays *s)
{
	pushinorder(s);
	while (s->bs >= 0)
		short5(s);
	pushtotop(s);
}

//pushes stack a to stack b leaving stack a in ascending order
void	pushinorder(t_arrays *s)
{
	int	i;
	int	h;
	int	c;

	c = 0;
	i = findsmallest(s, 0);
	h = s->a[i];
	if (i > (s->as / 2))
		tophalf(s, i);
	else
		bottomhalf(s, i);
	while (s->a[s->as] != h)
	{
		if ((findpos(s, s->a[s->as]) > ((findpos(s, s->a[0]) + (s->q / 6.6)))))
			pb(s);
		else if (s->a[s->as] > s->a[0])
			ra(s);
		else
			pb(s);
	}
}

// intput an index, returns how many numbers it is bigger than
int	findpos(t_arrays *s, int i)
{
	int	c;
	int	t;

	c = 0;
	t = 0;
	while (t <= s->as)
	{
		if (i > s->a[t])
			c++;
		t++;
	}
	return (c);
}

//returns an index point of number that has n numbers it is bigger than
int	findsmallest(t_arrays *s, int n)
{
	int	i;
	int	c;
	int	z;

	i = s->as;
	while (i >= 0)
	{
		c = 0;
		z = s->as;
		while (z >= 0)
		{
			if (s->a[i] > s->a[z])
				c++;
			z--;
		}
		if (c == n)
			break ;
		i--;
	}
	return (i);
}

// finds smallest number that is larger than b[s->bs]
int	findlarge(t_arrays *s, int n)
{
	int	i;
	int	t;
	int	ii;

	s->c = 1;
	i = s->as;
	ii = s->as + 1;
	t = 0;
	s->a[ii] = 99999;
	while (i >= 0)
	{
		while (s->a[i] < s->b[n])
			i--;
		if (s->a[i] < s->a[ii])
			ii = i;
		i--;
	}
	ii += 1;
	s->a[s->as + 1] = 0;
	return (ii);
}
