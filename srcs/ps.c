/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:07:57 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/14 13:23:29 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

void	sa(t_arrays *s)
{
	int	t;

	t = s->a[s->as];
	s->a[s->as] = s->a[s->as - 1];
	s->a[s->as - 1] = t;
	s->s += 1;
	printa(s, "sa");
}

void	sb(t_arrays *s)
{
	int	t;

	t = s->b[s->bs];
	s->b[s->bs] = s->b[s->bs - 1];
	s->b[s->bs - 1] = t;
	s->s += 1;
	printa(s, "sb");
}

void	ss(t_arrays *s)
{
	int	t;

	t = s->b[s->bs];
	s->b[s->bs] = s->b[s->bs - 1];
	s->b[s->bs -1] = t;
	t = s->a[s->as];
	s->a[s->as] = s->a[s->as - 1];
	s->a[s->as -1] = t;
	s->s += 1;
	printa(s, "ss");
}

void	pa(t_arrays *s)
{
	s->a[s->as + 1] = s->b[s->bs];
	s->b[s->bs] = 0;
	s->bs -= 1;
	s->as += 1;
	s->s += 1;
	printa(s, "pa");
}

void	pb(t_arrays *s)
{
	s->b[s->bs + 1] = s->a[s->as];
	s->a[s->as] = 0;
	s->as -= 1;
	s->bs += 1;
	s->s += 1;
	printa(s, "pb");
}
