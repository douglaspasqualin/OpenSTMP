#ifndef VANILLA_H
#define VANILLA_H

#ifdef __cplusplus
extern "C" {
#endif

#define vtm_thread_init(vtm)         (stm_init_thread())
#define vtm_thread_finish(vtm)       (stm_exit_thread())

#define vtm_start(dataSet, ro) {   \
            stm_tx_attr_t _a = {{.read_only = ro}}; \
            sigjmp_buf *_checkPoint = stm_start(_a); \
            if (_checkPoint != 0) \
               sigsetjmp(*_checkPoint, 0); \
        }
#define vtm_commit( dataSet )       (stm_commit())

#define vtm_read( dataSet, addr )           stm_load((volatile stm_word_t *)(void *)&(addr))
#define vtm_read_pointer( dataSet, addr )   stm_load_ptr((volatile void **)(void *)&(addr))
#define vtm_read_float( dataSet, addr )     stm_load_float((volatile float *)(void *)&(addr))
    
#define vtm_write( dataSet, addr, data )            stm_store((volatile stm_word_t *)(void *)&(addr), (stm_word_t)data)
#define vtm_write_pointer( dataSet, addr, data )    stm_store_ptr((volatile void **)(void *)&(addr), data)
#define vtm_write_float( dataSet, addr, data )      stm_store_float((volatile float *)(void *)&(addr), data)


#ifdef __cplusplus
}
#endif

#endif /* VANILLA_H */

