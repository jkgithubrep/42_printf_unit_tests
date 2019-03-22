# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 13:30:57 by jkettani          #+#    #+#              #
#    Updated: 2019/03/22 16:43:15 by jkettani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- VARIABLES -----

NC =            \x1b[0m
OK_COLOR =      \x1b[32;01m
ERR_COLOR =     \x1b[31;01m
WARN_COLOR =    \x1b[34;01m
QUIET :=        @
ECHO :=         @echo
ifneq ($(QUIET),@)
ECHO :=         @true
endif
SHELL =         /bin/sh
MAKEFLAGS +=    --warn-undefined-variables
NAME =          libunit.a
SRC_PATH =      srcs
INCLUDE_PATH =  includes
OBJ_PATH =      .obj
RM =            rm -f
RMDIR =         rmdir -p
AR =            ar
ARFLAGS =       -rcs
CC =            gcc
CFLAGS =        -g3 -Werror -Wall -Wextra
CPPFLAGS =      -I$(INCLUDE_PATH) 
COMPILE.c =     $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
DEPFLAGS =      -MT $@ -MMD -MP -MF $(OBJ_PATH)/$*.Td
POSTCOMPILE =   mv -f $(OBJ_PATH)/$*.Td $(OBJ_PATH)/$*.d && touch $@
SRC_NAME =	    frmk_load_test frmk_launch_tests frmk_print frmk_print_trace \
				frmk_utils frmk_stdout_utils
SRC =           $(addprefix $(SRC_PATH)/,$(addsuffix .c, $(SRC_NAME)))
OBJ =           $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))
DEP =           $(addprefix $(OBJ_PATH)/,$(SRC:.c=.d))
OBJ_TREE =      $(shell find $(OBJ_PATH) -type d -print 2> /dev/null)

.SUFFIXES:
.SUFFIXES: .c .o .h

# ----- RULES -----

.PHONY: all
all: $(NAME)

.PRECIOUS: $(OBJ_PATH)%/. $(OBJ_PATH)/. 
$(OBJ_PATH)/. $(OBJ_PATH)%/.: 
	$(ECHO) "Making directory $(WARN_COLOR)$@$(NC)..."
	$(QUIET) mkdir -p $@

$(OBJ_PATH)/%.d: ;

.SECONDEXPANSION:

$(OBJ): $(OBJ_PATH)/%.o: %.c $(OBJ_PATH)/%.d | $$(@D)/.
	$(ECHO) "Compiling $(WARN_COLOR)$<$(NC)..."
	$(QUIET) $(COMPILE.c) $< -o $@
	$(QUIET) $(POSTCOMPILE)

$(NAME): $(OBJ)
	$(ECHO) "Building archive file $(WARN_COLOR)$(NAME)$(NC)..."
	$(QUIET) $(AR) $(ARFLAGS) $@ $?

.PHONY: clean
clean:
	$(ECHO) "Cleaning object files..."
	$(QUIET) $(RM) $(OBJ)
	$(ECHO) "Cleaning dependency files..."
	$(QUIET) $(RM) $(DEP)
	$(ECHO) "Cleaning obj tree..."
	$(QUIET) echo $(OBJ_TREE) | xargs $(RMDIR) 2> /dev/null || true
	@if [ -d $(OBJ_PATH) ]; \
		then echo "$(ERR_COLOR)⟹  Could not clean obj directory.$(NC)"; \
		else echo "$(OK_COLOR)⟹  Obj directory succesfully cleaned.$(NC)"; fi

.PHONY: fclean
fclean: clean
	$(ECHO) "Cleaning $(NAME)..."
	$(QUIET) $(RM) $(NAME)
	@if [ -f $(NAME) ]; \
		then echo "$(ERR_COLOR)⟹  Could not clean $(NAME).$(NC)"; \
		else echo "$(OK_COLOR)⟹  $(NAME) succesfully cleaned.$(NC)"; fi

.PHONY: re
re: fclean all

# ----- INCLUDES -----

.PRECIOUS: $(OBJ_PATH)/%.d
-include $(DEP)
