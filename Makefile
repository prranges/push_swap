NAME1 	= push_swap

NAME2 	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRCS1	= main.c \
	  utils.c \
	  push_swap.c \
	  ft_atoi.c \
	  ft_split.c \
	  operations1.c \
	  operations2.c \
	  sort_3_5.c \
	  sort_100_500.c \
	  sort_100_500_utils.c \
	  index.c \
	  parse.c

SRCS2	= checker.c \
	  utils.c \
	  push_swap.c \
	  ft_atoi.c \
	  ft_split.c \
	  ft_strcmp.c \
	  operations1.c \
	  operations2.c \
	  includes/get_next_line/get_next_line.c \
	  includes/get_next_line/get_next_line_utils.c \
	  index.c \
	  parse.c

OBJSFD 	= temp

OBJS1	= $(addprefix $(OBJSFD)/,$(SRCS1:.c=.o))

OBJS2	= $(addprefix $(OBJSFD)/,$(SRCS2:.c=.o))

RM	= rm -rf

HEAD	= -I./includes

all: $(NAME1) $(NAME2)

$(OBJSFD):
	mkdir $@
	mkdir $@/includes
	mkdir $@/includes/get_next_line

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) $(HEAD) -c $< -o $@

$(NAME1): $(OBJS1) ./includes/push_swap.h
	gcc -g $(OBJS1) -o $@

$(NAME2): $(OBJS2) ./includes/push_swap.h
	gcc -g $(OBJS2) -o $@

clean:
	$(RM) $(OBJSFD)

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: 	fclean all

