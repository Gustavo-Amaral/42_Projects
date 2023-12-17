/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:12:41 by gamaral           #+#    #+#             */
/*   Updated: 2023/12/17 20:32:09 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Pipex.h"

static char *parse_cmds(char **args, int *index, int flag, char *aux)
{
    char	*tmp;
	int		length;

	length = ft_strlen(args[*index]);
	if (args[*index][0] != '"' || args[*index][length - 1] != '"')
	{
		handle_error(INCORRECT_ARGUMENTS);
	}
    // while ((ft_strcmp(args[index + 1], "|") != 0) && (args[index + 1] != NULL))
    // {
    //     if (flag)
    //     {
    //         aux = ft_strjoin(args[index], " ");
    //         free(tmp);
    //         tmp = aux;
    //         aux = ft_strjoin(aux, args[index + 1]);
    //         free(tmp);
    //         tmp = aux;
    //     }
    //     else
    //     {
    //         aux = ft_strjoin(args[index], " ");
    //         tmp = aux;
    //         aux = ft_strjoin(aux, args[index + 1]);
    //         free(tmp);
    //         tmp = aux;
    //     }
    //     flag = 1;
    //     index++;
    // }
    return (aux);
}

static char *parse_outfile(char **args, int index, int flag, char* aux)
{
    char            *tmp;
    
    while (args[index + 1] != NULL)
    {
        if (flag)
        {
            aux = ft_strjoin(args[index], " ");
            free(tmp);
            tmp = aux;
            aux = ft_strjoin(aux, args[index + 1]);
            free(tmp);
            tmp = aux;
        }
        else
        {
            aux = ft_strjoin(args[index], " ");
            tmp = aux;
            aux = ft_strjoin(aux, args[index + 1]);
            free(tmp);
            tmp = aux;
        }
        flag = 1;
        index++;
    }
	return (aux);
}

static void generate_cmds(t_cmds *commands, char **args, int *index)
{
    int     flag;
    char    *aux;

    flag = 0;
    aux = NULL;
    commands->cmd1 = parse_cmds(args, index, flag, aux);
    flag = 0;
    aux = NULL;
    commands->file2 = parse_outfile(args, index, flag, aux);
}

void proccess_args(int argc, char **argv, t_cmds *commands)
{
    char    **args;
    int     index;

    args = argv;
    index = 2;
	commands->file1 = argv[1];
    generate_cmds(commands, args, &index);
    free_array(args);
}