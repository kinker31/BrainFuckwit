# Brain Fuckwit: A Silly Extension to a Silly Esolang
Normal Brainfuck's cool and all, but what if we could extend it?

This question did *not* need to be answered at all, but yet I answered it anyways with this little program. Comes with the ability to shift cells into adjacent cells, generating random values for cells, and most importantly, a 1-value stack for doing advanced crap with!

Written entirely in C because I like C, okay?

## How to use it
To understand how to use the language itself, take a look-see at [the specification](specification.txt).

Otherwise, running the program by itself will lead you to an interactive version with it's own helpscreen, and running it with `-c filename.bfw` or `-i filename.bfw` will automatically load `filename.bfw` into the program and interpret/compile it.

Saved Brain Fuckwit scripts cannot have comments by themselves, but you can write a .txt file with the script's name to describe what it's doing, and what it's supposed to output.

## Compilation
`build.sh` should be able to handle the whole process if you're on Linux.

If you're on Windows, use MinGW to run `build.sh`. Or the WSL, whichever works, really.