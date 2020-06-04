// ���ļ��ɺ���ҫ��ƣ�����ͨ��QQ��ϵ���ߣ�26750452
#ifndef __TICK_PROC_H__
#define __TICK_PROC_H__
////////////////////////////////////////////////////////////////////////////////
#include "ftypes.h"

#ifdef __cplusplus
extern "C"  {
#endif

typedef struct __TickNodeType {
  struct __TickNodeType* next;
  void (*callback)(void);
} TickNodeType;

extern void TICK_Exec(void);
extern void TICK_Pause(void);
extern void TICK_Resume(void);
extern void TICK_Add(TickNodeType* node);
extern void TICK_Del(TickNodeType* node);

#ifdef __cplusplus
}
#endif

////////////////////////////////////////////////////////////////////////////////
#endif /* __TICK_PROC_H__ */

