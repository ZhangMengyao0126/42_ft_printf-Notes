# ft_printf
## The **objective** of this project

## The **solution** of this project

## Useful Knowledge
### About variadic variable

### About Makefile
#### Complication Process
1. Preprocess.  
The compiler will process the preprocessor directives, such as #include and #define. After that, the original source file is expanded with all the headers and macro definitions. This means that the preprocessor will replace the directives with their corresponding content.
2. Compilation
The preprocessed code is then translated into assembly code, which acts as an intermediary between syntax code and machine code. Notice that syntax code cannot be directly transferred into machine code.
3. Assembly
The assembly code will be converted into machine code by the assembler, resulting in a binary **object** file(.o). This file contains the machine code and the related metadata, such as the symbol table.
4. Linking
The linker will combine multiple object files and libraries to produce the final executable file (.out/.exe).

#### What is Makefile
1.Makefile is a build automation tool. It defines a set of rules and dependencies that dictate how to compile and link the program.
2.Makefile will check the timestamps of all the targets and the dependencies to make sure that the output is the newest version. With Makefile, we don't have to recompile all the programs when there are changes in the original code.

#### Makefile syntax
target: dependencies // target is created from dependencies
(tab) the command for using dependencies to produce the target

$(variable's name) // reference a defined variable
$(variable's name:.c=.o) // references a defined variable, but replaces all '.c' with '.o'"
$<// reference the first dependency
$^// reference all the dependencies
$@// reference the target

%// same name, eg. %.o:%.c

OBJS // objects
CC // c compiler
RM // rm -f（default value）

gcc // c compiler
-o // specify the name of the output file(the default name should be a.out/a.exe)
-Wall -Wextra -Werror // warning messages flags, warn all, extra warnings, warnings as errors

rm // remove
-r // -recursive, remove the directory and all of its content
-f // -force

* // wildcard, all files with the specified file extension

### About **markdone language**
//.md：1.markdone language, which is a markup language commonly used to format README files.
//file extensions: 1.A declaration to the operating system (OS) and to applications about how the file should be interpreted and handled.
///////////////////2.Changing it won't lead to changes in the content.
///////////////////3.Some file extensions are compatible, so even if you change them, you can still open the file with the same editor. For example, .md and .txt are both for plain text files, so you can open both of them with a text editor.

Headers: 1. # for H1(Be aware of the space after #); # for H2 etc...  
         2. Headers can have up to six levels.
new paragraph: space and double enter
new line: double space and enter
#text: Headers; # for H1; ## for H2; ### for H3.
*text*/_text_: Be italic.
**text**/__text__: Be bold.
***text***:Be both italic and bold.
~text~: Strikethrough.
***/___/- - - between two paragraphs: divider.