#include <stdio.h>
#include <stdlib.h>
#include "book_index.h"


int main(void) {
    const char texte[] = "c\nb e\nd f aabc\na";
    Headings* h = remplirIndex(texte);

    afficherIndex(h);
    
    return EXIT_SUCCESS;
}

