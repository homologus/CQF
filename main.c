#include <stdio.h>
#include "hashutil.h"
#include "gqf.h"
#include "gqf_int.h"
#include "gqf_file.h"


int main()
{
    QF new_qf;
    void *buffer;

    int qbits=6;
    uint64_t nhashbits = qbits + 9;
    uint64_t nslots = (1ULL << qbits);
    uint64_t nvals = 75*nslots/100;
    uint64_t key_count = 10000000;
    uint64_t *vals;

    if (!qf_malloc(&new_qf, nslots, nhashbits, 0, QF_HASH_INVERTIBLE, 0)) {
             fprintf(stderr, "Can't allocate CQF.\n");
    }

    int x;
    x= qf_insert(&new_qf, 1000, 1, 2, QF_KEY_IS_HASH);
    printf("%i\n", x);
    x= qf_insert(&new_qf, 10000, 1, 1, QF_KEY_IS_HASH);
    printf("%i\n", x);

    uint64_t cur_count = qf_count_key_value(&new_qf, 1000, 1, QF_KEY_IS_HASH);

    printf("%i\n", cur_count);
}
