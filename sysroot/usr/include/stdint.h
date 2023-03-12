# ifndef _STDINT_H
# define _STDINT_H       1

# include <wordsize.h>

/* Exact integral types. */

/* Signed */

# ifndef __int8_t_defined
# define __int8_defined
typedef signed char     int8_t;
typedef short int       int16_t;
typedef int             int32_t;

# if __WORDSIZE == 64
typedef long int        int64_t
# else
typedef long long       int int64_t;
# endif
# endif

/* Unsigned */
# ifndef __uint32_t_defined
# define __uint32_t_defined
typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
typedef unsigned int            uint32_t;

# if __WORDSIZE == 64
typedef unsigned long int       uint64_t;
# else
typedef unsigned long long int  uint64_t;
# endif
# endif

/* Least integral types */
/* Signed */
# ifndef __int_least32_t_defined
# define __int_least32_t_defined

typedef signed char     int_least8_t;
typedef short int       int_least16_t;
typedef int             int_least32_t;

# if __WORDSIZE == 64
typedef long int        int_least64_t;
# else
typedef long long int   int_least64_t;
# endif
# endif


/* Unsigned */
# ifndef __uint_least32_defined
# define __uint_least32_defined
typedef unsigned char           uint_least8_t;
typedef unsigned short int      uint_least16_t;
typedef unsigned int            uint_least32_t;

# if __WORDSIZE == 64
typedef unsigned long int        uint_least64_t;
# else
typedef unsigned long long int   uint_least64_t;
# endif
# endif

/* Fast types */

/* Signed */

# ifndef __int_fast32_t_defined
# define __int_fast32_t_defined

typedef signed char     int_fast8_t;

# if __WORDSIZE == 64
typedef long int        int_fast16_t;
typedef long int        int_fast32_t;
typedef long int        int_fast64_t;

# else
typedef int     int_fast16_t;
typedef int     int_fast32_t;
typedef long long int     int_fast64_t;
# endif
# endif



/* Fast types */

/* Unsigned */

# ifndef __uint_fast32_t_defined
# define __uint_fast32_t_defined

typedef unsigned char   uint_fast8_t;

# if __WORDSIZE == 64
typedef unsigned long int       uint_fast16_t;
typedef unsigned long int       uint_fast32_t;
typedef unsigned long int       uint_fast64_t;

# else
typedef unsigned int                    uint_fast16_t;
typedef unsigned int                    uint_fast32_t;
typedef unsigned long long int          uint_fast64_t;
# endif
# endif


/* Pointers */
# ifndef __intptr_t_defined
# define __intptr_t_defined

# if __WORDSIZE == 64
typedef long int                intptr_t;
typedef unsigned long int       uintptr_t;
# else
typedef int             intptr_t;
typedef unsigned int    uintptr_t;
# endif
# endif

/* Greatest-width integer types */
# ifndef __int_greatest_defined
# define __int_greatest_defined
# if __WORDSIZE == 64
typedef long int                 intmax_t;
typedef unsigned long int        uintmax_t;
# else
typedef long long int                 intmax_t;
typedef unsigned long long int        uintmax_t;
# endif
# endif

# endif /* stdint.h */
