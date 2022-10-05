/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:20:46 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/15 12:55:28 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pushswap.h"

void	error(char *s)
{
	char	*h;

	h = s;
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
		if ((long)result >= INT_MAX / 10)
			error("2");
	}
	result *= sign;
	return ((int)result);
}

void	arrayinit(t_arrays *s, int ac, char **av)
{
	int		i;
	int		c;

	if (ac == 2)
	{
		av = ft_split(av[1], ' ', s);
		ac = s->q;
	}
	checkforints(av, ac);
	setints(s, ac);
	i = 0;
	c = ac - 1;
	while (c != 0)
	{	
		s->a[i] = ft_atoi(av[c]);
		c--;
		i++;
	}
	checkdups(s);
}

void	checkforints(char **av, int ac)
{
	int		c;
	int		i;

	c = 1;
	while (c < ac)
	{
		i = 0;
		while (av[c][i] != '\0')
		{
			if (av[c][i] == '-')
				i++;
			if ((av[c][i] < '0' || av[c][i] > '9'))
				error("1");
			i++;
		}
		c++;
	}
}

void	setints(t_arrays *s, int ac)
{
	s->a = (int *)malloc(sizeof (int *) * (ac - 1));
	s->b = (int *)malloc(sizeof (int *) * (ac - 1));
	s->as = ac - 2;
	s->bs = -1;
	s->c = 0;
	s->s = 0;
	s->q = ac;
	ft_ibzero(s);
}
