#ifndef TM_H
#define TM_H 1

#  include <stdio.h>
#  include <vanilla.h>

#  define MAIN(argc, argv)              int main (int argc, char** argv)
#  define MAIN_RETURN(val)              return val

#  define GOTO_SIM()                    /* nothing */
#  define GOTO_REAL()                   /* nothing */
#  define IS_IN_SIM()                   (0)

#  define SIM_GET_NUM_CPU(var)          /* nothing */

#  define TM_PRINTF                     printf
#  define TM_PRINT0                     printf
#  define TM_PRINT1                     printf
#  define TM_PRINT2                     printf
#  define TM_PRINT3                     printf

#  define P_MEMORY_STARTUP(numThread)   /* nothing */
#  define P_MEMORY_SHUTDOWN()           /* nothing */


#  include <string.h>
#  include <stm.h>
#  include "thread.h"

#    define TM_ARG                        vtm_arg
#    define TM_ARG_ALONE                  vtm_arg_alone
#    define TM_ARGDECL                    vtm_arg_decl
#    define TM_ARGDECL_ALONE              vtm_arg_decl_alone
#    define TM_CALLABLE                   /* nothing */

#      define TM_STARTUP(numThread)     vtm_start_stm(numThread)
#      define TM_SHUTDOWN()             vm_exit_stm()

#      define TM_THREAD_ENTER()         vtm_thread_init()
#      define TM_THREAD_EXIT()          vtm_thread_finish()

#      define P_MALLOC(size)            vtm_p_malloc(size)
#      define P_FREE(ptr)               vtm_p_free(ptr)
#      define TM_MALLOC(size)           vtm_stm_malloc(size)
#      define TM_FREE(ptr)              vtm_stm_free(ptr)

#    define TM_START(ro)                vtm_start(NULL, ro)
#    define TM_BEGIN()                  TM_START(0)
#    define TM_BEGIN_RO()               TM_START(1)
#    define TM_END()                    vtm_commit(NULL)

#    define TM_RESTART()                vtm_restart(NULL)

#    define TM_EARLY_RELEASE(var)       /* nothing */

#  define TM_SHARED_READ(var)           vtm_read(NULL, var)
#  define TM_SHARED_READ_P(var)         vtm_read_pointer(NULL, var)
#  define TM_SHARED_READ_F(var)         vtm_read_float(NULL, var)

#  define TM_SHARED_WRITE(var, val)     vtm_write(NULL, var, val)
#  define TM_SHARED_WRITE_P(var, val)   vtm_write_pointer(NULL, var, val)
#  define TM_SHARED_WRITE_F(var, val)   vtm_write_float(NULL, var, val)

#  define TM_LOCAL_WRITE(var, val)      ({var = val; var;})
#  define TM_LOCAL_WRITE_P(var, val)    ({var = val; var;})
#  define TM_LOCAL_WRITE_D(var, val)    ({var = val; var;})

#endif /* TM_H */