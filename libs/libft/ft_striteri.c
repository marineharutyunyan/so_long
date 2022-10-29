/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:21:51 by maharuty          #+#    #+#             */
/*   Updated: 2022/04/13 01:11:58 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			f(i, &s[i]);
	}
}