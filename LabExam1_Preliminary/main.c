#include <stdio.h>

#define ARS 485
#define KOL 754
#define ANT 129
#define OBR 983
#define REP 555
#define UNF 205
#define IMP 107

#define ENGINEER 'E'
#define DOCTOR 'D'
#define DIPLOMAT 'P'
#define WORKER 'W'

#define MALE 'M'
#define FEMALE 'F'

int main()
{
    int n, day, nationality, visa, bribe, accepted, i = 0;
    char gender, occupation;

    /* read number of entrants */
    scanf("%d", &n);

    /* read all of the entrants */
    for (i = 1; i < n + 1; i++)
    {
        scanf(" %d %d %c %c %d %d", &day, &nationality, &gender, &occupation, &visa, &bribe);
        if (day == 1)
        {
            if ((nationality == KOL || nationality == OBR) && occupation != DIPLOMAT && bribe == 0 && visa == 1)
                accepted = 1;

            else if ((nationality == KOL || nationality == OBR) && occupation == DIPLOMAT && bribe == 0)
                accepted = 1;

            else if ((nationality == ARS || nationality == ANT || nationality == REP || nationality == UNF || nationality == IMP) && bribe == 0 && visa == 1)
                accepted = 1;

            else
                accepted = 0;
        }

        if (day == 2)
        {
            if (nationality == ARS && bribe == 0)
                accepted = 1;
            else
                accepted = 0;
        }

        if (accepted == 1)
            printf("Day #%d Person #%d ACCEPT\n", day, i);

        else
            printf("Day #%d Person #%d REJECT\n", day, i);
    }

    return 0;
}