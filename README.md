# BrainFuck_WithOOP
-thank you for cloning<br>
i hope the person cloning this in 16 april 2016 grow more with OOP !.
<br><br>
-sammary<br>
brainfuck interpreter with object oriented programming for the beginner to train Object Oriented Programming(OOP).<br>
you can learn the strategy and interpreter, abstract-factory, bridge, etc...<br>
these source codes were written as the sample for learning OOP, very simple cases.<br>
<br>
-document<br>
if you want the document, please generate with doxygen, these source codes have the doxygen comments.<br>
<br>
-basic structure<br>
ICommandFactory<T>:<br>
brainfuck interpreter command factory. override the MakeCommand, and register into BrainFuckInterpreterFactory object.<br>
<br>
ICommand<T>:<br>
brainfuck interpreter command. overriding the Execute method, and creating ICommandFactory<T> to make ICommand<T> object, register into BrainFuckInterpreterFactory object.<br>
<br>
BrainFuckInterpreterFactory<T>:<br>
this factory can be registered command factory with brainfuck 1-byte source code.<br>
<br>
-how to use<br>
use as executable:<br>
compiling these source codes with c++ compiler, generate the executable reads the source codes from standard input and execute brainfuck.<br>
=for example in linux of fedora. output the character of '$'(Dollar mark)<br>
1. g++ ./main.cpp -o brainfuck -O3<br>
2. ./brainfuck<br>
3. ++[>++[>+++[>+++<-]<-]<-]>>>.<br>
4. $<br>
<br>
use as library:<br>
these source codes is consist of c++ template generics classes in headers. just you include these headers, you can use interpreter, parser, context.<br>
<br>
-note<br>
we should write the exception by chain-of-responsibility, and print out the bug stack-traces.<br>
<br>
-by<br>
n. ryouta
