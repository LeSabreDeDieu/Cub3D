/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:49:05 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 17:26:03 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_identifiant(char **str)
{
	char	*identifiant;
	char	*tmp;
	size_t	len;

	len = 0;
	while (**str && !ft_isspace(**str))
	{
		len++;
		(*str)++;
	}
	identifiant = ft_calloc(len + 1, sizeof(char));
	if (!identifiant)
		return (NULL);
	*str -= len;
	tmp = identifiant;
	while (**str && !ft_isspace(**str))
		*tmp++ = *((*str)++);
	if (identifiant[0] == '\0')
	{
		free(identifiant);
		return (NULL);
	}
	return (identifiant);
}

char	*get_chemin(char **str)
{
	char	*chemin;
	char	*tmp;
	size_t	len;

	len = 0;
	while (**str)
	{
		len++;
		(*str)++;
	}
	chemin = ft_calloc(len + 1, sizeof(char));
	if (!chemin)
		return (NULL);
	*str -= len;
	tmp = chemin;
	while (**str)
		*tmp++ = *((*str)++);
	if (chemin[0] == '\0')
	{
		free(chemin);
		return (NULL);
	}
	return (chemin);
}

t_texture_map	*get_elems(char *str)
{
	t_texture_map	*texture;
	char			*start;

	start = str;
	texture = ft_calloc(1, sizeof(t_texture_map));
	if (!texture)
		return (NULL);
	texture->id = get_identifiant(&start);
	if (!texture->id)
		return (free(texture), NULL);
	while (*start && ft_isspace(*start))
		start++;
	texture->path = get_chemin(&start);
	if (!texture->path)
	{
		free(texture->id);
		free(texture);
		return (NULL);
	}
	return (texture);
}

t_texture_map	*get_texture(int fd)
{
	char			*line;
	char			*tmp;
	t_texture_map	*result;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	tmp = ft_strtrim(line, " \t\n\v\f\r");
	free(line);
	while (tmp && tmp[0] == '\0')
	{
		free(tmp);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		tmp = ft_strtrim(line, " \t\n\v\f\r");
		free(line);
	}
	result = get_elems(tmp);
	free(tmp);
	return (result);
}

void	get_all_texture(t_cub3d *cub3d, int fd)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		cub3d->texture[i] = get_texture(fd);
		if (!cub3d->texture[i])
		{
			clean_gnl(fd);
			close(fd);
			exit_on_error(cub3d, ERROR_TEXTURE);
		}
		i++;
	}
}
