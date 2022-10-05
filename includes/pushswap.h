/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:17:45 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/15 12:50:36 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../printf/includes/ft_printf.h"
# define INT_MAX	2147483647
# define INT_MIN	2147483648

typedef struct s_arrays
{
	int		*a;
	int		*b;
	int		as;
	int		bs;
	int		c;
	int		s;
	int		q;
	char	**split;
}				t_arrays;

void	frontcheck(t_arrays *s);
void	checkiforder(t_arrays *s);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c, t_arrays *h);
void	printb(t_arrays *s, char *ins);
void	sortplus(t_arrays *s);
void	checkdups(t_arrays *s);
int		stackbcheck(t_arrays *s);
int		revapos(t_arrays *s, int n);
void	checkforints(char **av, int ac);
void	setints(t_arrays *s, int ac);
int		findshortest(t_arrays *s);
void	short5(t_arrays *s);
void	bothhigh(t_arrays *s, int b, int a);
void	bothlow(t_arrays *s, int b, int a);
void	neither(t_arrays *s, int b, int a);
int		route(t_arrays *s, int n);
void	rr(t_arrays *s);
void	rrr(t_arrays *s);
int		findpos(t_arrays *s, int i);
void	pushbackorder(t_arrays *s);
int		findlargest(t_arrays *s);
int		findsmallest(t_arrays *s, int n);
void	pushinorder(t_arrays *s);
int		findlarge(t_arrays *s, int n);
void	tophalf(t_arrays *s, int i);
void	bottomhalf(t_arrays *s, int i);
void	pushtotop(t_arrays *s);
void	printa(t_arrays *s, char *ins);
void	error(char *s);
int		main(int ac, char **av);
void	sa(t_arrays *s);
void	sb(t_arrays *s);
void	ss(t_arrays *s);
void	pa(t_arrays *s);
void	pb(t_arrays *s);
void	ra(t_arrays *s);
void	rra(t_arrays *s);
void	threesort(t_arrays *s);
int		atoai(char *av);
void	arrayinit(t_arrays *s, int ac, char **av);
void	sortfive(t_arrays *s);
void	fivecheck(t_arrays *s);
void	ft_ibzero(t_arrays *s);
void	rb(t_arrays *s);
void	backcheckf(t_arrays *s);
void	sortplus(t_arrays *s);
int		findsmall(t_arrays *s);
int		findsmall5(t_arrays *s, int n);
void	rrb(t_arrays *s);
void	bottomhalfb(t_arrays *s, int i);
void	tophalfb(t_arrays *s, int i);
int		apos(t_arrays *s, int n);
#endif
