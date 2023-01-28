/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:22:43 by htalhaou          #+#    #+#             */
/*   Updated: 2023/01/28 22:49:06 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

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

	i = 0;
	while (i <= 7)
	{
		bit = ((c >> i) & 1);
		if (bit == 0)
			tmp = kill(pid, SIGUSR1);
		else
			tmp = kill(pid, SIGUSR2);
		if (tmp == -1)
			exit (1);
		usleep (200);
		i++;
	}
}


// void	send_string(char *str, int pid)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		send_character(str[i], pid);
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		kill(pid, SIGUSR1);
	}
	return (0);
}
