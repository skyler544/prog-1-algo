#ifndef SYSMACRO_H_
#define SYSMACRO_H_

#ifdef WINDOWS
#define clear() system("CLS")
#else
#define clear() system("clear")
#endif

#endif // SYSMACRO_H_
