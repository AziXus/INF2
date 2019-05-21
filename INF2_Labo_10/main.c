#include <stdio.h>
#include <stdlib.h>
#include "book_index.h"


int main(void) {
    const char texte[] = "je\nteste\nnotre\nprogramme";
    Headings* h = remplirIndex(texte);
    afficherIndex(h);
    
    return EXIT_SUCCESS;
}

