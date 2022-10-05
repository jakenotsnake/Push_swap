/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:31:23 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/15 12:20:15 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

int	intlen(int n);

int	revapos(t_arrays *s, int n)
{
	int	i;
	int	t;
	int	ii;

	i = s->as;
	ii = s->as + 1;
	t = 0;
	s->a[ii] = 99999;
	while (i >= 0)
	{
		while (s->a[i] < s->b[n])
			i--;
		if (i < 0)
			break ;
		if (s->a[i] < s->a[ii])
			ii = i;
		i--;
	}
	s->a[s->as + 1] = 0;
	s->c = 0;
	return (ii + 1);
}

void	checkdups(t_arrays *s)
{
	int	i;
	int	c;

	i = 0;
	while (i <= s->as)
	{
		c = 0;
		while (c <= s->as)
		{
			if (i == c)
				c++;
			if ((s->a[i] == s->a[c] || s->a[i] > INT_MAX) && c <= s->as)
			{		
				error("5");
			}
			c++;
		}
		i++;
	}
}

void	printb(t_arrays *s, char *ins)
{
	int	i;

	if (s->bs > s->as)
		i = s->bs;
	else
		i = s->as;
	ft_printf("%s Step No.%d\n", ins, s->s);
	ft_printf("stackA   StackB\n");
	ft_printf("---------------\n");
	while (i > -1)
	{
		ft_printf("  %d[%d]       %d[%d]  \n", s->a[i], i, s->b[i], i);
		i--;
	}
	ft_printf("________________\n");
}

void	checkiforder(t_arrays *s)
{
	int	a;

	a = s->as;
	while (s->a[a] < s->a[a - 1] && a >= -1)
		a--;
	if (a == 0)
		exit(0);
}

void	frontcheck(t_arrays *s)
{
	int	i;
	int	c;

	c = 0;
	i = s->as;
	while (s->b[s->bs] > s->a[s->as] && c <= s->as)
	{
		ra(s);
		c++;
	}
	pa(s);
	while (s->b[s->bs] > s->a[s->as] && c <= s->as)
	{
		ra(s);
		c++;
	}
	if (s->bs != -1)
		pa(s);
	while (c <= s->as)
	{
		ra(s);
		c++;
	}
}
