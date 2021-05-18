#include <unistd.h>

int	r_strchr(char *str, char c, int i)
{
	while (--i >= 0)
		if (str[i] == c)
			return (0);
	return (1);
}

void	ft_union(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		if (r_strchr(str1, str1[i], i))
			write(1, &str1[i], 1);
		i++;
	}
	while (str2[j])
	{
		if (r_strchr(str1, str2[j], i) && r_strchr(str2, str2[j], j))
			write(1, &str2[j], 1);
		j++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
}
