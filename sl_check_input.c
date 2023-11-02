/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:01 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/02 15:48:37 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc)
{
	if (argc <= 1)
	{
		ft_printf("Please, choose any map and try again");
		exit (MLX_ERROR);
		return (MLX_ERROR);
	}
	else if (argc > 2)
	{
		ft_printf("Too many arguments, try again!");
		exit (MLX_ERROR);
		return (MLX_ERROR);
	}
	else
		return (0);
}