#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len2;

	len2 = ft_strlen(needle);
	if (len2 == 0)
		return ((char*)haystack);
	while (*haystack && len2 <= len--)
	{
		if (!ft_strncmp(haystack, needle, len2))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
