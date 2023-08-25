SRCS			=	src/strstr.c src/algo_func4.c src/list_utils5.c src/algo_func3.c src/algo_func2.c src/algo_func1.c  src/list_utils4.c src/main.c src/algo.c src/ft_split.c src/atoi.c src/init_pile.c src/list_creation.c src/list_utils1.c src/list_utils2.c src/list_utils3.c src/parse.c
INCLUDES		= include/
OBJS			= $(patsubst src/%.c,objs/%.o,$(SRCS))

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= push_swap


all: $(NAME)
				
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g3 ${SRCS} -I ${INCLUDES} -o $(NAME)

objs/%.o: src/%.c | objs
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

objs:
	mkdir -p objs


clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

debug:
	echo $(OBJS)

.PHONY:			all clean fclean re bonus