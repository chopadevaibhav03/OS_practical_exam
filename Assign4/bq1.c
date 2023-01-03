#include <stdio.h>

int search(int key, int frames[], int frame_occupied)
{
    for (int i = 0; i < frame_occupied; i++)
        if (frames[i] == key)
            return 1;
    return 0;
}
void printFrames(int item, int frames[], int frame_occupied, int no_of_frames)
{

    printf("\n%d \t\t", item);

    for (int i = 0; i < no_of_frames; i++)
    {
        if (i < frame_occupied)
            printf("%d \t\t", frames[i]);
        else
            printf("- \t\t");
    }
}
int predict(int rstr[], int frames[], int pages, int index, int frame_occupied)
{
    int result = -1, farthest = index;
    for (int i = 0; i < frame_occupied; i++)
    {
        int j;
        for (j = index; j < pages; j++)
        {
            if (frames[i] == rstr[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == pages)
            return i;
    }
    return (result == -1) ? 0 : result;
}

void optimalPage(int rstr[], int pages, int frames[], int no_of_frames)
{
    int frame_occupied = 0;
    int pf = 0;
    for (int i = 0; i < pages; i++)
    {
        if (search(rstr[i], frames, frame_occupied))
        {
            pf++;
            printFrames(rstr[i], frames, frame_occupied, no_of_frames);
            continue;
        }
        if (frame_occupied < no_of_frames)
        {
            frames[frame_occupied] = rstr[i];
            frame_occupied++;
            printFrames(rstr[i], frames, frame_occupied, no_of_frames);
        }
        else
        {
            int pos = predict(rstr, frames, pages, i + 1, frame_occupied);
            frames[pos] = rstr[i];
            printFrames(rstr[i], frames, frame_occupied, no_of_frames);
        }
    }
    printf("\n\nPage Faults: %d\n\n", pages - pf);
}

int main()
{
    int rstr[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8}, pages = 16, no_of_frames, frames[10];

    printf("Enter no of frames: ");
    scanf("%d", &no_of_frames);
    printf("Str\t\t");
    for (int i = 1; i <= no_of_frames; i++)
    {
        printf("F%d\t\t",i);
    }
    printf("\n");


    optimalPage(rstr, pages, frames, no_of_frames);
    return 0;
}