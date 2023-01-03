#include <stdio.h>
int main()
{
  int rstring[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
  int pf = 0, frames, m, n, s, pages = 12;
  printf("\nFIFO Page Replacement Algorithm\n\n");

  printf("Enter no of frames: ");
  scanf("%d", &frames);
  for (int i = 1; i <= frames; i++)
  {
    printf("F%d\t", i);
  }

  int temp[frames];

  for (m = 0; m < frames; m++)
  {
    temp[m] = -1;
  }
  for (m = 0; m < pages; m++)
  {
    s = 0;
    for (n = 0; n < frames; n++)
    {
      if (rstring[m] == temp[n])
      {
        s++;
        pf--;
      }
    }
    pf++;
    if ((pf <= frames) && (s == 0))
    {
      temp[m] = rstring[m];
    }
    else if (s == 0)
    {
      temp[(pf - 1) % frames] = rstring[m];
    }
    printf("\n");
    for (n = 0; n < frames; n++)
    {
      if (temp[n] != -1)
        printf("%d\t", temp[n]);
      else
        printf("-\t");
    }
  }

  printf("\n\n Total Page Faults = %d\n\n", pf);
}
