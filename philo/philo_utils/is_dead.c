/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:27:29 by jihong            #+#    #+#             */
/*   Updated: 2022/08/27 23:13:07 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	is_dead(t_info *info, t_philo *philo)
{
	int			i;
	long long	now;

	while (!info->finish)
	{
		if ((info->eat_times != 0) && (info->philo_num == info->finish_eat))
		{
			info->finish = 1;
			break ;
		}
		i = 0;
		while (i < info->philo_num)
		{
			now = get_current_time();
			if ((now - philo[i].last_eat_time) >= info->time_to_die)
			{
				print_for_state(info, i, "died");
				info->finish = 1;
				break ;
			}
			i ++;
		}
	}
}
