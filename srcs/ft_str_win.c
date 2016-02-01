/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:02:13 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/01 17:35:25 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	            ft_str_win(t_env *init)
{
	mlx_string_put(init->mlx, init->win, 10, 5, 0xFF0000, "! Bienvenue sur FDF !");
	mlx_string_put(init->mlx, init->win, 10, 25, 0xffffff,
        "Chemin de la maps :");
	mlx_string_put(init->mlx, init->win, 205, 25, 0xffffff, init->lol);
	mlx_string_put(init->mlx, init->win, 10, 45, 0xffffff, "Zoom :");
	mlx_string_put(init->mlx, init->win, 75, 45, 0xffffff,
        ft_itoa(init->zoom));
	mlx_string_put(init->mlx, init->win, 10, 65, 0xffffff, "Position X :");
	mlx_string_put(init->mlx, init->win, 135, 65, 0xffffff,
        ft_itoa(init->movex));
	mlx_string_put(init->mlx, init->win, 10, 85, 0xffffff, "Position Y :");
	mlx_string_put(init->mlx, init->win, 135, 85, 0xffffff,
        ft_itoa(init->movey));
	mlx_string_put(init->mlx, init->win, 10, 105, 0xffffff, "Hauteur :");
	mlx_string_put(init->mlx, init->win, 105, 105, 0xffffff,
        ft_itoa(init->axez));
	mlx_string_put(init->mlx, init->win, 10, 125, 0xffffff, "Rotation X :");
	mlx_string_put(init->mlx, init->win, 132, 125, 0xffffff,
        ft_itoa(init->axex));
	mlx_string_put(init->mlx, init->win, 10, 145, 0xffffff, "Rotation y :");
	mlx_string_put(init->mlx, init->win, 132, 145, 0xffffff,
        ft_itoa(init->axey));

    mlx_string_put(init->mlx, init->win, 10, 900, 0xffffff,
        "Press Echap to quit");

}
