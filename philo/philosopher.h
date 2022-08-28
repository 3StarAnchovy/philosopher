/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:03:03 by jihong            #+#    #+#             */
/*   Updated: 2022/08/28 11:46:21 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>

typedef struct s_info
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				finish;
	int				finish_eat;
	long long		start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	t_print;
}	t_info;

typedef struct s_philo
{
	struct s_info	*info;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_cnt;
}	t_philo;

int		error_message(char *msg, int err_num);
int		ft_atoi(const char *str);
long	get_current_time(void);

int		print_for_state(t_info *info, int id, char *msg);
void	custom_usleep(long long wait, t_info *info);
void	is_dead(t_info *info, t_philo *philo);
void	destroy_mutex(t_info *info, t_philo *philo);

int		philosopher(t_info *info, t_philo *philo);

int		init_info(t_info *info, int argc, char *argv[]);
int		philo_init(t_philo **philo, t_info *info);

#endif
