### GCC

* -MM: Like -M but do not mention header files that are found in system header directories, nor header files that are included, directly or indirectly, from such a header.
* -MF: When used with -M or -MM, specifies a file to write the dependencies to
* -MP: This option instructs CPP to add a phony target for each dependency other than the main file, causing each to depend on nothing.
* -MT: Change the target of the rule emitted by dependency generation. (we can use the full path in the dependency rules)
* -g: Produce debugging information in the operating system's native format 
* -Werror: Make all warnings into hard errors. Source code which triggers warnings will be rejected.
* -Wextra: This enables some extra warning flags that are not enabled by -Wall
* -std=c99: Specify the standard to which the code should conform (c99 iso9899:199x)
* -pedantic: Issue all the mandatory diagnostics listed in the C standard. Some of them are left out by default, since they trigger frequently on harmless code.
* -D=_GNU_SOURCE: request additional features (not only the ISO C library features)


### Astyle

* install the tool: sudo apt-get install astyle
* runt the tool: astyle -t -l -k1 foo.c
