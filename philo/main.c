/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:38:24 by jihong            #+#    #+#             */
/*   Updated: 2022/08/28 11:44:37 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;
	int		err_num;

	if (argc < 5 || argc > 6)
		return (error_message("check argc", 3));
	memset(&info, 0, sizeof(t_info));
	err_num = init_info(&info, argc, argv);
	if (err_num)
		return (error_message("check init params", err_num));
	err_num = philo_init(&philo, &info);
	if (err_num)
		return (error_message("error philo init", err_num));
	err_num = philosopher(&info, philo);
	if (err_num)
		return (error_message("err", err_num));
	return (0);
}
