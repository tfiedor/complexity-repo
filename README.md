# complexity-repo
Just an example repository for perun.

Example generation of the profile using job:

``
$ perun run job -b bin -c complexity -cp complexity job.yml

``

Example generation of the profile using collect:

``
$ perun collect -c complexity complexity -t ./target -f ./cpp_sources/test_workload/main.cpp -f ./cpp_sources/test_workload/SLList.h -f ./cpp_sources/test_workload/SLListcls.h -r SLList_init -r func1 -r SLList_insert -r SLList_search -r SLList_destroy -r SLListcls -r ~SLListcls -r Insert -r Remove -r Search -s SLList_insert 1 -s func1 1 -if trace.log -is 20000

``
