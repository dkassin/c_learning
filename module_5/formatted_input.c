#include <stdio.h>

int main(void)
{
    FILE *fp;
    char name[1024];
    float length;
    int mass;

    fp = fopen("whales.txt", "r");

    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
        printf("%s whales, %d tonnes, %.1f meters\n", name, mass, length);
    
    fclose(fp);
}