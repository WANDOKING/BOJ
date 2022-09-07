#include <iostream>
#include <cstdlib>

struct Meeting
{
    int startTime;
    int endTime;
};

int compare(const void* a, const void* b)
{
    Meeting* meeting1 = (Meeting*)a;
    Meeting* meeting2 = (Meeting*)b;

    if (meeting1->endTime == meeting2->endTime)
    {
        if (meeting1->startTime == meeting2->startTime)
        {
            return 0;
        }
        else if (meeting1->startTime > meeting2->startTime)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (meeting1->endTime > meeting2->endTime)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Meeting meetings[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &meetings[i].startTime, &meetings[i].endTime);
    }

    qsort(meetings, N, sizeof(Meeting), compare);

    int time = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (meetings[i].startTime >= time)
        {
            count++;
            time = meetings[i].endTime;
        }
    }

    printf("%d", count);
}
