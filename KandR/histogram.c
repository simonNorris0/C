#include <stdio.h>

#define MAXHIST 15 /* maximum length of histogram bars */
#define MAXWORD 11 /* maximum word length to record    */
#define IN 1
#define OUT 0

int main() {
    /* fields */
    /* ------ */
    int c, i, nc;    /* current char, array initializer, number of chars 
                        in current word */
    int state;       /* inside or outside of a word. */
    int len;          
    int maxvalue;    /* stores the highest frequency in the histogram */ 
    int overflow;    /* count of words longer than MAXWORD */
    int wl[MAXWORD]; /* int array that stores the histogram. The array 
                        indices represent the number of characters in 
                        a word and the value at those positions stores 
                        the frequency of which words of that length 
                        were seen.                   */

    /* initializations */
    state = OUT;
    nc = len = maxvalue = overflow = 0;

    for(i = 0; i < MAXWORD; i++)
        wl[i] = 0;

    /* building the histogram */
    /* ---------------------- */
    /* while the next char c is not EOF */
    while((c = getchar()) != EOF) {
        /* if c is a whitespace character */
        if(c == ' '  || c == '\n' || c == '\t')
        {
            /* move outside of word */
            state = OUT;
            /* if the number of chars in the finished word 
             * was greater than 0 */
            if(nc > 0)
            {
                /* if the finished word doesn't exceed the length of the
                 * size limit defined by MAXWORD */
                if(nc < MAXWORD)
                    ++wl[nc]; /* increase the count on the histogram
                                 for the words of the length of the 
                                 finished word */
                else
                    ++overflow; /* otherwise increase the count of words 
                                   that exceeded MAXWORD */
            }
            // next, set the number of characters stored to 0 for the next 
            // word.
            nc = 0;
        }
        /* if c is not a whitespace character, and currently outside 
         * of a word */
        else if(state == OUT)
        {
            /* move into a word */
            state = IN;
            nc = 1; /* record the first letter */
        }
        /* otherwise.. */ 
        else /* already inside a word */
            ++nc; /* increase the character count */
    }
    
    /* reporting the histogram */
    /* ----------------------- */
    /* for each position in the histogram, or each length of word stored */
    for(i = 1; i < MAXWORD; ++i)
    {
        /* if the value stored for this length of word is greater 
         * than the largest value seen */
        if(wl[i] > maxvalue)
            maxvalue = wl[i]; /* record value at wl[i] as the highest known
                                 frequency occuring in the histogram */
    } 
    /* again, each position in the histogram, or each length of word stored */
    for(i = 1; i < MAXWORD; ++i)
    {
        /* print the length of the word and then the frequency of words of 
         * that length in the input. Buffer 5 input character for 
         * each entry */
        printf("%5d - %5d : ", i, wl[i]);
        /* if the count of occurences for the length of word is greater 
         * than 0 */
        if(wl[i] > 0)
        {
            /* REVIEW somehow this normalizes the histogram */
            if((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        }
        /* if the frequency recorded for the length of word is less than 
         * or equal to 0 */
        else
            len = 0;

        while(len > 0)
        {
            putchar('*'); /* add to the bar for this class */
            --len;
        }
        putchar('\n');
    }

    if (overflow > 0)
        printf("There are %d words >= %d\n", overflow, MAXWORD);

    return 0;
}
