#ifndef VANILLA_TINY_H
#define VANILLA_TINY_H

#ifdef __cplusplus
extern "C" {
#endif
    
//Imports da tiny:
#include <mod_mem.h>
#include <mod_stats.h>
#include <wrappers.h>
    

#define vtm_start_stm(numThread)     if (sizeof(long) != sizeof(void *)) { \
                                        fprintf(stderr, "Error: unsupported long and pointer sizes\n"); \
                                          exit(1); \
                                   } \
                                        stm_init(); \
                                        mod_mem_init(0); \
                                        if (getenv("STM_STATS") != NULL) { \
                                          mod_stats_init(); \
                                   }
#define vm_exit_stm()             if (getenv("STM_STATS") != NULL) { \
                                          unsigned long u; \
                                          if (stm_get_global_stats("global_nb_commits", &u) != 0) \
                                            printf("#commits    : %lu\n", u); \
                                          if (stm_get_global_stats("global_nb_aborts", &u) != 0) \
                                            printf("#aborts     : %lu\n", u); \
                                          if (stm_get_global_stats("global_max_retries", &u) != 0) \
                                            printf("Max retries : %lu\n", u); \
                                    } \
                                    stm_exit()
    
    
    

#define vtm_thread_init(vtm)         (stm_init_thread())
#define vtm_thread_finish(vtm)       (stm_exit_thread())

#define vtm_start(dataSet, ro) {   \
            stm_tx_attr_t _a = {{.read_only = ro}}; \
            sigjmp_buf *_checkPoint = stm_start(_a); \
            if (_checkPoint != 0) \
               sigsetjmp(*_checkPoint, 0); \
        }
#define vtm_commit( dataSet )       (stm_commit())
#define vtm_restart( dataSet )      (stm_abort(0))

#define vtm_read( dataSet, addr )           stm_load((volatile stm_word_t *)(void *)&(addr))
#define vtm_read_pointer( dataSet, addr )   stm_load_ptr((volatile void **)(void *)&(addr))
#define vtm_read_float( dataSet, addr )     stm_load_float((volatile float *)(void *)&(addr))
    
#define vtm_write( dataSet, addr, data )            stm_store((volatile stm_word_t *)(void *)&(addr), (stm_word_t)data)
#define vtm_write_pointer( dataSet, addr, data )    stm_store_ptr((volatile void **)(void *)&(addr), data)
#define vtm_write_float( dataSet, addr, data )      stm_store_float((volatile float *)(void *)&(addr), data)
    
    
//mallocs
#define vtm_p_malloc(size)            malloc(size)
#define vtm_p_free(ptr)               free(ptr)
#define vtm_stm_malloc(size)          stm_malloc(size)
#define vtm_stm_free(ptr)             stm_free(ptr, sizeof(stm_word_t))
    
//arguments
#define vtm_arg                      /* nothing */
#define vtm_arg_alone                /* nothing */
#define vtm_arg_decl                 /* nothing */
#define vtm_arg_decl_alone           /* nothing */
    


#ifdef __cplusplus
}
#endif

#endif /* VANILLA_TINY_H */

