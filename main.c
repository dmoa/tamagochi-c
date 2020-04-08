#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Tamagotchi
{
    char *art[4];
    int art_height;
    bool bored;
    bool hungry;
    bool happy;
};

void take_input()
{
    getchar();
}

void print_tamagotchi(struct Tamagotchi tamagotchi)
{
    for(int i = 0; i < tamagotchi.art_height; i++)
    {
        printf("%s\n", tamagotchi.art[i]);
    }

    printf("\n");

    if (tamagotchi.bored)
    {
        printf("Your pet is bored :(\n");
    }
    else
    {
        printf("Your pet is having fun!");
    }
    if (tamagotchi.hungry)
    {
        printf("Your pet is hungry :(\n");
    }
    else
    {
        printf("Your pet is not hungry!");
    }
    if (tamagotchi.happy)
    {
        printf("Your pet is happy!\n");
    }
    else
    {
        printf("Your pet is sad :(\n");
    }

    printf("\nType command + enter\n- or type help\n");
}

int main ()
{
    // FILE * fp;
    // fp = fopen ("data.txt", "w+");
    // fprintf(fp, "%s", "\nAre\nCool");
    // fclose(fp);

    struct Tamagotchi tamagotchi =
    {
        {
            "           __  ",
            "      (___()'`;",
            "      /,    /` ",
            "      \\\\'--\\\\  "
        }, 4, 1, 1, 1
    };

    print_tamagotchi(tamagotchi);

    take_input();

    return(0);
}