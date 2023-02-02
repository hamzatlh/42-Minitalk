/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:03 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/02 16:17:22 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../ft_printf/ft_printf.h"
# include<unistd.h>
# include<signal.h>
# include<stdlib.h>

int		ft_atoi(const char *str);
void	sig_handler(int signum, siginfo_t *info, void *upp);
void	send_character(char c, int pid);
void	send_string(char *str, int pid);
void	hand_msg(int sig);

#endif
