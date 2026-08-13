NAME = cub3d

DEPDIR := .deps
OBJDIR := .obj

SRC = $(wildcard src/*.c)
SRCFILES := $(notdir $(SRC))
OBJ = $(SRCFILES:%.c=$(OBJDIR)/%.o)
DEPFILES := $(SRCFILES:%.c=$(DEPDIR)/%.d)

CC = cc
FLAGS = -Wall -Werror -Wextra
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d
LDFLAGS = -L./libft -lft 

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJDIR)/%.o: src/%.c $(DEPDIR)/%.d | $(DEPDIR) $(OBJDIR)
	$(CC) $(DEPFLAGS) $(FLAGS) -c $< -o $@

$(DEPDIR): ; @mkdir -p $@
$(OBJDIR): ; @mkdir -p $@

clean:
	rm -f $(OBJ) $(DEPFILES)
	rm -rf $(DEPDIR)
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

$(DEPFILES):
include $(wildcard $(DEPFILES))

.PHONY: all clean fclean re
