# complexity-repo
Just an example repository for perun.

To show generated profiles run:

```
  $ perun --no-pager status
```

Alternatively to distinguish between different configurations you can add `-w workload` or
`-c command` parameters. These do not change the collection process of the complexity collector,
however, are used in the resulting collected profile. The following will generate the file
`cmd-complexity-wl-time.perf`:

```
  $ perun collect -c cmd -w wl -p configurations/simple_sll.yml complexity
```

To postprocess the generated profile with regression analysis run:

```
   $ perun postprocessby 0@p regression_analysis --method=full
```
Where `0@p` and `0@i` stands for first profile in the `.perun/jobs` directory and perun index
respectively.

To visualize the collected data along with inferred models run:

```
  $ perun show 0@p scatter -v
```

Note that `show` command will open the bokeh visualizations in the browser (might take a while for
huge profiles).

For help use the following:

```
  $ perun run job --help
  $ perun postprocessby --help
  $ perun collect --help
  $ perun collect complexity --help
  $ perun show --help
```

# Simple Toy SLL

Just an example with Single Linked List usage

```
  $ perun collect -p configurations/simple_sll.yml complexity
```

# Compare Sorts

To reproduce the jobs from the original `compare_sorts.py` run:

```
  $ perun collect -p configurations/compare_sorts.yml complexity
```

# Methods Overview

Full computation (substitute 2@p for generated profile):

```
  $ perun collect -p configurations/methods_full.yml complexity
  $ perun postprocessby 2@p regression_analysis --method=full
```

Iterative computation (substitute 4@p for generated profile):

```
  $ perun collect -p configurations/methods_iterative.yml complexity
  $ perun postprocessby 4@p regression_analysis --method=iterative
```

Computation with initial guess (substitute 6@p for generated profile):

```
  $ perun collect -p configurations/methods_init_guess.yml complexity
  $ perun postprocessby 6@p regression_analysis --method=initial_guess
```

Computation with interval (substitute 8@p for generated profile):

```
  $ perun collect -p configurations/methods_interval.yml complexity
  $ perun postprocessby 8@p regression_analysis --method=interval
```

# Quicksort Inputs

To collect all of the various inputs run the following:

```
  $ perun collect -p configurations/quicksort_random.yml complexity
  $ perun collect -p configurations/quicksort_reversed.yml complexity
  $ perun collect -p configurations/quicksort_sorted.yml complexity
  $ perun collect -p configurations/quicksort_badpartition_random.yml complexity
  $ perun collect -p configurations/quicksort_badpartition_reversed.yml complexity
  $ perun collect -p configurations/quicksort_badpartition_sorted.yml complexity
```

# Skiplists Experiments

To collect data for different heights of skiplists run the following:

```
  $ perun collect -p configurations/skiplist_height_low.yml complexity
  $ perun collect -p configurations/skiplist_height_medium.yml complexity
  $ perun collect -p configurations/skiplist_height_probability.yml complexity
  $ perun collect -p configurations/skiplist_height_unlimited.yml complexity
```

# Skiplist vs List Experiments

To collect data for comparison of skiplists and lists run the following:
```
  $ perun collect -p configurations/skiplist_vs_list_list_search.yml complexity
  $ perun collect -p configurations/skiplist_vs_list_skiplist_search.yml complexity
  $ perun collect -p configurations/skiplist_vs_list_skiplist_optimized_search.yml complexity
```