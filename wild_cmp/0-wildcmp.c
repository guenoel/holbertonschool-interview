
/**
 * wildcmp - Compares two strings with wildcard
 * @s1: First string
 * @s2: Second string with wildcard
 *
 * Return: 1 if strings are identical, 0 otherwise
*/
int wildcmp(char *s1, char *s2)
{
	int i, j = 0;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
	{
		if (*s1 == '\0') /* If s1 reaches the end but s2 still has '*' */
			return (wildcmp(s1, s2 + 1)); /* Recursively check without '*' */
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
		/* Check if '*' represents empty string or move forward in s1 */
	}
	if (*s1 == *s2) /* If characters match */
		return (wildcmp(s1 + 1, s2 + 1)); /* Move to next characters */
	return (0); /* If none the above conditions met, strings are not identical */
}
