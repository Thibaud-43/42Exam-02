#include <unistd.h>

int		ft_is_in_charset(char c, char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return 1;
		i++;
	}
	return 0;
}

void	ft_union(char **argv)
{
	int i;
	int k;
	char writen[26];

	i = 0;
	k = 0;
	while (argv[1][k])
	{
		if (ft_is_in_charset(argv[1][k], writen) == 0)
		{
			write(1, &argv[1][k], 1);
			writen[i] = argv[1][k];
			i++;
		}
		k++;
	}
	k = 0;
	while (argv[2][k])
	{
		if (ft_is_in_charset(argv[2][k], writen) == 0)
		{
			write(1, &argv[2][k], 1);
			writen[i] = argv[2][k];
			i++;
		}
		k++;
	}
}
int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return 0;
	}
	ft_union(argv);
	write (1, "\n", 1);
	return 0;
}