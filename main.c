#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// char to int
static inline int ctoi(char input)
{
    return ((int) input) - 48;
}

struct Tamagotchi
{
    char *text_arts[4];

    int art_height;
    bool bored;
    bool hungry;
    bool happy;
} typedef Tamagotchi;

enum Command {
    Throw_Ball,
    Feed,
    Kill,
    Pet,
    Wash
} typedef Command;

void take_input(Tamagotchi* tamagotchi)
{
    char input = getchar();
    printf("\n");
    if (input == 'h')
    {
        printf("1 - Throw Ball\n2 - Feed\n3 - Kill\n4 - Pet\n5 - Wash\n");
    }
    // if it's a digit, then we know it's a specific command relating to tamagotchi
    else if (isdigit(input))
    {
        // Commands start at 1, enums start at 0, so we do - 1 to correct the offset.
        int cmd = (Command) ctoi(input) - 1;

        switch (cmd)
        {
            case Throw_Ball:
                printf("Threw Ball!\n");
                break;
            default:
                printf("Number not corresponding to any command, try again!\n");
                break;
        }
    }
}

// print text art and statuses
void print_tamagotchi(Tamagotchi* tamagotchi)
{
    for (int i = 0; i < tamagotchi->art_height; i++)
    {
        printf("%s\n", tamagotchi->text_arts[i]);
    }

    printf("\n");

    if (tamagotchi->bored)
    {
        printf("Your pet is bored :(\n");
    }
    else
    {
        printf("Your pet is having fun!");
    }
    if (tamagotchi->hungry)
    {
        printf("Your pet is hungry :(\n");
    }
    else
    {
        printf("Your pet is not hungry!");
    }
    if (tamagotchi->happy)
    {
        printf("Your pet is happy!\n");
    }
    else
    {
        printf("Your pet is sad :(\n");
    }

    printf("\nType command + enter\n- or type h for help\n");
}

int main ()
{
    Tamagotchi tamagotchi =
    {
        {
            "           __  ",
            "      (___()'`;",
            "      /,    /` ",
            "      \\\\'--\\\\  "
        }, 4, 1, 1, 1
    };

    print_tamagotchi(& tamagotchi);

    while (true) {
        take_input(& tamagotchi);
    }

    return(0);
}