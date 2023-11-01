/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_victory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:35:32 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 15:37:33 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    victory(t_data *data)
{
    int i;
    
    data->player.victory = true;
    while (1)
    {
        i = 0;
        mlx_string_put(data->mlx, data->win, rand(), rand(), rand(), "VICTORY!!!");
        while (i < 1000)
            i++;
    }
}