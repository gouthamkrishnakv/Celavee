/* main.c
 *
 * Copyright 2022 Goutham Krishna K V
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name(s) of the above copyright
 * holders shall not be used in advertising or otherwise to promote the sale,
 * use or other dealings in this Software without prior written
 * authorization.
 */

/*
 * PROBLEM: Solve the producer-consumer problem here.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>


int c = 0;
bool done = false;


void*
producer(void* unused)
{
  for(int i = 0; i < 500; i++)
  {
    /* produce something */
    /* and add it to the list */
    c++;
  }
  done = true;
  return NULL;
}

void*
consumer(void* unused)
{
  while (!done)
  {
    while (c > 0)
    {
      /* remove something from list */
      c--;
    }
  }
  return NULL;
}

int main ()
{
  pthread_t prod, con;

  pthread_create (&prod, NULL, producer, NULL);
  pthread_create (&con, NULL, consumer, NULL);

  void* unused = NULL;
  pthread_join (prod, &unused);
  pthread_join (con, &unused);

  printf ("NET: %d\n", c);

  return 0;
}
