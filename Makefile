# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 03:21:58 by emaugale          #+#    #+#              #
#    Updated: 2021/12/14 03:21:58 by emaugale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo
SRCS 		=	srcs/init/init_philo.c				\
				srcs/main.c							\
				srcs/init/init_mutex.c					\
				srcs/routine/print_routine.c		\
				srcs/utils.c						\
				srcs/exec/execute_philo.c			\
						
OBJS		=		$(SRCS:.c=.o)
INCLUDE		= 		include
AR		=		#ar rcs
RM		=		rm -f
CC		=		gcc
CFLAGS		=		-Wall -Wextra -Werror -pthread -g

%.o:				%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all:	$(NAME)

$(NAME):		$(OBJS)
	@clear
	@echo "\033[1;34m                                                                                                                     "
	@echo "#######                                                  ###                                                   "       
	@echo "#       #    #   ##   #    #  ####    ##   #      ###### ###  ####     #####  #####   ####       # ######  ####  ##### "
	@echo "#       ##  ##  #  #  #    # #    #  #  #  #      #       #  #         #    # #    # #    #      # #      #    #   #   "
	@echo "#####   # ## # #    # #    # #      #    # #      #####  #    ####     #    # #    # #    #      # #####  #        #   "
	@echo "#       #    # ###### #    # #  ### ###### #      #               #    #####  #####  #    #      # #      #        #   "
	@echo "#       #    # #    # #    # #    # #    # #      #          #    #    #      #   #  #    # #    # #      #    #   #   "
	@echo "####### #    # #    #  ####   ####  #    # ###### ######      ####     #      #    #  ####   ####  ######  ####    #   "
	@echo "									"
	@echo "Project name : $(NAME)"
	@echo "\n\033[1;32mCompilation en cours... ⌛\033[0;m\n"
#	$(AR) $(NAME) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@make wait
	@make norm
	@echo "Bonne correction!"	


norm:
	@echo "⚠️ \033[5;1;34m Checking The Norm \033[m⚠️" 
	@if norminette $(SRCS) >/dev/null; then\
        echo "\033[1;32m    Norminette : OK\033[m";\
    else\
        echo "\033[1;31m    Norminette : Error\033[m";\
    fi
clean:
	@$(RM) $(OBJS)
	@echo "\033[1;31m ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀\033[1;34m Goodbye everyone\033[1;31m"
	@echo "⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀"
	@echo "⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀\033[m"
	@echo "\033[1;1;32m♻️  Objects have been \033[5;1;31mdeleted\033[m ♻️"

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo -n "\033[0;31m⠀"
	@echo "UNINSTALLING LEAGUE OF LEGENDS"
	@echo "[##############]"
	@echo "　╭━╮╭━╮ ╭╮ ╱ "　　
	@echo "　╰━┫╰━┫ ╰╯╱ ╭╮ "　　
	@echo "　╰━╯╰━╯　╱　╰╯" 　　　　　
	@echo "　     COMPLETE"
	@echo "\033[1;1;32m♻️  Objects and $(NAME) have been \033[5;1;31mdeleted\033[m ♻️"

wait:
	@echo -n "\r  5%  [\033[0;31m█\033[m.........................]"
	@sleep 0.1
	@echo -n "\r 10%  [\033[0;31m███\033[m.......................]"
	@sleep 0.1
	@echo -n "\r 15%  [\033[0;31m████\033[m......................]"
	@sleep 0.1
	@echo -n "\r 20%  [\033[0;31m██████\033[m....................]"
	@sleep 0.1
	@echo -n "\r 27%  [\033[0;31m████████\033[m..................]"
	@sleep 0.1
	@echo -n "\r 32%  [\033[0;31m██████████\033[m................]"
	@sleep 0.1
	@echo -n "\r 35%  [\033[0;31m███████████\033[m...............]"
	@sleep 0.1
	@echo -n "\r 45%  [\033[0;31m█████████████\033[m.............]"
	@sleep 0.1
	@echo -n "\r 50%  [\033[0;31m███████████████\033[m...........]"
	@sleep 0.1
	@echo -n "\r 65%  [\033[0;31m██████████████████\033[m........]"
	@sleep 0.1
	@echo -n "\r 80%  [\033[0;31m█████████████████████\033[m.....]"
	@sleep 0.1
	@echo -n "\r 90%  [\033[0;31m████████████████████████\033[m..]"
	@sleep 0.1
	@echo -n "\r 95%  [\033[0;31m█████████████████████████\033[m.]"
	@sleep 0.1
	@echo -n "\r 99%  [\033[0;31m██████████████████████████\033[m]"
	@sleep 1
	@echo -n "\r 100% [\033[0;32m██████████████████████████\033[m]\033[0;32m compilation terminee ✓\n\033[0;m"
re:		fclean all

.PHONY: all clean fclean re
