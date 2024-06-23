var inputs = Console.ReadLine()!.Split();
string A = inputs[0];
string B = inputs[1];

int ARowNumber = 0;
int BColumnNumber = 0;

for (int i = 0; i < A.Length; ++i)
{
    for (int j = 0; j < B.Length; ++j)
    {
        if (A[i] == B[j])
        {
            ARowNumber = j;
            BColumnNumber = i;
            goto NEXT;
        }
    }
}

NEXT:

for (int i = 0; i < B.Length; ++i)
{
    for (int j = 0; j < A.Length; ++j)
    {
        if (i == ARowNumber)
        {
            Console.Write(A[j]);
        }
        else if (j == BColumnNumber)
        {
            Console.Write(B[i]);
        }
        else
        {
            Console.Write('.');
        }
    }
    Console.WriteLine();
}
