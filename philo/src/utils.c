/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:33:12 by xlebecq           #+#    #+#             */
/*   Updated: 2024/11/04 08:21:08 by xlebecq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error_msg(const char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	exit(EXIT_FAILURE);
}

void	ft_handle_sign(const char *str, int *i)
{
	while(str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-')
		ft_error_msg("Error: argument must be a positive number.\n");
	else if (str[*i] == '+')
		(*i)++;
}

void	ft_overflow(long long result, int digit)
{
	if (result > (INT_MAX - digit) / 10)
		ft_error_msg("Error: argument exceeds maximum integer value.\n");
}

int	ft_atoi(const char *str)
{
	int		i;
	long long	result;
	int		digit;

	i = 0;
	result = 0;
	ft_handle_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		ft_overflow(result, digit);
		result = result * 10 + (str[i] - '0');
		i++;
	}
if (str[i] != '\0')
		ft_error_msg("Error : argument contains invalid characters.\n");
	return ((int)(result));
}	




