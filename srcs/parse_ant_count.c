/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ant_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:31:29 by vkinnune          #+#    #+#             */
/*   Updated: 2022/10/20 15:40:25 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*parse_ant_count(const char *input_str, t_info *info)
{
	enum e_type	line_type;
	char		*p;

	p = (char *)input_str;
	info->ant_count = 0;
	while (1)
	{
		line_type = comment_or_command(p);
		if (line_type == COMMENT || line_type == IGNORE)
		{
			while (*p != '\n')
				p++;
			p++;
			continue ;
		}
		break ;
	}
	p = ant_num(p, info);
	if (*p != '\n')
		ft_out("ERROR");
	p++;
	return (p);
}

char	*ant_num(char *p, t_info *info)
{
	if (*p == '0')
		ft_out("ERROR");
	while (ft_isdigit(*p))
	{
		info->ant_count *= 10;
		info->ant_count += *p - '0';
		p++;
	}
	if (info->ant_count > INT32_MAX)
		ft_out("ERROR");
	return (p);
}
