#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

// char to int
static inline int ctoi(char input)
{
    return ((int) input) - 48;
}

// clear screen
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

struct Tamagotchi
{
    char* text_arts[4];
    char name [20];

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
    char input;
    scanf("%c", & input);

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
                printf("Threw Ball! Dog chasing after it!\n");
                sleep(2);
                printf("Dog ran back to you and handed you the ball.\n");
                break;
            default:
                printf("Number not corresponding to any command, try again!\n");
                break;
        }
    }
    else
    {
        printf("Bad input :|, h for help\n");
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

int main()
{
    Tamagotchi tamagotchi =
    {
        {
            "           __  ",
            "      (___()'`;",
            "      /,    /` ",
            "      \\\\'--\\\\  "
        }, "Dog McDog", 4, 1, 1, 1
    };

    printf("Pick a name for your dog: ");
    scanf("%s", & tamagotchi.name);
    int a = 0;

    while (true) {
        a++;
        print_tamagotchi(& tamagotchi);
        take_input(& tamagotchi);
    }

    return(0);
}