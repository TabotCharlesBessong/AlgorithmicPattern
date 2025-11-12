#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool startsWith(const char *str, const char *prefix)
{
  return strncmp(str, prefix, strlen(prefix)) == 0;
}

char *longestCommonPrefix(char strs[][100], int n)
{
  static char prefix[100];
  strcpy(prefix, strs[0]);

  for (int i = 1; i < n; i++)
  {
    while (!startsWith(strs[i], prefix))
    {
      prefix[strlen(prefix) - 1] = '\0';
      if (strlen(prefix) == 0)
      {
        return "";
      }
    }
  }

  return prefix;
}

int main()
{
  char strs[3][100] = {"flower", "flow", "flight"};
  printf("%s\n", longestCommonPrefix(strs, 3));
  return 0;
}
