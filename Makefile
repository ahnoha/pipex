NAME = pipex.a
CFLAGS = -Wall -Wextra -Werror
HEADERS = pipex.h
SRC = 	ft_split.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_substr.c\
		errors.c\
		pipe.c\
		env.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)
	gcc $(NAME) main.c -o pipex

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f pipex

re: fclean all