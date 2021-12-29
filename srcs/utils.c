/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:20:38 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/29 04:15:37 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			i;
	long long	r;
	int			verif;

	r = 0;
	verif = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			verif = -verif;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r * verif > 2147483647)
			return (-1);
		else if (r * verif < -2147483648)
			return (0);
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (r * verif);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 2048)
			i++;
		else
			return (0);
	}
	return (1);
}