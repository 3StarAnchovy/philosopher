/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:02:05 by jihong            #+#    #+#             */
/*   Updated: 2022/08/27 23:10:33 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	valid_check(t_info *info)
{
	if (info->philo_num <= 0 || info->time_to_die <= 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0)
	{
		return (5);
	}
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->t_print), NULL))
		return (1);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!(info->fork))
		return (1);
	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL))
			return (1);
		i ++;
	}
	return (0);
}

int	init_info(t_info *info, int argc, char *argv[])
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->start = get_current_time();
	valid_check(info);
	if (argc == 6)
	{
		info->eat_times = ft_atoi(argv[5]);
		if (info->eat_times <= 0)
			return (6);
	}
	if (init_mutex(info))
		return (1);
	return (0);
}

int	philo_init(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!(philo))
		return (1);
	while (i < info->philo_num)
	{
		(*philo)[i].info = info;
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->philo_num;
		(*philo)[i].last_eat_time = get_current_time();
		(*philo)[i].eat_cnt = 0;
		i ++;
	}
	return (0);
}
