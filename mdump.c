#include <signal.h>
#include <setjmp.h>
#include "mdump.h"

jmp_buf env;

// segment violation signal handler
void on_sigsegv (int param)
{
    longjmp (env, 1);
}

void mdump(FILE *stream, char *ptr, unsigned int size) {

    void (*prev_handler)(int);

    int val;

      
    // fa in modo che siano righe tutte uguali
    if((size % COLS) != 0)
        size = size + (COLS - (size % COLS));
    
    unsigned int i;
    
    char s[COLS + 1];   // vettore per il contnuto in formato stringa                
    s[COLS] = '\0';     // ultimo carattere fine stringa

    for(i = 0; i < size; i++)
    {
        // prima cella di memoria della riga
        if((i % COLS) == 0)
            fprintf(stream, "%p: ", ptr);            

        if(val = setjmp(env) == 0)
        {
            // cattura il segnale SEGMENT VIOLATION
            prev_handler = signal (SIGSEGV, on_sigsegv);

            // contenuto della cella di memoria            
            char c = *(ptr++);            

            // se il carattere non è stampabile, mette un .
            if(isprint(c))
                s[i % COLS] = c;
            else
                s[i % COLS] = '.'; 
                        
            // stampa il contenuto della cella
            fprintf(stream, "%02x ", 0xFF & c);

        }

        else
        { 
            s[i % COLS] = '.';           
            // stampa il contenuto della cella
            fprintf(stream, "?? ");

        }
        

        // ultima cella di memora della riga, stampa la strinfa di caratteri                
        if(((i+1) % COLS) == 0)
            fprintf(stream, "%s\n", s);            
            
        
    }
    
}

