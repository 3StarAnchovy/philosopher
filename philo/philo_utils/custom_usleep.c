/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:14:46 by jihong            #+#    #+#             */
/*   Updated: 2022/08/27 23:13:20 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	custom_usleep(long long wait, t_info *info)
{
	long long	start;
	long long	now;

	start = get_current_time();
	while (!(info->finish))
	{
		now = get_current_time();
		if ((now - start) >= wait)
			break ;
		usleep(10);
	}
}
