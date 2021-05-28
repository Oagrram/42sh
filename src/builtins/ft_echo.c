#include "forty_two_sh.h"

int	do_special_char(char c)
{
	if (c == 'n')
		ft_putchar('\n');
	else if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'e' || c == 'E')
		ft_putchar('\e');
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else if (c == '\\')
		ft_putchar('\\');
	else if (c == '0')
		ft_putchar('\0');
	else
		return (0);
	return (1);
}

void	do_printing(char **str, int i)
{
	int	j;

	j = i;
	while (str[j])
	{
		ft_printf(1, "%s", str[j]);
		if (str[j + 1])
			ft_printf(1, " ");
		j++;
	}
}

int	check_for_errors(t_vector *redi)
{
	t_redirection	*red;
	int				i;

	red = (t_redirection *)redi->array;
	i = 0;
	while (i < (int)redi->length)
	{
		if (is_close_red(red))
			return (1);
		i++;
	}
	return (0);
}

int	ft_echo(char **str, t_vector *red)
{
	int	i;
	int	opt;

	i = 1;
	opt = 0;
	if (check_for_errors(red))
	{
		ft_printf(2, "42sh: echo: write error: Bad file descriptor\n");
		g_exit_status = 1;
		return (g_exit_status);
	}
	while (!ft_strcmp("-n", str[i]))
	{
		opt = 1;
		i++;
	}
	do_printing(str, i);
	if (opt == 0)
		ft_printf(1, "\n");
	g_exit_status = 0;
	return (g_exit_status);
}
