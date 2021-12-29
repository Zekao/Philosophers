/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:27:06 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/29 04:15:47 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine()
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	pid = fork();
	printf("Process id : %d\n", getpid());
	if (!pid)
		wait (NULL);	
}