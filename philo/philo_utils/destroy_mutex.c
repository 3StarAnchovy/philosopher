/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:42:50 by jihong            #+#    #+#             */
/*   Updated: 2022/08/27 23:13:48 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	destroy_mutex(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
		pthread_mutex_destroy(&(info->fork[i++]));
	free(philo);
	free(info->fork);
	pthread_mutex_destroy(&(info->t_print));
}
