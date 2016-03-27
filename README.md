# BrainFuck_WithOOP
-sammary
brainfuck interpreter with object oriented programming for the beginner to train Object Oriented Programming(OOP).
you can learn the strategy and interpreter, abstract-factory, bridge, etc...
these source codes was written as the sample for learning OOP, very simple cases.

-document
if you want the document, please generate with doxygen, thess source codes has the doxygen comment.

-basic structure
ICommandFactory<T>:
brainfuck interpreter command factory. override the MakeCommand, and register into BrainFuckInterpreterFactory object.

ICommand<T>:
brainfuck interpreter command. overriding the Execute method, and creating ICommandFactory<T> to make ICommand<T> object, register into BrainFuckInterpreterFactory object.

BrainFuckInterpreterFactory<T>:
this factory can be registered command factory with brainfuck 1-byte source code.

-how to use
use as executable:
compiling these source codes with c++ compiler, generate the executable read the source codes from standard input and execute brainfuck.
=for example in linux of fedora. output the character of '$'(Dollar mark)
1. g++ ./main.cpp -o brainfuck -O3
2. ./brainfuck
3. ++[>++[>+++[>+++<-]<-]<-]>>>.
4. $

use as library:
these source codes is consist of c++ template generics classes in header. just you include these the header, you can use interpreter, parser, context.
