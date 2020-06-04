// ���ļ��ɺ���ҫ��ƣ�����ͨ��QQ��ϵ���ߣ�26750452
#include "tickproc.h"
#include "target.h"

static TickNodeType* pList = 0;

////////////////////////////////////////////////////////////////////////////////
//|          |
//| �������� |: TICK_Exec
//| �������� |: ִ�б���
//|          |:
//| �����б� |:
//|          |:
//| ��    �� |:
//|          |:
//| ��ע��Ϣ |: ͨ����tick�ж��ڵ���
//|          |:
////////////////////////////////////////////////////////////////////////////////
void TICK_Exec(void)
{
  TickNodeType* node;
  void (*pf)(void);
  CPU_SR_DECL;

  CPU_ENTER_CRITICAL();
  node = pList;
  while (node) {
    pf = node->callback;
    if (pf) {
      node = node->next;
      CPU_EXIT_CRITICAL();
      (*pf)();
      CPU_ENTER_CRITICAL();
    } else {
      node = node->next;
    }
  }
  CPU_EXIT_CRITICAL();
}

////////////////////////////////////////////////////////////////////////////////
//|          |
//| �������� |: TICK_Add
//| �������� |: ��ӽڵ�
//|          |:
//| �����б� |:
//|          |:
//| ��    �� |:
//|          |:
//| ��ע��Ϣ |: ǧ�����ظ����ͬһ���ڵ㣡
//|          |:
////////////////////////////////////////////////////////////////////////////////
void TICK_Add(TickNodeType* node)
{
  CPU_SR_DECL;

  CPU_ENTER_CRITICAL();
  node->next = pList;
  pList = node;
  CPU_EXIT_CRITICAL();
}

////////////////////////////////////////////////////////////////////////////////
//|          |
//| �������� |: TICK_Del
//| �������� |: ɾ���ڵ�
//|          |:
//| �����б� |:
//|          |:
//| ��    �� |:
//|          |:
//| ��ע��Ϣ |:
//|          |:
////////////////////////////////////////////////////////////////////////////////
void TICK_Del(TickNodeType* node)
{
  TickNodeType* cur, *pre;
  CPU_SR_DECL;

  pre = NULL;
  CPU_ENTER_CRITICAL();
  cur = pList;
  while (cur) {
    if (cur == node) {
      if (pre) {
        pre->next = cur->next;
      } else {
        pList = cur->next;
      }
      cur->next = NULL;
      break;
    }
    pre = cur;
    cur = cur->next;
  }
  CPU_EXIT_CRITICAL();
}

////////////////////////////////////////////////////////////////////////////////

