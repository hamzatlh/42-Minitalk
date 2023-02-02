/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:22:43 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/02 22:58:34 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	send_character(char c, int pid)
{
	int	i;
	int	bit;
	int	tmp;

	i = 7;
	while (i >= 0)
	{
		bit = ((c >> i) & 1);
		if (bit == 0)
			tmp = kill(pid, SIGUSR1);
		else
			tmp = kill(pid, SIGUSR2);
		if (tmp == -1)
			exit (1);
		usleep (200);
		i--;
	}
}

void	send_string(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_character(str[i], pid);
		i++;
	}
	send_character('\0', pid);
}

void	hand_msg(int sig)
{
	(void)sig;
	ft_printf("message recieved\n");
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR2, &hand_msg);
	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 1)
		return (0);
	send_string(av[2], pid);
	return (0);
}
