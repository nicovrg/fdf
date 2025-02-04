/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:59:35 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/05 19:19:39 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		main(int ac, char **av)
{
	t_fdf	f;

	f.exit_code = 0;
	if (ac != 2)
		return (error_msg(ERR_ARG));
	if (init_struct(av[1], &f) == -1)
		return (-1);
	fdf_init(&f);
	if (fdf(&f) == -1)
		return (clean_exit(&f));
	f.exit_code = 1;
	return (clean_exit(&f));
}
