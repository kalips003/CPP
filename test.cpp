#include <iostream>
/*******************************************************************************
******************************************************************************/
// <!> - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  </!>
///////////////////////////////////////////////////////////////////////////////]
/*******************************************************************************

			░█████╗░  ███████╗░█████╗░██╗██████╗░███████╗
			██╔══██╗  ██╔════╝██╔══██╗██║██╔══██╗██╔════╝
			███████║  █████╗░░███████║██║██████╔╝█████╗░░
			██╔══██║  ██╔══╝░░██╔══██║██║██╔══██╗██╔══╝░░
			██║░░██║  ██║░░░░░██║░░██║██║██║░░██║███████╗
			╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝╚══════╝





Setting Limits

You can set various limits using ulimit. Here are some common options:

    Core file size (-c): The maximum size of core files created.
    Data segment size (-d): The maximum size of the data segment for a process.
    File size (-f): The maximum size of files created by the shell.
    Number of open files (-n): The maximum number of file descriptors a process can have.
    Stack size (-s): The maximum stack size for a process.
    CPU time (-t): The maximum amount of CPU time a process can use.
    Virtual memory (-v): The maximum amount of virtual memory available to a process.




<?> .PHONY: test - This declares that test is a phony target,
	meaning it's not associated with a file. </?>

// MACRO
// #define funct(ap, type)    (*(type *)((ap += sizeof(type)) - sizeof(type)))
******************************************************************************/
#define PI 3.14159265358979323846
#define BUF_WD 1024
///////////////////////////////////////////////////////////////////////////////]
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////]