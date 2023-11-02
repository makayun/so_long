/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_victory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:35:32 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:19 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	victory(t_data *data)
{
	int	i;

	data->player.victory = true;
	ft_printf("VICTORY!!!\n");
	i = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->assets.vict1.img, 0, 0);
	ft_printf("You finished the game in %d steps\n", ++data->player.steps);
}
