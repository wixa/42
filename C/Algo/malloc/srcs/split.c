
#include <unistd.h>
#include "malloc.h"

void		split_mid(t_header *tmp, int total_size)
{
  t_header	*newBlock;
  int		offset;

  offset = sizeof(*tmp) + tmp->size;
  newBlock = (t_header *)((int)tmp + offset);
  newBlock->magic = FREE_MAGIC;
  newBlock->size = total_size - offset - sizeof(*newBlock);
  newBlock->next = tmp->next;
  tmp->next = newBlock;
  verifyFusion(newBlock);
}

void		split_end(t_header *tmp)
{
  t_header	*newBlock;
  int		offset;

  offset = sizeof(*tmp) + tmp->size;
  newBlock = (t_header *)((int)tmp + offset);
  newBlock->size = MIN_MALLOC - offset - sizeof(*newBlock);
  addToFreeList(newBlock, 0);
}
