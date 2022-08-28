/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:58:36 by jihong            #+#    #+#             */
/*   Updated: 2022/08/27 23:13:41 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	print_for_state(t_info *info, int id, char *msg)
{
	long long	now;

	now = get_current_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(info->t_print));
	if (!(info->finish))
		printf("%lld %d %s\n", now - info->start, id +1, msg);
	pthread_mutex_unlock(&(info->t_print));
	return (0);
}
