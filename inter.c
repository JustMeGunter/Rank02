#include <stdio.h>
#include <unistd.h>

int	r_strchr(char *str, char c, int i)
{
	while (--i >= 0)  
		if (str[i] == c)
			return (0);
	return (1);
}

void	inter(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		while (str2[j])
		{
			if (str1[i] == str2[j])
				if (r_strchr(str1, str1[i], i) && r_strchr(str2, str2[j], j))
					write (1, &str1[i], 1);
			j++;
		}
		j = 0;
		i++;
	}
	write (1, "\n", 1);
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	inter(argv[1], argv[2]);
	inter("aaabbbcd", "aabbcdghi");
	inter("nothing", "This sentence hides nothing");
	inter("padinton", "paqefwtdjetyiytjneytjoeyjnejeyj");
	inter("ddf6vewg64f", "gtwthgdwthdwfteewhrtag6h4ffdhsd");
	return (0);
}
