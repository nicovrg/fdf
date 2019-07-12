/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:23:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 14:17:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		error_msg(char *error_msg)
{
	ft_putendl(error_msg);
	return (-1);
}

int		gnl_error_free(char **line, char *error_msg)
{
	ft_putendl(error_msg);
	ft_strdel(line);
	return (-1);
}