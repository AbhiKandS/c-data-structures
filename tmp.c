#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fileCsv = fopen("School email - Sheet1(1).csv", "r");
    FILE *fileOut = fopen("Output.csv", "w");
    if (fileCsv == NULL || fileOut == NULL)
    {
        printf("File not opened!!\n");
        return 1;
    }
    char c;
    while ((c = getc(fileCsv)) != EOF)
    {
        if (c != '[')
            fputc(c, fileOut);
        else
        {
            char next = getc(fileCsv);
            fseek(fileCsv, -1, SEEK_CUR);
            if (next == 'a')
            {
                fputc('@', fileOut);
                fseek(fileCsv, 3, SEEK_CUR);
            }
            else if (next == 'd')
            {
                fputc('.', fileOut);
                fseek(fileCsv, 4, SEEK_CUR);
            }
            else
                fputc(c, fileOut);
        }
    }
    printf("Completed\n");
    fclose(fileCsv);
    fclose(fileOut);
    fileCsv = fileOut = NULL;
    return 0;
}