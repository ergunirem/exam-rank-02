/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 16:06:39 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/01/11 16:11:52 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	int		doubles;
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
		doubles = 0;
		for(int k = i - 1; k >= 0; k--)
		{
			if (s1[i] == s1[k])
				doubles = 1;
		}
		absent = 0;
		for(int x = 0; s2[x]; x++)
		{
			if (s1[x] == s2[i])
				absent = 1;
		}
		if ((absent == 1 && doubles == 0 ) || (i == 0 && absent == 1))
			write(1, &s1[i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
