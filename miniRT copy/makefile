# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artainmo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 20:25:57 by artainmo          #+#    #+#              #
#    Updated: 2019/12/19 15:51:35 by artainmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRC = miniRT.c \
				raycast/raycasting_base.c \
				raycast/raycasting_base2.c \
				raycast/get_ray.c \
				raycast/intersection_color.c \
				raycast/shadow.c \
				intersection/sphere_intersection.c \
				intersection/plane_intersection.c \
				intersection/square_intersection.c \
				intersection/cylinder_intersection.c \
				intersection/triangle_intersection.c \
				utils/vec_matrix_math/get_vector.c \
				utils/vec_matrix_math/calc_vectors.c \
				utils/vec_matrix_math/calc_vector_variable.c \
				utils/vec_matrix_math/calc_matrix.c \
				setup/setup.c \
				setup/setup1.c \
				setup/setup2.c \
				setup/setup3.c \
				setup/setup4.c \
				setup/setup_init.c \
				events/key_hook.c \
				events/mouse_hook.c \
				events/key_commands.c \
				events/key_commands2.c \
				events/key_commands3.c \
				utils/image.c \
				utils/color/color.c \
				utils/misconfiguration.c \
				utils/exit_free.c \
				utils/save_bmp.c \
				utils/list/list_manipulation.c \
				utils/list/max_obj.c \
				utils/list/max_obj2.c
OBJ = $(SRC:.c=.o)
#s->transforming .c in .o to enable the creation of a library

MLXFLAGS = -I ./utils/minilibX -L ./utils/minilibX -lmlx -framework OpenGl -framework Appkit

LIBFLAGS = -I ./utils/libft -L ./utils/libft -I ./utils/vec_matrix_math -L ./utils/vec_matrix_math -I . -L . ./utils/libft/*.c -I ./utils/get_next_line -L ./utils/get_next_line ./utils/get_next_line/*.c -I ./utils/color -L ./utils/color
# -I Add the directory dir to the list of directories to be searched for header files
# -L Searches the library when linking

GCC = gcc -Wall -Wextra -Werror

RM = rm -rf

all: libft_all minilibx_all $(NAME)


$(NAME): $(OBJ)
	$(GCC) $(MLXFLAGS) $(LIBFLAGS) libft.a libmlx.a $(OBJ) -o $(NAME) #&& ./$(NAME) scenes/errors/no_res.rt
# -c is used to form .o files from .c files
# !! Do not use -o before SRC it made files dissapear !!
# -o is normally used to create an executable into the filename that follows

bonus:
	$(GCC) $(CFLAGS) -c $(SRC2)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean: libft_clean minilibx_clean
	$(RM) $(OBJ)
	$(RM) *.rt


fclean: libft_fclean clean
	$(RM) $(NAME)

#(RM) scenes/*.bmp

re: fclean all


# In this last section we make other makefiles compile with the -C flag
# The -C flag makes you go to the appropriate path and do the asked command
libft_all:
	make -C ./utils/libft all
	cp ./utils/libft/libft.a libft.a
libft_clean:
	make -C ./utils/libft clean
libft_fclean:
	make -C ./utils/libft fclean
	$(RM) libft.a

minilibx_all:
	make -C ./utils/minilibX all
	cp ./utils/minilibX/libmlx.a libmlx.a
minilibx_clean:
	make -C ./utils/minilibX clean
	$(RM) libmlx.a

.PHONY: all test clean fclean re bonus
# Phony targets can exs->plicitly tell Make they're not associated with files but with make commands
