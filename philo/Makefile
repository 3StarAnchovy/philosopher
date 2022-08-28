NAME		= philo


SRCS		= main.c init.c\
			utils/ft_atoi.c utils/ft_isdigit.c\
			utils/get_current_time.c\
			utils/error_message.c\
			philo_utils/print_for_state.c\
			philo_utils/is_dead.c\
			philo_utils/destroy_mutex.c\
			philo_utils/custom_usleep.c\
			philosopher.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		cc -o $(NAME) $(OBJS)

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
