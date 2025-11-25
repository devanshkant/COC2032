ℹ️ About the Header Files in This Repository

Some of the files in this repo are .h header files that are written in a general, reusable way. (I created them as part of learning how to write header files properly and how include guards work.)

If you’re new to header files or find the syntax confusing, here are a few simple points:

👉 Understanding the Structure

If the top part of the header (#ifndef, #define, #endif) looks overwhelming, just skip those lines while reading.
Everything after #define is simply normal C++ code — classes, functions, templates, etc.
👉 How to Use a Header File

    To use any header file inside a .cpp or another .h file, simply write:
        #include "filename.h"

This copies the content of the header into your file before compilation.
In C++, a header file (.h or .hpp) is used to store declarations of classes, functions, templates, and constants so that they can be reused across multiple .cpp files. 
Instead of rewriting the same code again and again, we simply include the header wherever needed. 
The #include directive at the top of a file tells the preprocessor (a stage that runs before actual compilation) to copy the entire content of the specified header file into the current source file. Preprocessor commands like #ifndef, #define, and #endif create what is called an include guard, which prevents the header from being included more than once in the same compilation unit — avoiding duplicate definition errors.
