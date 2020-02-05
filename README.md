
  stdexts

This is library of functionality that I found myself repeatedly wanting, but not finding by default.
I always considered this an extension to the C standard library, hence std exts.

It includes:

 * Singleton pattern base class
 * Non-copyable patter base class
 * Instance counter base class (keeps count of number of inherited objects of that templated type)
 * Secure Auto and Shared pointer implementations
 * An array of string functions for c-strings
 * An exception class can includes hash-defines to track:
	- Where it was produced
	- Every point it is caught and re-thrown
	- The file name and line number that caused the issue
	- Basically creating a internal stack-dump
 * Some single and double linked-list types and a fifo, and a triplet struct (std::pair+1)
 * Some other random miscellaneous functions...

Sorry there is no formal documentation as yet, I was young and naive when I wrote this...
No active development since 2015.

