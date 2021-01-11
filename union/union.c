/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 14:08:37 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/01/11 15:54:52 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	int		absent;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (-1);
	}

	s1 = argv[1];
	s2 = argv[2];

	for(int i = 0; s1[i]; i++)
	{
		absent = 0;
		for(int k = i - 1; k >= 0; k--)
		{
			if (s1[i] == s1[k])
				absent = 1;
		}
		if (absent == 0 || i == 0)
			write(1, &s1[i], 1);
	}
	for(int i = 0; s2[i]; i++)
	{
		absent = 0;
		for(int k = i - 1; k >= 0; k--)
		{
			if (s2[i] == s2[k])
				absent = 1;
		}
		for(int x = 0; s1[x]; x++)
		{
			if (s1[x] == s2[i])
				absent = 1;
		}
		if (absent == 0 || (i == 0 && absent == 0))
			write(1, &s2[i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
