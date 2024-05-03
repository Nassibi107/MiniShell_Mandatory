#include "../../minishell.h"

int	grep(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (!ft_isalnum(s[i]))
			break ;
		i++;
	}
	return (i);
}

char	*grep_value(char *s)
{
	int		len;
	int		i;
	char	*r;

	len = 0x0;
	while (s[len])
	{
		if (!ft_isalnum(s[len]))
			break ;
		len++;
	}
	r = malloc(len + 0x1);
	if (!r)
		return (NULL);
	i = 0x0;
	while (i < len)
	{
		r[i] = s[i];
		i++;
	}
	r[len] = '\0';
	return (r);
}

char	*add_t(char *p, char *o)
{
	int	i;
	int	len;

	i = 0x0;
	if (ft_strlen(p) > 0x0 && o)
	{
		len = 0x0;
		while (p[len])
			len++;
		while (o[i])
		{
			p[len + i] = o[i];
			i++;
		}
	}
	else if (ft_strlen(p) == 0x0 && o)
	{
		while (o[i])
		{
			p[i] = o[i];
			i++;
		}
	}
	return (p);
}

int	even_odd(char *s)
{
	int	i;

	i = 0x0;
	while (s[i] && s[i] == '$')
		i++;
	if (i % 2 == 0x0)
		return (0x0);
	return (0x1);
}

int	non_requesed(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '$' && s[i])
			return (0x0);
		i++;
	}
	return (0x1);
}