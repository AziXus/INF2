#include <stdio.h>
#include <stdlib.h>
#include "book_index.h"


int main(void) {
    const char texte[] = "The five boxing\nwizards jump quickly.\n\nPack my box with five\ndozen liquor jugs.";
    Headings* h = remplirIndex(texte);
    afficherIndex(h);
    return EXIT_SUCCESS;
}

