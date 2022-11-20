/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:59:58 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/20 11:42:05 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extention(char *ber_file)
{
	int	len;

	len = ft_strlen(ber_file);
	if (ber_file[len - 1] == 'r' && ber_file[len - 2] == 'e'
		&& ber_file[len - 3] == 'b' && ber_file[len - 4] == '.' )
		return (1);
	else
	{
		ft_printf("map is invalid\n");
		return (0);
	}
}
