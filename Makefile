##
## EPITECH PROJECT, 2020
## NWP_myftp_2019
## File description:
## Makefile
##

DIR_INC_SER	=	./include/server/
DIR_INC_CLI	=	./include/client/
DIR_INC_LIB	= 	./libs/myteams/

DIR_UTILS 	= 	./src/utility/

# SERVER
DIR_SER		=	./src/server/server/
DIR_SCLI	=	./src/server/client/
DIR_SRC		=	./src/server/
DIR_CMD		=	./src/server/server/cmd/

SRC_SER		=	$(DIR_SRC)main.c					\
				$(DIR_SRC)tools.c					\
				$(DIR_SRC)tools_create.c			\
				$(DIR_SRC)tools2.c					\
				$(DIR_SER)server.c					\
				$(DIR_SER)event.c					\
				$(DIR_SER)socket.c					\
				$(DIR_SER)set_fd.c					\
				$(DIR_SER)manage_data.c				\
				$(DIR_CMD)login.c					\
				$(DIR_CMD)users.c					\
				$(DIR_CMD)create_team_channel.c		\
				$(DIR_CMD)user.c					\
				$(DIR_CMD)subscribe.c				\
				$(DIR_CMD)create.c					\
				$(DIR_CMD)use.c						\
				$(DIR_CMD)send.c					\
				$(DIR_CMD)send_bis.c				\
				$(DIR_CMD)messages.c				\
				$(DIR_CMD)unsubscribe.c				\
				$(DIR_SCLI)manage_clients.c			\
				$(DIR_SCLI)add_client.c				\
				$(DIR_SCLI)delete_client.c			\
				$(DIR_UTILS)itoa.c					\
				$(DIR_UTILS)concat_str.c			\
				$(DIR_UTILS)add_line_at_end.c       \
				$(DIR_UTILS)take_arg.c				\
                $(DIR_UTILS)get_uuid_conv.c         \
                $(DIR_UTILS)str_twa.c				\
                $(DIR_UTILS)clean_txt.c				\
                $(DIR_UTILS)read_file.c

OBJ_SER		=	$(SRC_SER:.c=.o)
SERVER		=	myteams_server

# CLIENT
DIR_CLI 	= 	./src/client/
DIR_CLISRC 	= 	./src/client/cli_teams/cli_pi/

SRC_CLI		=	$(DIR_CLI)main.c 					\
		  		$(DIR_CLISRC)start.c 				\
		  		$(DIR_CLISRC)utils.c 				\
				$(DIR_CLISRC)utils2.c				\
		  		$(DIR_CLISRC)interpreter.c 			\
		  		$(DIR_CLISRC)commands.c 			\
		  		$(DIR_CLISRC)a_commands_handler.c	\
          		$(DIR_CLISRC)b_commands_handler.c	\
          		$(DIR_CLISRC)c_commands_handler.c	\
				$(DIR_CLISRC)events.c				\
				$(DIR_CLISRC)a_event_handler.c		\
				$(DIR_CLISRC)b_event_handler.c		\
                $(DIR_CLISRC)a_response_handler.c   \
                $(DIR_CLISRC)b_response_handler.c   \
                $(DIR_CLISRC)c_response_handler.c   \
                $(DIR_CLISRC)d_response_handler.c   \
                $(DIR_CLISRC)e_response_handler.c

OBJ_CLI		=	$(SRC_CLI:.c=.o)
CLIENT		= 	myteams_cli

LDFLAGS		+= 	-L ./libs/myteams -lmyteams
CFLAGS		=	-Wall -Wextra -luuid -I$(DIR_INC_SER) -I$(DIR_INC_CLI) -I$(DIR_INC_LIB) -g

all			: 	$(SERVER) $(CLIENT)

server		:	$(SERVER)

client		:	$(CLIENT)

$(SERVER)	:	$(OBJ_SER)
				gcc -o $(SERVER) $(OBJ_SER) $(CFLAGS) $(LDFLAGS)

$(CLIENT)	:	$(OBJ_CLI)
				gcc -o $(CLIENT) $(OBJ_CLI) $(CFLAGS) $(LDFLAGS)

clean		:
				rm -f $(OBJ_SER)
				rm -f $(OBJ_CLI)

fclean		:	clean
				rm -f $(SERVER)
				rm -f $(CLIENT)

re			:	fclean all

.PHONY: all clean fclean re
