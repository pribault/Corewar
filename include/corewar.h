/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:28:06 by pribault          #+#    #+#             */
/*   Updated: 2017/03/17 09:23:47 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "ft_printf.h"
# include "op.h"

typedef struct	s_flags
{
	size_t		flags;
}				t_flags;

typedef struct	s_process
{
	char		reg[REG_NUMBER][REG_SIZE];
	char		pc[REG_SIZE];
	char		carry;
	size_t		cycles;
}				t_process;

typedef struct	s_champ
{
	char		*name;
	char		*comment;
	size_t		len;
	size_t		live;
	t_list		*process;
}				t_champ;

typedef struct	s_arena
{
	t_flags		flags;
	char		arena[MEM_SIZE];
	t_champ		champs[MAX_PLAYERS];
	t_list		*active;
	t_list		*waiting;
}				t_arena;

void			ft_error(int error, void *param);

size_t			ft_endian(size_t n);
void			ft_endian_c(char *n);

void			get_flags(t_arena *arena, int argc, char **argv);

void			create_champions(t_arena *arena, int n);

void			creat_process(t_arena *arena, int n, int fd[4]);

#endif
