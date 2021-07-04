#ifndef VANILLA_SWISS_H
#define VANILLA_SWISS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <string.h>

    
#define vtm_start_stm(numThread)    wlpdstm_global_init()
#define vm_exit_stm()               wlpdstm_global_shutdown()
    
    
    

#define vtm_thread_init(vtm)         wlpdstm_thread_init(); \
                                     tx_desc *tx = wlpdstm_get_tx_desc(); \
                                     wlpdstm_start_thread_profiling_desc(tx)
                                     
#define vtm_thread_finish(vtm)       wlpdstm_end_thread_profiling_desc(tx); \
                                     wlpdstm_thread_shutdown()

#define vtm_start(dataSet, ro)      BEGIN_TRANSACTION_DESC
#define vtm_commit( dataSet )       END_TRANSACTION
#define vtm_restart( dataSet )      wlpdstm_restart_tx_desc(tx)

#define vtm_read( dataSet, addr )           wlpdstm_read_word_desc(tx, (Word *)(&addr))
#define vtm_read_pointer( dataSet, addr )   (void *)wlpdstm_read_word_desc(tx, (Word *)(&addr))
#define vtm_read_float( dataSet, addr )     wlpdstm_read_double_desc(tx, (&addr))
    
#define vtm_write( dataSet, addr, data )            wlpdstm_write_word_desc(tx, (Word *)(&addr), (Word)(data))
#define vtm_write_pointer( dataSet, addr, data )    wlpdstm_write_word_desc(tx, (Word *)(&addr), (Word)(data))
#define vtm_write_float( dataSet, addr, data )      wlpdstm_write_double_desc(tx, (&addr), (data))
    
    
//mallocs
#define vtm_p_malloc(size)            wlpdstm_s_malloc(size)
#define vtm_p_free(ptr)               wlpdstm_s_free(ptr)
#define vtm_stm_malloc(size)          wlpdstm_tx_malloc_desc(tx, size)
#define vtm_stm_free(ptr)             wlpdstm_tx_free_desc(tx, ptr, sizeof(*ptr))
    
//arguments
#define vtm_arg                      tx,
#define vtm_arg_alone                tx
#define vtm_arg_decl                 tx_desc* tx,
#define vtm_arg_decl_alone           tx_desc* tx
    

#ifdef __cplusplus
}
#endif

#endif /* VANILLA_SWISS_H */

