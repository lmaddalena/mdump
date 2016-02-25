#include "mdump.h"



void mdump(FILE *stream, char *ptr, unsigned int size) {
    
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

        // contenuto della cella di memoria
        char c = *(ptr++);
        
        // se il carattere non è stampabile, mette un .
        if(isprint(c))
            s[i % COLS] = c;
        else
            s[i % COLS] = '.'; 
            
       
        // stampa il contenuto della cella
        fprintf(stream, "%02x ", 0xFF & c);

        // ultima cella di memora della riga, stampa la strinfa di caratteri                
        if(((i+1) % COLS) == 0)
            fprintf(stream, "%s\n", s);            
            
        
    }
    
}

