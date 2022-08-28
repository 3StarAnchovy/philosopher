/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:11:17 by jihong            #+#    #+#             */
/*   Updated: 2022/08/27 23:12:00 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philo_action(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->fork[philo->left]));
	print_for_state(info, philo->id, "has taken a fork");
	if (info->philo_num != 1)
	{
		pthread_mutex_lock(&(info->fork[philo->right]));
		print_for_state(info, philo->id, "has taken a fork");
		print_for_state(info, philo->id, "is eating");
		philo->last_eat_time = get_current_time();
		philo->eat_cnt = philo->eat_cnt + 1;
		custom_usleep((long long)info ->time_to_eat, info);
		pthread_mutex_unlock(&(info->fork[philo->right]));
	}
	pthread_mutex_unlock(&(info->fork[philo->left]));
	return (0);
}

void	*do_action(void *argv)
{
	t_info	*info;
	t_philo	*philo;

	philo = argv;
	info = philo->info;
	if (philo->id % 2)
		usleep(1000);
	else
		usleep(500);
	while (!info->finish)
	{
		philo_action(info, philo);
		if (info->eat_times == philo->eat_cnt)
		{
			info->finish_eat++;
			break ;
		}
		print_for_state(info, philo->id, "is sleeping");
		custom_usleep((long long)info->time_to_sleep, info);
		print_for_state(info, philo->id, "is thinking");
	}
	return (0);
}

int	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		philo[i].last_eat_time = get_current_time();
		if (pthread_create(&(philo[i].thread), NULL, do_action, &(philo[i])))
			return (1);
		i ++;
	}
	is_dead(info, philo);
	i = 0;
	while (i < info->philo_num)
		pthread_join(philo[i++].thread, NULL);
	destroy_mutex(info, philo);
	return (0);
}
