/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/27 18:58:25 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "./42Libft/libft.h"
# include "./42GNL/get_next_line_bonus.h"

# define READ_END 0
# define WRITE_END 1
# define FILE_NAME "file.txt"
# define FIRST_CHILD_FAIL "Problem with first child process!\n"
# define SECOND_CHILD_FAIL "Problem with second child process!\n"

char	*find_path(char **envp, char *cmd);
int		execute_cmd(char *cmd, char **envp);
void	first_child(char **argv, char **envp, int *fdp);
void	second_child(char **argv, char **envp, int *fdp);
int		main(int argc, char **argv, char **envp);
int		pipex(char **argv, char **envp);
void	error_log(void);

#endif
