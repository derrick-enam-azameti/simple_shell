#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *input = NULL;
    size_t input_size = 0;
    ssize_t bytes_read;

    while (1)
    {
        printf("($) ");

        bytes_read = getline(&input, &input_size, stdin);

        if (bytes_read == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            else
            {
                perror("getline");
                break;
            }
        }

        if (input[bytes_read - 1] == '\n')
            input[bytes_read - 1] = '\0';
    }

    free(input);
    return (0);
}
