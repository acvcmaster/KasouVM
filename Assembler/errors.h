#ifndef ERRORS
#define ERRORS

// Error messages

#define INSUFFICIENT_ARGS "kasm : no input files.\n"
#define ARGUMENT_EXPECTED "error : expected argument after '%s'.\n"
#define INVALID_ARGUMENT "error : invalid option '%s'.%s\n"
#define INVALID_ARGUMENT_CONT " Type --h for help."
#define HELP_MESSAGE "Syntax : kasm <files> <options> \nValid command-line options are :\n\n\t--h : Displays this message.\n\t-o <file_name> : Specifies output file name.\n\n\n"
#define UNEXPECTED_ARGUMENT "error : this option does not expect an argument. "
#define UNEXPECTED_ARGUMENT_CONT "Try writing --option instead of -option.\n"
#define EXPECTED_ARGUMENT "error : this option expects an argument. Try writing -option instead of --option.\n"
#define INVALID_BUFFER_SIZE "error : invalid buffer size. The specified buffer size must be a non-negative integer.\n"
#define COULD_NOT_OPEN_FILE "fail.\nerror : could not open file '%s'. "
#define COULD_NOT_OPEN_FILE_OTHER "Make sure it exists and is accessible.\n"
#define OPENING_FILE "Trying to open file '%s'.. "
#define W_NON_STANDARD_BUFFER_SIZE "warning: Buffer size set to a non-standard value (%d bytes). Compilation will fail if it's too small. (--no_warnings to suppress)\n\n"
#define BUFFER_OVERFLOW_ERROR "The specificed buffer size is too small to contain the file. Try with a larger size (default is %d, -b <size> to change).\n"

#endif