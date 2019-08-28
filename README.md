# CQF (Counting Quotient Filter) from Prashant Pandey

## Source github repo

https://github.com/splatlab/cqf

## Overview

The CQF supports approximate membership testing and counting the occurrences of
items in a data set. This general-purpose AMQ is small and fast, has good
locality of reference, scales out of RAM to SSD, and supports deletions,
counting (even on skewed data sets), resizing, merging, and highly concurrent
access.

## API

* 'qf_insert(item, count)': insert an item to the filter
* 'qf_count_key_value(item)': return the count of the item. Note that this
  method may return false positive results like Bloom filters or an over count.
* 'qf_remove(item, count)': decrement the count of the item by count. If count
  is 0 then completely remove the item.


## Example Code

### Declarations

~~~~~~~
QF new_qf;
void *buffer;
int qbits=6;
uint64_t nhashbits = qbits + 9;
uint64_t nslots = (1ULL << qbits);
uint64_t nvals = 75*nslots/100;
uint64_t key_count = 10000000;
uint64_t *vals;
~~~~~~~

### Create CQF filter

~~~~~~~~
if (!qf_malloc(&new_qf, nslots, nhashbits, 0, QF_HASH_INVERTIBLE, 0)) {
         fprintf(stderr, "Can't allocate CQF.\n");
}
~~~~~~~~

### Insert in CQF filter

~~~~~~~~
int x;
x= qf_insert(&new_qf, 1000, 1, 2, QF_KEY_IS_HASH);
~~~~~~~~

### Retrieve from CQF filter

~~~~~~~~
uint64_t cur_count = qf_count_key_value(&new_qf, 1000, 1, QF_KEY_IS_HASH);
~~~~~~~~


## Paper

https://www3.cs.stonybrook.edu/~ppandey/files/p775-pandey.pdf

This work appeared at SIGMOD 2017. If you use this software please cite us:

```
@inproceedings{DBLP:conf/sigmod/PandeyBJP17,
  author    = {Prashant Pandey and
               Michael A. Bender and
               Rob Johnson and
               Robert Patro},
  title     = {A General-Purpose Counting Filter: Making Every Bit Count},
  booktitle = {Proceedings of the 2017 {ACM} International Conference on Management
               of Data, {SIGMOD} Conference 2017, Chicago, IL, USA, May 14-19, 2017},
  pages     = {775--787},
  year      = {2017},
  crossref  = {DBLP:conf/sigmod/2017},
  url       = {http://doi.acm.org/10.1145/3035918.3035963},
  doi       = {10.1145/3035918.3035963},
  timestamp = {Wed, 10 May 2017 22:12:12 +0200},
  biburl    = {http://dblp.org/rec/bib/conf/sigmod/PandeyBJP17},
  bibsource = {dblp computer science bibliography, http://dblp.org}
}
```


