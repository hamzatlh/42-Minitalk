/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:22:39 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/02 18:30:26 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int signum, siginfo_t *info, void *upp)
{
	static char		c;
	static int		countbit;
	static int		pid;

	(void)upp;
	if (pid != info->si_pid)
	{
		countbit = 0;
		c = 0;
		pid = info->si_pid;
	}
	c <<= 1;
	if (signum == SIGUSR2)
		c = c | 1;
	countbit++;
	if (countbit == 8)
	{
		write(1, &c, 1);
		countbit = 0;
		if (c == '\0')
			kill(pid, SIGUSR2);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		sa.sa_sigaction = sig_handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
