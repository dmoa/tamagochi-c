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
#define clear_screen() system("cls")
#else
#include <stdio.h>
#define clear_screen() system("clear")
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
    Wash,
    Status
} typedef Command;


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
        printf("%s is bored :(\n", tamagotchi->name);
    }
    else
    {
        printf("%s is having fun!", tamagotchi->name);
    }
    if (tamagotchi->hungry)
    {
        printf("%s is hungry :(\n", tamagotchi->name);
    }
    else
    {
        printf("%s is not hungry!", tamagotchi->name);
    }
    if (tamagotchi->happy)
    {
        printf("%s is happy!\n", tamagotchi->name);
    }
    else
    {
        printf("%s is sad :(\n", tamagotchi->name);
    }

    printf("\nType command + enter\n- or type h for help\n");
}

// recursive take_input functions
// - exits when you kill the dog
void take_input(Tamagotchi* tamagotchi)
{
    char input;
    scanf(" %c", & input);

    printf("\n");

    if (input == 'h')
    {
        printf("1 - Throw Ball\n2 - Feed\n3 - Kill\n4 - Pet\n5 - Wash\n6 - Status\n");
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
            case Kill:
                printf("You killed your dog :( The end.\n");
                return;
                break;
            case Status:
                print_tamagotchi(tamagotchi);
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

    take_input(tamagotchi);
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

    clear_screen();
    printf("Pick a name for your dog: ");
    scanf("%s", & tamagotchi.name);
    printf("\nTry entering a command:\n");

    take_input(& tamagotchi);

    return(0);
}