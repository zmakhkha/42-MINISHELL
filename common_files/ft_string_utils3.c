
#include "../header.h"

int ft_voperator(char*str, char op)
{
    int i;

    i = 0;
    if (str[i] && str[i + 1] && str [i + 2])
    {
        if (str[i] == op && str[i + 1] == op && str[i + 2] == op)
            return (0);
    }
    if (str[i] && str[i + 1])
   {
        if (str[i] == op || str[i + 1] == op)
            return (1);
    }
    if (str[i])
    {
        if (str[i] == op)
            return (1);
    }
    
    return (0);
}

int ft_validouble(char *str, char op)
{
    int i;

    i = 0;
    if (str[i] && str[i + 1])
    {
        if (str[i] == op && str[i + 1] == op)
            return (1);
        else
            return (0);
    }
    return (0);
}
