/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:06:24 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/15 12:23:05 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

void	ra(t_arrays *s)
{
	int	i;
	int	tmp;

	i = s->as + 1;
	tmp = s->a[s->as];
	while (--i)
		s->a[i] = s->a[i - 1];
	s->a[0] = tmp;
	if (s->c == 1)
		return ;
	s->s += 1;
	printa(s, "ra");
}

void	rra(t_arrays *s)
{
	int	i;
	int	t;

	i = 0;
	t = s->a[0];
	while (i < s->as)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->as] = t;
	if (s->c == 1)
		return ;
	s->s += 1;
	printa(s, "rra");
}	

void	rb(t_arrays *s)
{
	int	i;
	int	tmp;

	i = s->bs + 1;
	tmp = s->b[s->bs];
	while (--i)
		s->b[i] = s->b[i - 1];
	s->b[0] = tmp;
	if (s->c == 1)
		return ;
	s->s += 1;
	printa(s, "rb");
}

void	rrb(t_arrays *s)
{
	int	i;
	int	t;

	i = 0;
	t = s->b[0];
	while (i < s->bs)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->bs] = t;
	if (s->c == 1)
		return ;
	s->s += 1;
	printa(s, "rrb");
}	

void	rr(t_arrays *s)
{
	s->c = 1;
	ra(s);
	rb(s);
	s->c = 0;
	s->s += 1;
	printa(s, "rr");
}
