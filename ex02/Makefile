NAME	= mutant

SRC		=	main.cpp \

OBJDIR := obj

OBJ	:= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

DEPDIR := $(OBJDIR)/.deps

DEPFILES = $(addprefix $(DEPDIR)/, $(SRC:.cpp=.d))

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CC       = c++

CPPFLAGS = $(CC) $(DEPFLAGS) -Wall -Wextra -Werror -std=c++98

%.o : %.cpp

$(OBJDIR)/%.o : %.cpp | $(OBJDIR) $(DEPDIR)
		$(CPPFLAGS) -c $< -o $@

all : $(NAME)

$(DEPFILES):
include $(DEPFILES)

$(NAME) : $(OBJ)
		$(CPPFLAGS) $(OBJ) -o $(NAME)

re : fclean all

clean :
		rm -rf $(OBJDIR)

fclean : clean
		rm -rf $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(DEPDIR): | $(OBJDIR)
	@mkdir $(DEPDIR)

.PHONY: all re clean fclean
