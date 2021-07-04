#ifndef VANILLA_H
#define VANILLA_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(VANILLA_TINY)
    #include <vanilla-tiny.h>
#elif defined(VANILLA_SWISS)
    #include <vanilla-swiss.h>
#endif    
    
#ifdef __cplusplus
}
#endif

#endif /* VANILLA_H */

