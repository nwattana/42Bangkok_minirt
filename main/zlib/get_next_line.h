/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:02:12 by lsomrat           #+#    #+#             */
/*   Updated: 2022/04/04 23:21:24 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include<sys/types.h>
# include<sys/stat.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

typedef struct  s_gnl
{
    char            *content;
    struct s_gnl   *next;
}       t_gnl;

char    *get_next_line(int fd);
char    *read_file(int fd, t_gnl **buff);
char    *get_line(t_gnl *buff, char **line);
void    save_readed(t_gnl **buff, char *buf, int readed);
void    generate_line(char **line, t_gnl *buff);
void    clear_buff(t_gnl **buff);
void    free_buff(t_gnl *buff);
int		get_newline(t_gnl *buff);
size_t  gnl_strlen(const char *s);
t_gnl  *get_last(t_gnl *buff);
#endif