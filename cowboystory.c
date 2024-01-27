#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <cs50.h>
#include <time.h> //used for generating random values for duel
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h> //used to wait between printing statements, use USLEEP from midterm

int Points = 1; //global variable for points

int bandit_fight (int a, int b); //used for duel in the wilder west

int main(void)
{
    //intro
    printf("\n    /You find yourself in a dusty, old-timey, wild-wild-west type of saloon. Glasses clink and low voices\n");
    printf ("mumble. You notice a tattoo on your wrist that reads \"Points: 1\" that you're certain you didn't have before.\n");
    printf ("A stool scrapes against the floor in front of you, and you look up. A smiling patron greets you./\n\n");

    usleep(5000000);

    //see if the user/player wishes to continue
    char c = get_char("Σ|:) Howdy, I'm Cowboy Jim! I reckon you're new to these parts? y/n: ");
    c = tolower(c);

        //if the user is new to these parts
        if (c == 'y')
        {
            printf("Σ|:) A bonafide outta towner, eh?");
            usleep(1000000);

           //get name
            string name = get_string(" Any way I could get your name, pardner? ");
            printf("\nΣ|:D Ah, howdy %s! lemme show you 'round.\n\n", name);
            usleep(1000000);
            printf("    /You leave the saloon, and enter the town square./\n\n");

            usleep(1000000);

            //declare direction
            char direction;

            //loops to allow you to explore all areas (until character death or user quitting)
            do {
                //allows you to choose where to go:
                printf("Σ|:) Where to, %s? I've got my trusty compass on me, any direction N, S, E, or W will do.\n", name); //d = direction
                usleep(1000000);
                direction = get_char("\n    /You somehow know that inputting Q while you stand in the town square will allow you to leave town./\n");
                direction = tolower(direction);

                //north part of town, stables:
                if (direction == 'n')
                {
                    printf("\n    /You see a worn down stable bookended by stacks of spitoons./\n");
                    usleep(1000000);
                    char look = get_char("\nΣ|:) That's where I keep my best horse, Bessy. Fancy a look inside? y/n: ");
                    look = tolower(look);
                    //choosing to go inside
                    if (look == 'y')
                    {
                        printf("Σ|:D Yippee! \n\n");
                        usleep(1000000);
                        printf("    /Jim leads you into the rickety, dark, smelly stables. He inhales, savoring the\n");
                        printf("horse-smell, and reaches up to light a kerosene lamp. You can see a beautifully\n");
                        printf("inscribed leather saddle that reads 'Bessy', next to the only well lit stall. Bessy\n");
                        printf("herself is well groomed, with a braided mane decorated with dried flowers, and\n");
                        printf("sporting the shiniest brown coat you ever did see. You look back at Jim, and he smiles./\n\n");
                        usleep(6000000);
                        char pet = get_char("Σ|:) My daughter just lo-o-oves pampering my Bessy, and I don't mind none. Wanna pet her? y/n: ");
                        pet = tolower(pet);

                        //choosing to pet Bessy
                        if (pet == 'y')
                        {
                            printf("\n    /You pet Bessy./\n\n");
                            usleep(1000000);
                            printf("Σ|:D  Ain't she just the best, %s? Anyhoo, let's get a wiggle on.\n\n", name);
                            usleep(1000000);
                            Points += 1; //point for petting bessy
                        }

                        //choosing not to pet Bessy
                        else if (pet == 'n')
                        {
                            usleep(1000000);
                            printf("Σ|:( Your loss, I suppose.\n");
                            usleep(1000000);
                            Points -= 1; //subtract a point for not petting bessy
                        }

                        Points += 1; //point for visiting stables
                        printf("\n    /You feel a sharp pain on your wrist, and look down. ");
                        printf("Your mysterious tattoo \nnow reads \"Points: %i\"./\n", Points); // ***POINT
                        printf("\n    /You leave the stables, and return to the town square./\n\n");
                        usleep(1000000);
                    }
                    //choosing not to go inside
                    else if (look == 'n')
                    {
                        //no points - didnt visit stables or pet bessy
                        printf("Σ|:( Aw, alrighty then.\n");
                        printf("\n    /You leave the stables, and return to the town square./\n\n");
                        usleep(1000000);
                    }
                }

                //south part of town, vampires (spoilers!):
                else if (direction == 's')
                {
                    printf("\n    /You see the saloon you found yourself in earlier. Some women talk outside, but\n");
                    printf("get quiet when you approach, as if they had been talking about you.../\n\n");
                    usleep(3000000);
                    printf("Σ|:) Howdy ladies!\n");
                    usleep(1000000);
                    printf("\n    /They sneer, and their canine teeth look a tad sharper than usual. Something tells you\n");
                    printf("that maybe you should leave them alone. Jim turns to you and whispers./\n\n");
                    usleep(3000000);

                    char women = get_char ("Σ|:/ These uh... fine women... are givn' me the collywobbles. What d'ya say we get outta here? y/n: ");
                    women = tolower(women);

                    //choosing to run away from women
                    if (women == 'y')
                    {
                    printf("\nΣ|:{  Alright %s, let's mizzle!!\n", name);
                    usleep(1000000);
                    }

                    //choosing to stay near women
                    else if(women == 'n')
                    {
                        printf("\nΣ|:{ Oh... whatever you say, %s.\n", name);
                        usleep(1000000);

                        //your gender decides your fate
                        char gender = get_char("\n    /What is your gender identity? (m/f/x)/\n");
                        gender = tolower(gender);

                        //result if f is input
                        if (gender == 'f')
                        {
                            printf("\n    /Despite their outwardly menacing appearance, you see a warmth behind their eyes. You feel\n");
                            printf("compelled to kneel and as you look back up at the women, you realize they are vampires. They\n");
                            printf("ask you to join them. You must join them. You cannot resist. Jim slowly backs away./\n\n");
                            usleep(6000000);
                            printf("Final Point Total: %i\n", Points);
                            break;
                            //undead
                        }

                        //result if m is input
                        else if (gender == 'm')
                        {
                            printf("\n    /Their penetrating gaze chills you to the bone. You hardly have a chance to react when\n");
                            printf("all three ladies dive for your neck. You now realize the women are vampires as Jim screams and\n");
                            printf("runs to get help, and you quickly lose consciousness./\n\n");
                            usleep(6000000);
                            printf("Final Point Total: %i\n", Points);
                            break;
                            //dead
                        }

                        //result if x is input
                        else if (gender == 'x')
                        {
                            printf("\n    /The women, who you knew were vampires from the first you saw them, smile\n");
                            printf("fondly at you. They each whisper a half-audible blessing in your ear, gaze\n");
                            printf("with a somewhat longing hunger at Jim, and let you both be on your way./\n\n");
                            usleep(6000000);
                            //alive
                            Points += 1; //point for surviving (you decided your character is non-binary)
                            printf("    /You feel a sharp pain on your wrist, and look down. ");
                            printf("Your mysterious tattoo \nnow reads \"Points: %i\"./\n", Points); //***POINT
                        }
                    }


                    printf("\n    /You leave the saloon, and return to the town square./\n\n");
                    usleep(1000000);
                }

                //east part of town, definitely-not-wild east:
                else if (direction == 'e')
                {
                    printf("\nΣ|XD What d'ya think this is, the wild, wild *east*? Let's meander elsewhere, pardner.\n");
                    usleep(2000000);
                    Points += 1; //point for exploring
                    printf("\n    /You feel a sharp pain on your wrist, and look down. ");
                    printf("Your mysterious tattoo \nnow reads \"Points: %i\"./\n", Points); //***POINT
                    printf("\n    /You both return to the town square./\n\n");
                    usleep(1000000);
                }


                //west part of town, wilder west:
                else if (direction == 'w')
                {
                    printf("\n    /You see even wilder, wilder west. You feel drawn to it. Jim holds you back, for your own safety./\n");
                    usleep(1000000);
                    printf("\nΣ|:/ Nothing to see here, pardner.\n");
                    usleep(1000000);
                    printf("\n    /As you're both about to return to the town square.../\n");
                    usleep(3000000);
                    printf("    /A group of three bandits approach!/\n");
                    usleep(2000000);
                    printf("\n>B( Hey, tenderfoot!\n");
                    usleep(2000000);
                    printf("\n    /Jim tells you that this is wilder-wilder-west speak for \"outta towner\". You thank him for the\n");
                    printf("translation./\n");
                    usleep(3000000);
                    printf("\n>B( Put yer hands up, ya namby-pamby half-wit!\n");
                    usleep(1000000);

                    //will you fight the bandits?
                    char stickup = get_char("\n    /Will you stand your ground? y/n/: ");
                    stickup = tolower(stickup);

                    //you give in to their demands
                    if (stickup == 'n')
                    {
                        printf("\n>B) Perfect.\n");
                        usleep(1000000);
                        Points -= 1;
                        printf("\n    /The bandits search you and take all of your belongings. A sudden itching pain appears\n");
                        printf("in your wrist and your mysterious tattoo now reads \"Points: %i\"./\n", Points); //***POINT
                        usleep(2000000);
                    }

                    //you stand up for yourself
                    else if (stickup == 'y')
                    {
                        printf("\n    /The bandits get a meaner look in their eyes, and Jim hands you a dueling pistol. You take a deep breath.\n");
                        printf("All three bandits line up facing one way, and you face the other, and you all walk 10 paces. You're pretty sure\n");
                        printf("that this isn't how duels usually work, but you're not exactly in a position to protest./\n\n");

                        int HP = 3; //bandit health
                        int injury = 0; //# of injuries

                        //function used to find outcome of the fight
                        int outcome = bandit_fight (HP, injury);

                        //you died
                        if (outcome == 1)
                        {
                            printf("Final Point Total: %i\n", Points);
                            break;
                        }

                        //you lived
                        else if (outcome == 0)
                        {
                            printf("\n    /You survived the wilder, wilder west!/\n");
                            usleep(1000000);
                            printf("    /You both return to the town square./\n\n");
                            usleep(1000000);
                        }

                        //impossible case
                        else
                        {
                            usleep(1000000);
                            printf("    /What? This shouldn't be possible. The wild west around you dissolves and you find yourself\n");
                            printf("in an empty white room with no doors or windows. Good luck with that. Bye, %s./\n", name);
                            break;
                        }
                    }
                }

                //leaving town
                else if (direction == 'q')
                {
                    printf("\nΣ|:) See ya 'round, pardner!\n\n");
                    usleep(1000000);
                    printf("Final Point Total: %i\n", Points);
                    break;
                }

            //ending loop:
            } while (direction != 'q');

        }

        //if the user is not new to these parts
        else if (c == 'n')
        {
            printf("Σ|:( Ah, sorry to bother ya. See ya 'round!\n");
            printf("\nFinal Point Total: %i\n", Points);
        }

        //if the user is confused about these parts
        else
        {
            printf("Σ|:( Sorry pardner, I don't understand.\n");
            printf("\nFinal Point Total: %i\n", Points);
        }
}


int bandit_fight (int a, int b)
{
    //creating time variable t
    time_t t;

    //seeding random numbers against unix time
    srand((unsigned) time(&t));

    usleep(5000000);

    do
    {
        //randomize function from 1 to 10
        int random = (rand() % 10) + 1;

        printf("    /You each fire your dueling pistols./\n");
        usleep(1000000);

        //if the random number is greater than 7, the bandits manage to hit you
        if (random > 7)
        {
            Points -= 1;
            printf("    /You've been hit by a bandit! A pain in your wrist accompanies the pain of the bullet wound, and the tattoo now\n");
            printf("reads \"Points: %i\"./\n", Points);
            usleep(1000000);
            b += 1; //injury
        }

        //if the number is less than seven, you hit the bandits
        else
        {
            printf("    /You successfully hit a bandit!/\n");
            a -= 1; //HP
        }
        usleep(1000000);

    } while((a > 0) && (Points > 0)); //ending loop if either party dies

    //the bandits died
    if (a == 0) //HP
    {
        printf("\n    /With a final bang, the last bandit falls with a thud. Jim grabs your shoulder for reassurance./\n\n");
        usleep(2000000);
        printf("Σ|:/ We'd best be getting back, pardner.\n\n");
        usleep(2000000);

        //if you got hit
        if (b >= 1) //injury
        {
            printf("    /Jim helps you patch up all of your wounds, which takes a little while. You look off into the wilder west\n");
            printf("and quickly look away, to maintain your sanity. Instead, you take in his roughened cowboy face and strong yet\n");
            printf("careful hands, perfect for tying lassos and rounding up cattle. You thank him for his hospitality, and he tips\n");
            printf("his hat at you with a gruff \"No problem, pardner.\" He finishes, and helps you to take a few steps./\n");
            usleep(6000000);
        }

        //if you didnt get hit
        else
        {
            printf("    /Jim checks you for wounds, but you appear to be unscathed. You meet his eyes, and see a kindness and caring\n");
            printf("in them. He seems glad that you're okay./\n");
            usleep(3000000);
        }

        //you lived!
        printf("    /The two of you make your way back to the town square, a little shaken. An itching pain in your wrist\n");
        Points += 3; //one for each bandit
        printf("makes you look down to see that your tattoo now reads \"Points: %i\"./\n", Points);
        usleep(3000000);
        return 0;
    }

    //you died :(
    else if (Points == 0)
    {
        printf("\n    /Jim holds you as the light fades. You see a tear roll down his cheek./\n\n");
        usleep(2500000);
        printf("Σ|:( So long, pardner...\n\n");
        usleep(2500000);
        return 1;
    }

    //impossible case
    else
    {
        return -1;
    }
}


