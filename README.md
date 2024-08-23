# ft_printf
## The **objective** of this project
The function signature of "printf": int printf(const char *format, ...);<br>
（1）The return value is the number of characters successfully output, or negative when there is an error.<br>
（2）const char *format:<br>
A.constant char: To ensure the string cannot be modified through the pointer, cause it is the users' input.<br>
B.*format: In fact, it is indeed a pointer to a char, which is used to represent strings in C. Since it includes the format specifiers, so it is called "format".

## The **solution** of this project
1.The main function: <br>
int ft_printf(const char *format,...)，used to declare the variable argument list and specify the specific variable to use;<br>
2.Subfunction for ft_printf:<br>
static int ft_check_format(const char *format, va_list ap, int len)，used to check '%format' and print other normal characters.<br>
3.Subfunction for ft_check_format:<br>
static int ft_check_specifier(char spec, va_list ap)

## Useful Knowledge
### About variadic function
*Variadic function: They are indeed a group of macros defined in the head file <stdarg.h>.<be>
*Macro:  A macro is a fragment of code that is given a name. Whenever the name is used, it is going to be replaced by the content of the macro before compilation.<br>
1.va_start(arg, last_param):<br>
Purpose: Initializes the variable argument list and sets the pointer to the first argument.<br>
Note: This only initializes the variable argument list and does not retrieve the value of arg (value retrieval is done using va_arg).<br>
2.va_arg(arg, type):<br>
Purpose: Retrieves the current argument value and interprets it as the specified type.<br>
Note:<br>
If the type does not match, it will result in undefined behavior.<br>
If there is no next argument, the behavior is also undefined.<br>
3.va_end(arg):<br>
Purpose: Ends the traversal of the variable argument list and cleans up any resources.<br>
Note: Although va_end may do nothing in some implementations, it is required by the standard to be called.<br>

### About lib.a

1. The file extension of an archive, which is a file that encapsulates all of the compiled object files (.o). Archives are used for the modulargity of a program. Each archive can be treated as a module of the whole project.<br>
2.ar -rc *the name of the archive(.a)* *the object files the archive is going to encapsulate(.o)*<br>
3. gcc main.o lib.a -o *the name of the executable*<br>

### About different executable files
1.'a.out' is the default name of the executable on Unix-like systems. Note that .out is just part of the name, not a file extension. In fact, there is no specific file extension for executables on Unix-like systems.<br>
2.'.exe' is the file extension of the executable on Windows. Note the reason you get both of the test and the test.exe is that maybe your development environment is set up for cross-compilation.<br>

### About Makefile
#### Complication Process
1. Preprocess<br>
The compiler will process the preprocessor directives, such as #include and #define. After that, the original source file is expanded with all the headers and macro definitions. This means that the preprocessor will replace the directives with their corresponding content.<br>
2. Compilation<br>
The preprocessed code is then translated into assembly code, which acts as an intermediary between syntax code and machine code. Notice that syntax code cannot be directly transferred into machine code.<br>
3. Assembly<br>
The assembly code will be converted into machine code by the assembler, resulting in a binary **object** file(.o). This file contains the machine code and the related metadata, such as the symbol table.<br>
4. Linking<br>
The linker will combine multiple object files and libraries to produce the final executable file (.out/.exe).<br>

#### What is Makefile
1. Makefile is a build automation tool. It defines a set of rules and dependencies that dictate how to compile and link the program.<br>
2. Makefile will check the timestamps of all the targets and the dependencies to make sure that the output is the newest version. With Makefile, we don't have to recompile all the programs when there are changes in the original code.<br>

#### Makefile syntax
target: dependencies // target is created from dependencies<br>
(tab) the command for using dependencies to produce the target<br>

$(variable's name) // reference a defined variable<br>
$(variable's name:.c=.o) // references a defined variable, but replaces all '.c' with '.o'"<br>
$<// reference the first dependency<br>
$^// reference all the dependencies<br>
$@// reference the target<br>

%.o:%.c// match each of the object files and its corresponding source files<br>

OBJS // objects<br>
CC // c compiler<br>
RM // rm -f（default value）<br>

gcc // c compiler<br>
-c // specifically for compiling. When use without -c, gcc is for linking<br>
-o // specify the name of the output file(the default name should be a.out/a.exe)<br>
-Wall -Wextra -Werror // warning messages flags, warn all, extra warnings, warnings as errors<br>

rm // remove<br>
-r // -recursive, remove the directory and all of its content<br>
-f // -force<br>

* // wildcard, all files with the specified file extension<br>

ar // archive<br>
-r // replace: replace or add files in the archive. If the archive doesn't exist, then create one.<br>
-c // create: create the archive, if it doesn't exist. Seems redundant with the -r, but could suppress some error warnings.<br>



### About **markdone language**
//.md：markdone language, which is a markup language commonly used to format README files.<br>
//file extensions: 1. A declaration to the operating system (OS) and to applications about how the file should be interpreted and handled.<br>
                   2. Changing it won't lead to changes in the content.<br>
                   3. Some file extensions are compatible, so even if you change them, you can still open the file with the same editor. For example, .md and .txt are both for plain text f                            files, so you can open both of them with a text editor.<br>

Headers: 1. # for H1(Be aware of the space after #); # for H2 etc...  <br>
         2. Headers can have up to six levels.<br>
new paragraph: space and double enter<br>
new line: double space and enter<br>
#text: Headers; # for H1; ## for H2; ### for H3.<br>
*text*/_text_: Be italic.<br>
**text**/__text__: Be bold.<br>
***text***:Be both italic and bold.<br>
~text~: Strikethrough.<br>
***/___/- - - between two paragraphs: divider.<br>
