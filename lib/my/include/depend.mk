##
## depend.mk for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
##
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
##
## Started on  Wed Nov  9 17:16:44 2016 Benjamin Viguier
## Last update Mon May 29 18:12:54 2017 Alexandre Chamard-bois
##

CC		=	gcc

DEBUG		=	true

WALL		=	true

RELEASE		=	false

ALLOW_LSEEK	=	true

ALLOW_OPEN	=	true

OPTI_FLAG	=	-O2

ifeq	($(WALL),true)
 CFLAGS		+=	-W -Wall -Wextra
endif

ifeq	($(RELEASE),true)
 CFLAGS		+=	$(OPTI_FLAG)
 CFLAGS		+=	-Werror -Wno-unused-result
 DEBUG		=	false
else
 CFLAGS		+=	-O0
endif

ifeq	($(DEBUG),true)
 CFLAGS		+=	-g
endif

ODIR		=	obj

SDIR		=	src
