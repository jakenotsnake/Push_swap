/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortestroute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:25:29 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/19 14:41:06 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

int	findshortest(t_arrays *s)
{
	int	b;
	int	c;
	int	t;
	int	cc;

	b = 0;
	cc = 10000;
	while (b <= s->bs)
	{
		c = route(s, b);
		if (b < (s->bs / 2))
			c = c + b + 1;
		else
			c = (c + (s->bs - b));
		if (c < cc)
		{
			cc = c;
			t = b;
		}
		b++;
	}
	return (t);
}

void	short5(t_arrays *s)
{
	int	i;
	int	a;

	i = findshortest(s);
	if (s->c == 1)
		a = revapos(s, i);
	else
		a = apos(s, i);
	if ((i > (s->bs / 2)) && (a > (s->as / 2)))
		bothhigh(s, i, a);
	else if ((i < (s->bs / 2)) && (a < (s->as / 2)))
		bothlow(s, i, a);
	else
		neither(s, i, a);
	pa(s);
}

void	bothhigh(t_arrays *s, int b, int a)
{
	while (b < s->bs && a < s->as + 1)
	{
		rr(s);
		b++;
		a++;
	}
	while (b < s->bs)
	{
		rb(s);
		b++;
	}
	while (a < s->as + 1)
	{
		ra(s);
		a++;
	}
}

void	bothlow(t_arrays *s, int b, int a)
{
	while (b >= 0 && a > 0)
	{
		rrr(s);
		b--;
		a--;
	}
	while (b >= 0)
	{
		rrb(s);
		b--;
	}
	while (a >= 1)
	{
		rra(s);
		a--;
	}
}

void	neither(t_arrays *s, int b, int a)
{
	if (b > (s->bs / 2))
		tophalfb(s, b + 1);
	else
		bottomhalfb(s, b + 1);
	if (a > (s->as / 2))
		tophalf(s, a);
	else
		bottomhalf(s, a);
}
