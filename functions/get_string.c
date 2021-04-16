#include <stdio.h>
#include <stdlib.h>

char *get_string(int maxlen)
{
   char *string = malloc((maxlen+1)*sizeof(char));
   int buff;
   int k = 0;
   // Il vaut mieux mettre un || plutot ?
   while ((buff = getchar()) != '\n' && k < maxlen)
   {
      string[k] = buff;
      k++;
   }
   string[k] = '\0';
   return string;
}
