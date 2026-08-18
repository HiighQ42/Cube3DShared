/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:30:46 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 16:39:35 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	error_message(int err_code)
{
	if (err_code == 0)
		printf("Error in input: You need a map file(.cub extension)\n");
	if (err_code == 1)
		printf("Error in reading file: Invalid File or Allocation Failed\n");
	if (err_code == 2)
		printf("Error in memory allocation: Check your heap\n");
	if (err_code == 3)
		printf("Error in parsing map: Check your map\n");
}

void	error_message_in_read(int error_code)
{
	if (error_code == 0)
		printf("Error in File: Check Format(typo and order)\n");
	else if (error_code == 1)
		printf("Error in File: Your File is empty\n");
	else if (error_code == 2)
		printf("Error in File: Your file has no map\n");
	else if (error_code == 3)
		printf("Error in File: Color range shoud be between 0 and 255\n");
	else if (error_code == 4)
		printf("Error in File: Your map has empty line(s) inside\n");
}

void	error_message_in_parse(int error_code)
{
	if (error_code == 0)
		printf("Error in File: Your map includes invalid character\n");
	if (error_code == 1)
		printf("Error in File: Your map has no start position(N,S,W, or E)\n");
	if (error_code == 2)
		printf("Error in File: Your map has too many players\n");
	if (error_code == 3)
		printf("Error in File: Your map is not closed by wall\n");
}
